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
  