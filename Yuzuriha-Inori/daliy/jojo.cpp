
    #include<stdio.h>   
    #include <stdlib.h>  
      
    typedef struct node//�ڵ���һ�����ݺ�ָ����һ���ڵ��ָ��  
    {  
        int data;  
        struct node* pnext;  
    } Node;  
      
    Node *link_create(int n)//����n���ڵ��ѭ������  
    {  
        //�ȴ�����1���ڵ�  
        Node *p,*q,*head;  
        int i ;  
        p = (Node *)malloc(sizeof(Node));  
        head = p;  
        p->data = 1;  
      
        for(i = 2;i<=n;i++)//�ٴ���ʣ��ڵ�  
        {  
            q = (Node *)malloc(sizeof(Node));  
            q->data = i;  
            p->pnext = q;  
            p = q;  
        }  
        p->pnext = head;//���һ���ڵ�ָ��ͷ�����γ�ѭ������  
        return head;  
    }  