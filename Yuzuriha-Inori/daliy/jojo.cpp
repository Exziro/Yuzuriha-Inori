
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
void link_process(Node *head,int k,int m)//从编号为k(1<=k<=n)的人开始报数，数到m的那个人出列；  
{  
    int i;  
    Node *p = head,*tmp1;  
    while(p->data != k)//p指向的节点data为k  
        p = p->pnext;  
     while(p->pnext != p)  
    {  
        for(i=0;i<m;i++)  
        {  
            tmp1 = p;  
            p = p->pnext;  
        }  
        printf("%d ",p->data);  
        tmp1->pnext= p->pnext;  
        free(p);  
        p = tmp1->pnext;  
  
    }  
    printf("%d ",p->data);  
    free(p);  
}   
int main()  
{  
      
    Node *head = link_create(5);      
    link_process(head,3,1);  
    system("pause");  
    return 0;  
}  