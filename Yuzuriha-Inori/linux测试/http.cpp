#include <stdarg.h>  
#include <errno.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <string.h>  
#include <time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <dirent.h>  
#include <errno.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <resolv.h>  
#include <arpa/inet.h>  
#include <stdlib.h>  
#include <signal.h>  
#include <getopt.h>  
  
#define DEFAULTIP "10.2.3.51"  
#define DEFAULTPORT "80"  
#define DEFAULTBACK "10"  
#define DEFAULTDIR "/home/temp/http_server"  
#define DEFAULTLOG "/home/temp/http_server/das-server.log"  
  
void prterrmsg(char *msg);  
#define prterrmsg(msg)        { perror(msg); abort(); }  
void wrterrmsg(char *msg);  
#define wrterrmsg(msg)        { fputs(msg, logfp); fputs(strerror(errno), logfp);fflush(logfp); abort(); }  
  
void prtinfomsg(char *msg);  
#define prtinfomsg(msg)        { fputs(msg, stdout);  }  
void wrtinfomsg(char *msg);  
#define wrtinfomsg(msg)        {  fputs(msg, logfp); fflush(logfp);}  
  
#define MAXBUF        1024  
  
char buffer[MAXBUF + 1];  
char *host = 0;  
char *port = 0;  
char *back = 0;  
char *dirroot = 0;  
char *logdir = 0;  
unsigned char daemon_y_n = 0;  
FILE *logfp;  
  
#define MAXPATH        150  
  
/*----------------------------------------  
*--- dir_up - 查找dirpath所指目录的上一级目录  
*----------------------------------------  
*/  
char *dir_up(char *dirpath)  
{  
    static char Path[MAXPATH];  
    int len;  
  
    strcpy(Path, dirpath);  
    len = strlen(Path);  
    if (len > 1 && Path[len - 1] == '/')  
    {  
        len--;  
    }  
    while (Path[len - 1] != '/' && len > 1)  
    {  
        len--;  
    }  
    Path[len] = 0;  
    return Path;  
}  
  
/*------------------------------------------------------  
*--- AllocateMemory - 分配空间并把d所指的内容复制  
*------------------------------------------------------  
*/  
void AllocateMemory(char **s, int l, char *d)  
{  
    *s = malloc(l + 1);  
    bzero(*s, l + 1);  
    memcpy(*s, d, l);  
}  
/************关于本文档********************************************  
*filename: das-server.c  
*purpose: 这是在Linux下用C语言写的目录访问服务器，支持目录浏览和文件下载  
  
*********************************************************************/  
/*------------------------------------------------------  
*--- GiveResponse - 把Path所指的内容发送到client_sock去  
*-------------------如果Path是一个目录，则列出目录内容  
*-------------------如果Path是一个文件，则下载文件  
*------------------------------------------------------  
*/  
void GiveResponse(FILE * client_sock, char *Path)  
{  
    struct dirent *dirent;  
    struct stat info;  
    char Filename[MAXPATH];  
    DIR *dir;  
    int fd, len, ret;  
    char *p, *realPath, *realFilename, *nport;  
  
    /* 获得实际工作目录或文件 */  
    len = strlen(dirroot) + strlen(Path) + 1;  
    realPath = malloc(len + 1);  
    bzero(realPath, len + 1);  
    sprintf(realPath, "%s/%s", dirroot, Path);  
  
    /* 获得实际工作端口 */  
    len = strlen(port) + 1;  
    nport = malloc(len + 1);  
    bzero(nport, len + 1);  
    sprintf(nport, ":%s", port);  
  
    /* 获得实际工作目录或文件的信息以判断是文件还是目录 */  
    if (stat(realPath, &info))  
    {  
        fprintf(client_sock,  
             "HTTP/1.1 200 OK\r\nServer:SONG\r\nConnection: close\r\nContent-Type:text/html; charset=UTF-8\r\n\r\n<html><head><title>%d - %s</title></head>"  
             "<body><font size=+4>Linux directory access server</font><br><hr width=\"100%%\"><br><center>"  
             "<table border cols=3 width=\"100%%\">", errno,  
             strerror(errno));  
        fprintf(client_sock,  
             "</table><font color=\"CC0000\" size=+2>Please contact the administrator consulting why appear as follows error message：\n%s %s</font></body></html>",  
             Path, strerror(errno));  
        goto out;  
    }  