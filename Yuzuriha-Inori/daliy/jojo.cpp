
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
void link_process(Node *head,int k,int m)//�ӱ��Ϊk(1<=k<=n)���˿�ʼ����������m���Ǹ��˳��У�  
{  
    int i;  
    Node *p = head,*tmp1;  
    while(p->data != k)//pָ��Ľڵ�dataΪk  
        p = p->pnext;  
      