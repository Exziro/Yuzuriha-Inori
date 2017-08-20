#include<stdio.h>  
#include<stdlib.h>  
#include<errno.h>  
#include<string.h>  
#include<sys/types.h>  
#include<netinet/in.h>  
#include<sys/socket.h>  
#include<sys/wait.h>  
#include<unistd.h>  
#include<arpa/inet.h>  
#define MAXBUF 1024  
  
int main(int argc,char *argv[])  
{  
    int pid;  
    int sockfd,new_fd;  
    socklen_t len;  
    struct sockaddr_in my_addr,their_addr;  
    unsigned int myport,lisnum;  
    char buf[MAXBUF+1];  
    if(argv[2])  
        myport=atoi(argv[2]);  
    else  
        myport=7575;  
    if(argv[3])  
        lisnum=atoi(argv[3]);  
    else  
        lisnum=5; 