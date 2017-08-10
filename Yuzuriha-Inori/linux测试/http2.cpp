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
  
    /*�õ�����ĵ�һ��*/  
    numchars = get_line(client, buf, sizeof(buf));  
    i = 0; j = 0;  
    /*�ѿͻ��˵����󷽷��浽 method ����*/  
    while (!ISspace(buf[j]) && (i < sizeof(method) - 1))  
    {  
        method[i] = buf[j];  
        i++; j++;  
    }  
    method[i] = '\0';  
  
    /*����Ȳ��� GET �ֲ��� POST ���޷����� */  
    if (strcasecmp(method, "GET") && strcasecmp(method, "POST"))  
    {  
        unimplemented(client);  
        return;  
    }  
  
    /* POST ��ʱ���� cgi */  
    if (strcasecmp(method, "POST") == 0)  
        cgi = 1;  
  
    /*��ȡ url ��ַ*/  
    i = 0;  
    while (ISspace(buf[j]) && (j < sizeof(buf)))  
        j++;  
    while (!ISspace(buf[j]) && (i < sizeof(url) - 1) && (j < sizeof(buf)))  
    {  
        /*���� url */  
        url[i] = buf[j];  
        i++; j++;  
    }  
    url[i] = '\0';  
  
    /*���� GET ����*/  
    if (strcasecmp(method, "GET") == 0)  
    {  
        /* ����������Ϊ url */  
        query_string = url;  
        while ((*query_string != '?') && (*query_string != '\0'))  
            query_string++;  
        /* GET �����ص㣬? ����Ϊ����*/  
        if (*query_string == '?')  
        {  
            /*���� cgi */  
            cgi = 1;  
            *query_string = '\0';  
            query_string++;  
        }  
    }  
  
    /*��ʽ�� url �� path ���飬html �ļ����� htdocs ��*/  
    sprintf(path, "htdocs%s", url);  
    /*Ĭ�����Ϊ index.html */  
    if (path[strlen(path) - 1] == '/')  
        strcat(path, "index.html");  
    /*����·���ҵ���Ӧ�ļ� */  
    if (stat(path, &st) == -1) {  
        /*������ headers ����Ϣ������*/  
        while ((numchars > 0) && strcmp("\n", buf))  /* read & discard headers */  
            numchars = get_line(client, buf, sizeof(buf));  
        /*��Ӧ�ͻ����Ҳ���*/  
        not_found(client);  
    }  
    else  
    {  
        /*����Ǹ�Ŀ¼����Ĭ��ʹ�ø�Ŀ¼�� index.html �ļ�*/  
        if ((st.st_mode & S_IFMT) == S_IFDIR)  
            strcat(path, "/index.html");  
      if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH)    )  
          cgi = 1;  
      /*���� cgi,ֱ�Ӱѷ������ļ����أ�����ִ�� cgi */  
      if (!cgi)  
          serve_file(client, path);  
      else  
          execute_cgi(client, path, method, query_string);  
    }  
  
    /*�Ͽ���ͻ��˵����ӣ�HTTP �ص㣺�����ӣ�*/  
    close(client);  
}  
/**********************************************************************/  
/* Inform the client that a request it has made has a problem. 
 * Parameters: client socket */  
/**********************************************************************/  
void bad_request(int client)  
{  
    char buf[1024];  
  
    /*��Ӧ�ͻ��˴���� HTTP ���� */  
    sprintf(buf, "HTTP/1.0 400 BAD REQUEST\r\n");  
    send(client, buf, sizeof(buf), 0);  
    sprintf(buf, "Content-type: text/html\r\n");  
    send(client, buf, sizeof(buf), 0);  
    sprintf(buf, "\r\n");  
    send(client, buf, sizeof(buf), 0);  
    sprintf(buf, "<P>Your browser sent a bad request, ");  
    send(client, buf, sizeof(buf), 0);  
    sprintf(buf, "such as a POST without a Content-Length.\r\n");  
    send(client, buf, sizeof(buf), 0);  
}  
  
/**********************************************************************/  
/* Put the entire contents of a file out on a socket.  This function 
 * is named after the UNIX "cat" command, because it might have been 
 * easier just to do something like pipe, fork, and exec("cat"). 
 * Parameters: the client socket descriptor 
 *             FILE pointer for the file to cat */  
/**********************************************************************/  
void cat(int client, FILE *resource)  
{  
    char buf[1024];  
  
    /*��ȡ�ļ��е���������д�� socket */  
    fgets(buf, sizeof(buf), resource);  
    while (!feof(resource))  
    {  
        send(client, buf, strlen(buf), 0);  
        fgets(buf, sizeof(buf), resource);  
    }  
}  
  
/**********************************************************************/  
/* Inform the client that a CGI script could not be executed. 
 * Parameter: the client socket descriptor. */  
/**********************************************************************/  
void cannot_execute(int client)  
{  
    char buf[1024];  
  
    /* ��Ӧ�ͻ��� cgi �޷�ִ��*/  
    sprintf(buf, "HTTP/1.0 500 Internal Server Error\r\n");  
    send(client, buf, strlen(buf), 0);  
    sprintf(buf, "Content-type: text/html\r\n");  
    send(client, buf, strlen(buf), 0);  
    sprintf(buf, "\r\n");  
    send(client, buf, strlen(buf), 0);  
    sprintf(buf, "<P>Error prohibited CGI execution.\r\n");  
    send(client, buf, strlen(buf), 0);  
}  
  
/**********************************************************************/  
/* Print out an error message with perror() (for system errors; based 
 * on value of errno, which indicates system call errors) and exit the 
 * program indicating an error. */  
/**********************************************************************/  