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
	    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)  
    {  
        perror("socket");  
        exit(EXIT_FAILURE);  
    }  
  
    bzero(&my_addr,sizeof(my_addr));  
    my_addr.sin_family=AF_INET;  
    my_addr.sin_port=htons(myport);  
    if(argv[1])  
        my_addr.sin_addr.s_addr=inet_addr(argv[1]);  
    else  
        my_addr.sin_addr.s_addr=INADDR_ANY;  
    if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)  
    {  
        perror("bind");  
        exit(EXIT_FAILURE);  
    }  
    if(listen(sockfd,lisnum)==-1)  
    {  
        perror("listen");  
        exit(EXIT_FAILURE);  
    }  
    printf("wait for connect!\n");  
    len=sizeof(struct sockaddr);  