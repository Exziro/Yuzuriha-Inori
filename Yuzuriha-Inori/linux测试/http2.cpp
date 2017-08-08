/* J. David's webserver */  
/* This is a simple webserver. 
 * Created November 1999 by J. David Blackstone. 
 * CSE 4344 (Network concepts), Prof. Zeigler 
 * University of Texas at Arlington 
 */  
/* This program compiles for Sparc Solaris 2.6. 
 * To compile for Linux: 
 *  1) Comment out the #include <pthread.h> line. 
 *  2) Comment out the line that defines the variable newthread. 
 *  3) Comment out the two lines that run pthread_create(). 
 *  4) Uncomment the line that runs accept_request(). 
 *  5) Remove -lsocket from the Makefile. 
 */  
#include <stdio.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <ctype.h>  
#include <strings.h>  
#include <string.h>  
#include <sys/stat.h>  
#include <pthread.h>  
#include <sys/wait.h>  
#include <stdlib.h>  
  
#define ISspace(x) isspace((int)(x))  
  
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"  
void accept_request(int);  
void bad_request(int);  
void cat(int, FILE *);  
void cannot_execute(int);  
void error_die(const char *);  
void execute_cgi(int, const char *, const char *, const char *);  
int get_line(int, char *, int);  
void headers(int, const char *);  
void not_found(int);  
void serve_file(int, const char *);  
int startup(u_short *);  
void unimplemented(int);  
  
/**********************************************************************/  
/* A request has caused a call to accept() on the server port to 
 * return.  Process the request appropriately. 
 * Parameters: the socket connected to the client */  
/**********************************************************************/ 
void accept_request(int client)  
{  
    char buf[1024];  
    int numchars;  
    char method[255];  
    char url[255];  
    char path[512];  
    size_t i, j;  
    struct stat st;  
    int cgi = 0;      /* becomes true if server decides this is a CGI program */  
    char *query_string = NULL;  
  
    /*得到请求的第一行*/  
    numchars = get_line(client, buf, sizeof(buf));  
    i = 0; j = 0;  
    /*把客户端的请求方法存到 method 数组*/  
    while (!ISspace(buf[j]) && (i < sizeof(method) - 1))  
    {  
        method[i] = buf[j];  
        i++; j++;  
    }  
    method[i] = '\0';  
  
    /*如果既不是 GET 又不是 POST 则无法处理 */  
    if (strcasecmp(method, "GET") && strcasecmp(method, "POST"))  
    {  
        unimplemented(client);  
        return;  
    }  
  
    /* POST 的时候开启 cgi */  
    if (strcasecmp(method, "POST") == 0)  
        cgi = 1;  
  
    /*读取 url 地址*/  
    i = 0;  
    while (ISspace(buf[j]) && (j < sizeof(buf)))  
        j++;  
    while (!ISspace(buf[j]) && (i < sizeof(url) - 1) && (j < sizeof(buf)))  
    {  
        /*存下 url */  
        url[i] = buf[j];  
        i++; j++;  
    }  
    url[i] = '\0';  
  
    /*处理 GET 方法*/  
    if (strcasecmp(method, "GET") == 0)  
    {  
        /* 待处理请求为 url */  
        query_string = url;  
        while ((*query_string != '?') && (*query_string != '\0'))  
            query_string++;  
        /* GET 方法特点，? 后面为参数*/  
        if (*query_string == '?')  
        {  
            /*开启 cgi */  
            cgi = 1;  
            *query_string = '\0';  
            query_string++;  
        }  
    }  
  
    /*格式化 url 到 path 数组，html 文件都在 htdocs 中*/  
    sprintf(path, "htdocs%s", url);  
    /*默认情况为 index.html */  
    if (path[strlen(path) - 1] == '/')  
        strcat(path, "index.html");  
    /*根据路径找到对应文件 */  
    if (stat(path, &st) == -1) {  
        /*把所有 headers 的信息都丢弃*/  
        while ((numchars > 0) && strcmp("\n", buf))  /* read & discard headers */  
            numchars = get_line(client, buf, sizeof(buf));  
        /*回应客户端找不到*/  
        not_found(client);  
    }  
    else  
    {  
        /*如果是个目录，则默认使用该目录下 index.html 文件*/  
        if ((st.st_mode & S_IFMT) == S_IFDIR)  
            strcat(path, "/index.html");  
      if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH)    )  
          cgi = 1;  
      /*不是 cgi,直接把服务器文件返回，否则执行 cgi */  
      if (!cgi)  
          serve_file(client, path);  
      else  
          execute_cgi(client, path, method, query_string);  
    }  
  
    /*断开与客户端的连接（HTTP 特点：无连接）*/  
    close(client);  
}  