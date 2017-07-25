//���߳�
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
    //void sigint_handle(int sig);   //sigint�źŴ�������Ctrl + c�����͵��ź�  
    //void *func(void *arg);  //�̴߳�����  
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
    //        sig_ret = signal(SIGINT,sigint_handle); //����sigint�źŵĴ�����  
    //        if(SIG_ERR == sig_ret)  
    //        {  
    //                perror("signal");  
    //                exit(-1);  
    //        }  
    //  
    //        fd = socket(AF_INET,SOCK_STREAM,0);  //����һ������socket����ȷ��socket�����ͺ����ipv4��tcp����  
    //        if(fd < 0)  
    //        {  
    //                perror("soket");  
    //                exit(-1);  
    //        }  
    //        printf("fd:%d\n",fd);  
    //  
    //        sa_in.sin_family = AF_INET;  
    //        sa_in.sin_port = htons(SERVER_PORT); //���˿�תΪ�����򣬸����ṹ��  
    //        sa_in.sin_addr.s_addr = inet_addr(SERVER_IP);  //�����ʮ����ip��ַת��Ϊ������  
    //        bind_ret = bind(fd,(const struct sockaddr *)&sa_in,sizeof(sa_in));  //Ϊ������������ip��port��Ҳ����Ϊ����  
    //        if(bind_ret < 0)  
    //        {  
    //                perror("bind");  
    //                exit(-1);  
    //        }  
    //        debug("bind success\n");  
    //  
    //        listen_ret = listen(fd,LISTEN_NUM);  //����socketΪ����״̬  
    //        if(listen_ret < 0)  
    //        {  
    //                perror("listen");  
    //                exit(-1);  
    //        }  
    //        debug("listening\n");  
    //        while(1)  //��ѭ���д�����������  
    //        {  
    //                accept_ret = (int *)malloc(sizeof(int));  //��̬�����ԭ�򣺱����д������������̻߳���  
    //                *accept_ret = accept(fd,(struct sockaddr *)&client_sa,&client_len);  //�����Ӷ����л�ȡ�����õ�socket����  
    //                if(accept_ret < 0)  
    //                {  
    //                        perror("accept");  
    //                        exit(-1);  
    //                }  
    //                printf("accept_ret,fd for client:%d\n",*accept_ret);  
    //  
    //                ret = pthread_create(&thread,NULL,func,(void *)accept_ret);  //Ϊ���Ӵ����߳�  
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
    //void *func(void *fd) //�̴߳�����  
    //{  
    //        int *accept_ret = (int *)fd;  
    //        char receivebuf[20] = {0};  
    //        int recv_ret = -1;  
    //  
    //        while(1)  
    //        {  
    //                recv_ret = recv(*accept_ret,receivebuf,sizeof(receivebuf),0);//���տͻ�������  
    //                if(recv_ret < 0)  
    //                {  
    //                        perror("recv");  
    //                        exit(-1);  
    //                }  
    //                }  
    //                else if(recv_ret == 0)  //���ӶϿ�  
    //                {  
    //                        if(close(*accept_ret)) //�رն�ȡ������  
    //                        {  
    //                                perror("close");  
    //                                exit(-1);  
    //                        }  
    //                        printf("close:%d,exiting subthread\n",*accept_ret);  
    //                        free(accept_ret);  //�ͷŶ�̬������������ռ�  
    //                        pthread_exit(NULL);//�̷߳���  
    //                }  
    //                printf("%d bytes from %d,%s\n",recv_ret,*accept_ret,receivebuf);  
    //                memset(receivebuf,0,strlen(receivebuf));  
    //        }  
    //}  
    //  
    //void sigint_handle(int sig) //�źŴ�����  
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
  
void sigpipe_handle(int arg); //sigpipe�źŴ���������send����recv�ڵȴ����ͻ��ǽ�������ʱ�������ӶϿ���ϵͳ�ᷢ�����ź�  
  
static int fd = -1;  
  int main(int argc,char *argv[])  
{  
        struct sockaddr_in server_sa = {0};  
        int connect_ret = -1;  
  
        int send_ret = -1;  
  
        sighandler_t sig_ret = (sighandler_t)-1;  
  
        fd = socket(AF_INET,SOCK_STREAM,0);   //����socket���ӣ�������������  
        if(fd < 0)  
        {  
                perror("socket");  
                exit(-1);  
        }  
        printf("fd:%d\n",fd);  
  
        sig_ret = signal(SIGPIPE,sigpipe_handle);  //Ϊsigpipe�źŰ󶨴�����  
        if(SIG_ERR == sig_ret)  
        {  
                perror("signal");  
                exit(-1);  
        }  
  
        server_sa.sin_port = htons(SERVER_PORT);  
        server_sa.sin_addr.s_addr = inet_addr(SERVER_IP);  
        server_sa.sin_family = AF_INET;  
        connect_ret = connect(fd,(struct sockaddr *)&server_sa,sizeof(server_sa));  //�������������������  
        if(connect_ret < 0)  
        {  
                perror("connect");  
                exit(-1);  
        }  
        debug("connect done\n");  
  
        char sendbuf[20] = {0};  
        while(1)    //���û���������ݷ��͸��������ˣ�������endʱ���ͻ����˳�  
        {  
                printf("input your data\n");  
                scanf("%s",sendbuf);  
                if(!strncmp(sendbuf, "end",3))  
                {  
                        debug("exiting....\n");  
                        close(fd);  
                        return 0;  
                }  
  
                send_ret = send(fd,sendbuf,strlen(sendbuf),0);  //�������������Ϣ  
                if(send_ret < 0)  
                {  
                        perror("send");  
                        exit(-1);  
                }  
                printf("data sent successfully:%d\n",send_ret);  
        }  
}  
  