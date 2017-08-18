//多线程
//serve
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <sys/socket.h>  
    #include <arpa/inet.h>  
    #include <string.h>  
    #include <signal.h>  
      
    #define DEBUG  
    #ifdef DEBUG  
    #define debug(x) printf(x)  
    #else  
    #define debug(x)  
    #endif  
      
    #define SERVER_PORT 1500  
    #define SERVER_IP "192.168.150.129"  
    #define LISTEN_NUM 10  
      
    //typedef void (*sighandler_t)(int);  
    //  
    //void sigint_handle(int sig);   //sigint信号处理函数，Ctrl + c所发送的信号  
    //void *func(void *arg);  //线程处理函数  
    //  
    //static int fd = -1;  
    //  
    //int main(int argc , char * argv[])  
    //{  
    //        int bind_ret = -1;  
    //        struct sockaddr_in sa_in = {0};  
    //        int listen_ret = -1;  
    //        int *accept_ret;  
    //        struct sockaddr_in client_sa = {0};  
    //        socklen_t client_len = 0;  
    //  
    //        pthread_t thread = -1;  
    //        int ret = -1;  
    //  
    //        sighandler_t sig_ret = (sighandler_t)-1;  
    //        sig_ret = signal(SIGINT,sigint_handle); //设置sigint信号的处理函数  
    //        if(SIG_ERR == sig_ret)  
    //        {  
    //                perror("signal");  
    //                exit(-1);  
    //        }  
    //  
    //        fd = socket(AF_INET,SOCK_STREAM,0);  //建立一个监听socket，明确了socket的类型和类别：ipv4和tcp连接  
    //        if(fd < 0)  
    //        {  
    //                perror("soket");  
    //                exit(-1);  
    //        }  
    //        printf("fd:%d\n",fd);  
    //  
    //        sa_in.sin_family = AF_INET;  
    //        sa_in.sin_port = htons(SERVER_PORT); //将端口转为网络序，赋给结构体  
    //        sa_in.sin_addr.s_addr = inet_addr(SERVER_IP);  //将点分十进制ip地址转换为二进制  
    //        bind_ret = bind(fd,(const struct sockaddr *)&sa_in,sizeof(sa_in));  //为监听描述符绑定ip和port，也被称为命名  
    //        if(bind_ret < 0)  
    //        {  
    //                perror("bind");  
    //                exit(-1);  
    //        }  
    //        debug("bind success\n");  
    //  
    //        listen_ret = listen(fd,LISTEN_NUM);  //设置socket为监听状态  
    //        if(listen_ret < 0)  
    //        {  
    //                perror("listen");  
    //                exit(-1);  
    //        }  
    //        debug("listening\n");  
    //        while(1)  //在循环中处理连接请求  
    //        {  
    //                accept_ret = (int *)malloc(sizeof(int));  //动态分配的原因：避免读写描述符被多个线程混用  
    //                *accept_ret = accept(fd,(struct sockaddr *)&client_sa,&client_len);  //从链接队列中获取建立好的socket连接  
    //                if(accept_ret < 0)  
    //                {  
    //                        perror("accept");  
    //                        exit(-1);  
    //                }  
    //                printf("accept_ret,fd for client:%d\n",*accept_ret);  
    //  
    //                ret = pthread_create(&thread,NULL,func,(void *)accept_ret);  //为连接创建线程  
    //                if(ret != 0)  
    //                {  
    //                        perror("pthread_create");  
    //                        exit(-1);  
    //                }  
    //        }  
    //  
    //        return 0;  
    //}  
    //  
    //void *func(void *fd) //线程处理函数  
    //{  
    //        int *accept_ret = (int *)fd;  
    //        char receivebuf[20] = {0};  
    //        int recv_ret = -1;  
    //  
    //        while(1)  
    //        {  
    //                recv_ret = recv(*accept_ret,receivebuf,sizeof(receivebuf),0);//接收客户端数据  
    //                if(recv_ret < 0)  
    //                {  
    //                        perror("recv");  
    //                        exit(-1);  
    //                }  
    //                }  
    //                else if(recv_ret == 0)  //连接断开  
    //                {  
    //                        if(close(*accept_ret)) //关闭读取描述符  
    //                        {  
    //                                perror("close");  
    //                                exit(-1);  
    //                        }  
    //                        printf("close:%d,exiting subthread\n",*accept_ret);  
    //                        free(accept_ret);  //释放动态分配的描述符空间  
    //                        pthread_exit(NULL);//线程返回  
    //                }  
    //                printf("%d bytes from %d,%s\n",recv_ret,*accept_ret,receivebuf);  
    //                memset(receivebuf,0,strlen(receivebuf));  
    //        }  
    //}  
    //  
    //void sigint_handle(int sig) //信号处理函数  
    //{  
    //        if(SIGINT != sig)return;  
    //        printf("\nserver termated\n");  
    //        close(fd);  
    //        exit(1);  
    //}  
///////////////////////////////////////////////////////////////////////////////
//client
//include <stdio.h>  
//#include <stdlib.h>  
//#include <sys/socket.h>  
//#include <arpa/inet.h>  
//#include <netinet/in.h>  
//#include <string.h>  
//#include <signal.h>  
//  
#define DEBUG  
#ifdef DEBUG  
#define debug(x) printf(x)  
#else  
#define debug(x)  
#endif  
  
#define SERVER_IP "192.168.150.129"  
#define SERVER_PORT 1500  
  
typedef void (*sighandler_t)(int);  
  
void sigpipe_handle(int arg); //sigpipe信号处理函数，当send或是recv在等待发送或是接收数据时发现连接断开，系统会发出该信号  
  
static int fd = -1;  
  int main(int argc,char *argv[])  
{  
        struct sockaddr_in server_sa = {0};  
        int connect_ret = -1;  
  
        int send_ret = -1;  
  
        sighandler_t sig_ret = (sighandler_t)-1;  
  
        fd = socket(AF_INET,SOCK_STREAM,0);   //建立socket连接，设置连接类型  
        if(fd < 0)  
        {  
                perror("socket");  
                exit(-1);  
        }  
        printf("fd:%d\n",fd);  
  
        sig_ret = signal(SIGPIPE,sigpipe_handle);  //为sigpipe信号绑定处理函数  
        if(SIG_ERR == sig_ret)  
        {  
                perror("signal");  
                exit(-1);  
        }  
  
        server_sa.sin_port = htons(SERVER_PORT);  
        server_sa.sin_addr.s_addr = inet_addr(SERVER_IP);  
        server_sa.sin_family = AF_INET;  
        connect_ret = connect(fd,(struct sockaddr *)&server_sa,sizeof(server_sa));  //向服务器发送连接请求  
        if(connect_ret < 0)  
        {  
                perror("connect");  
                exit(-1);  
        }  
        debug("connect done\n");  
  
        char sendbuf[20] = {0};  
        while(1)    //将用户输入的数据发送给服务器端，当输入end时，客户端退出  
        {  
                printf("input your data\n");  
                scanf("%s",sendbuf);  
                if(!strncmp(sendbuf, "end",3))  
                {  
                        debug("exiting....\n");  
                        close(fd);  
                        return 0;  
                }  
  
                send_ret = send(fd,sendbuf,strlen(sendbuf),0);  //向服务器发送信息  
                if(send_ret < 0)  
                {  
                        perror("send");  
                        exit(-1);  
                }  
                printf("data sent successfully:%d\n",send_ret);  
        }  
}  
  void sigpipe_handle(int arg)  //打印提示信息后再退出  
{  
        if(SIGPIPE == arg)  
        {  
                printf("server disconnect\n");  
                close(fd);  
                debug("exiting\n");  
                exit(1);  
        }  
}  
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////select
  /////server
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

static void usage(char* arg)
{
    printf("%s[local_ip][local_port]",arg);
}

int starup(char* ip,int port)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    int opt = 1;
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    if(bind(sock,(struct sockaddr*)&server,sizeof(server)) < 0)
    {
        perror("bind");
        exit(3);
   }

    if(listen(sock,10) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}
int rfds_array[sizeof(fd_set) * 8];
int write_array[sizeof(fd_set) * 8];

int main(int argc,char* argv[])
{
   // printf("%d\n",sizeof(fd_set));
    if(argc != 3)
    {
        usage(argv[0]);
        return 1;
    }

    int listen_sock = starup(argv[1],atoi(argv[2]));

    int nums = 8 * sizeof(fd_set);
    fd_set read_set;
    fd_set write_set;
    rfds_array[0] = listen_sock;
    write_array[0] = -1;
    int i = 1;
    for(;i < nums; ++i)
    {
        rfds_array[i] = -1;
        write_array[i] = -1;
    }

    while(1)
    {
        FD_ZERO(&write_set);
        FD_ZERO(&read_set);
        int max_fd = -1;
       // FD_SET(listen_sock,&read_set);
        for(i = 0;i < nums; ++i)
        {
            if(rfds_array[i] < 0)
                continue;

            if(max_fd < rfds_array[i])
                max_fd = rfds_array[i];

            FD_SET(rfds_array[i],&read_set);
        }

        for(i = 0;i < nums;++i)
        {
            if(write_array[i] == -1)
                continue;
            if(max_fd < write_array[i])
                max_fd = write_array[i];
            FD_SET(write_array[i],&write_set);
        }

        //struct timeval timeout;
        //timeout.tv_sec = 2;
        //timeout.tv_usec = 0;

        int ret = select(max_fd + 1,&read_set,&write_set,NULL,NULL);
        if(ret > 0)
        {
            for(i = 0; i < nums; ++i)
            {
                if(i == 0 && FD_ISSET(listen_sock,&read_set))
                {
                    struct sockaddr_in client;
                    socklen_t len = sizeof(client);
                    int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
                    if(new_sock <= 0)
                    {
                        perror("accept");
                       // continue;                        
                    }
                    else
                    {
                        int j = 1;
                        for(; j < nums; ++j)
                        {
                            if(rfds_array[j] == -1)
                                break;
                        }

                        if(j < nums)
                        {
                            rfds_array[j] = new_sock;
                        }
                        else
                        {
                            printf("fd_set is full\n");
                            close(new_sock);
                //            continue;
                        }
                        printf("new client come %s %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                        for(j = 0;j < nums;++j)
                        {
                            if(write_array[j] == -1)
                                break;
                        }

                        if(j < nums)
                            write_array[j] = new_sock;
                        else
                        {
                            printf("cannot write\n");   
                        }
                    }
                }//i == 0
                else if(i > 0 && FD_ISSET(rfds_array[i],&read_set))
                {
                    char buf[1024];
                    ssize_t s = read(rfds_array[i],buf,sizeof(buf) - 1);
                    if(s == 0)
                    {
                        printf("client is quit..\n");
                        close(rfds_array[i]);
                        int j = 0;
                        for(;j< nums; ++j)
                        {
                            if(write_array[j] == rfds_array[i])
                                break;
                        }
                        if(j < nums)
                            write_array[j] = -1;

                        rfds_array[i] = -1;

                 //       continue;
                    }
                    else if(s < 0)
                    {
                        perror("read");
                        close(rfds_array[i]);
                        rfds_array[i] = -1;
                 //       continue;
                    }
                    else
                    {
                        buf[s] = 0;
  //                      printf("%s %d:",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                        printf("%s\n",buf);
                 //       write(rfds_array[i],buf,strlen(buf));
                    }
                }//i > 0

                if(write_array[i] != -1 && FD_ISSET(write_array[i],&write_set))
                {
                    char* buf = "hello word";
                    printf("%s\n",buf);
                    write(write_array[i],buf,strlen(buf));
                }

            }//for
        }
        else if(ret == 0)
        {
            printf("nothing is ready..\n");
        }
        else
        {
            perror("select");
            return 5;
        }

    }

    return 0;
}
////////////////////////////////////////////////////
/////////////epoll
#include<errno.h>  
#include<assert.h>  
#include<string.h>  
  
static void usage(const char* proc)  
{  
    assert(proc);  
    printf("usage: %s [ip] [port]\n",proc);  
}  
  
static int set_nonblock(int fd)  
{  
    int fl = fcntl(fd,F_SETFL);  
    fcntl(fd,F_SETFL,fl|O_NONBLOCK);  
}  
  
int my_read(int fd,char* buf,int len)  
{  
    assert(buf);  
    ssize_t total = 0;  
    ssize_t s = 0;  
    while((s = read(fd,&buf[total],len - 1 - total)) > 0&&errno != EAGAIN)  
    {  
        total += s;  
    }  
  
    return total;  
}  
int start_up(char* ip,int port)  
{  
    assert(ip);  
    assert(port > 0);  
  
    int sock = socket(AF_INET,SOCK_STREAM,0);  
    if(sock < 0)  
    {  
        perror("socket");  
        exit(1);  
    }  
      
    struct sockaddr_in local;  
    local.sin_family = AF_INET;  
    local.sin_port = htons(port);  
    local.sin_addr.s_addr = inet_addr(ip);  
  
    if(bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0)  
    {  
        perror("bind");  
        exit(2);  
    }  
  
    if(listen(sock,5) < 0)  
    {  
        perror("listen");  
        exit(3);  
    }  
  
    return sock;  
}  
int main(int argc,char* argv[])  
{  
    if(argc != 3)  
    {  
        usage(argv[0]);  
        return 1;  
    }  
    int listen_sock = start_up(argv[1],atoi(argv[2]));  
    int epfd = epoll_create(256);  
    if(epfd < 0)  
    {  
        perror("epoll_create");  
        return 2;  
    }  
	    struct epoll_event ev;  
    ev.events = EPOLLIN;  
    ev.data.fd = listen_sock;  
    epoll_ctl(epfd,EPOLL_CTL_ADD,listen_sock,&ev);  
    int nums = 0;  
  
    struct epoll_event ready_events[64];  
    int len = 64;  
    int timeout = -1; 
	 while(1)  
    {  
        switch(nums = epoll_wait(epfd,ready_events,len,timeout))  
        {  
            case 0:  
                printf("timeout..");  
                break;  
            case -1:  
                perror("epoll_wait");  
                break;  
				            default:  
                {  
                    int i = 0;  
                    for(;i < nums; i++)  
                    {  
                        int fd = ready_events[i].data.fd;  
                        if(fd == listen_sock && ready_events[i].events & EPOLLIN)  
                        {  
                            struct sockaddr_in client;  
                            socklen_t len = sizeof(client);  
                            int new_fd = accept(listen_sock,(struct sockaddr*)&client,&len);  
                            if(new_fd < 0)  
                            {  
                                perror("accept");  
                                continue;  
                            }  
  
                            printf("get a new client:%s:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));  
  
                            ev.events = EPOLLIN|EPOLLET;  
                            ev.data.fd = new_fd;  
                            set_nonblock(new_fd);  
                            epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&ev);  
                        }  
						                        else  
                        {  
                            if(ready_events[i].events & EPOLLIN)  
                            {  
                                char buf[1024];  
                                ssize_t s = read(fd,buf,sizeof(buf) - 1);  
                                if(s > 0)  
                                {  
                                    buf[s] = 0;  
                                    printf("client#%s\n",buf);  
                                    ev.events = EPOLLOUT|EPOLLET;  
                                    ev.data.fd = fd;  
                                    epoll_ctl(epfd,EPOLL_CTL_MOD,fd,&ev);  
                                }  
								                                else if(s == 0)  
                                {  
                                    epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL);  
                                    close(fd);  
                                    printf("client close...");  
                                }  
								                                else  
                                {  
                                    perror("read");  
                                }  
                            } 
                            else if(ready_events[i].events & EPOLLOUT)  
                            {  
                                char buf[1024];  
                                sprintf(buf,"HTTP/1.0 200 OK\r\n\r\n<html><h2>hello</h2></html>");  
                                write(fd,buf,strlen(buf));  
                                epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL);  
                                close(fd);  
                            }  