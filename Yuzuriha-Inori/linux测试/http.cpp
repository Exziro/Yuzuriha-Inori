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