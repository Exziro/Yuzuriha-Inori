
    #include<stdio.h>   
    #include <stdlib.h>  
      
    typedef struct node//节点存放一个数据和指向下一个节点的指针  
    {  
        int data;  
        struct node* pnext;  
    } Node;  
      
    Node *link_create(int n)//创建n个节点的循环链表  
    {  
        //先创建第1个节点  
        Node *p,*q,*head;  
        int i ;  
        p = (Node *)malloc(sizeof(Node));  
        head = p;  
        p->data = 1;  
      
        for(i = 2;i<=n;i++)//再创建剩余节点  
        {  
            q = (Node *)malloc(sizeof(Node));  
            q->data = i;  
            p->pnext = q;  
            p = q;  
        }  
        p->pnext = head;//最后一个节点指向头部，形成循环链表  
        return head;  
    }  