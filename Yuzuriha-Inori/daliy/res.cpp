Node *ReverseList(Node *phead)  
{  
    Node *p, *q, *r;  
  
    p = phead;  
    q=r=NULL;  
  
    while(p)  
    {  
        q = p->next;  
        p->next = r;  
        r = p;  
        p = q;  
    }  
    return r;  
} 
node *search(node *head,int k)
{
 
       int length=0;
       node *p=head;
       while (p!=NULL)
       {
              length++;
              p=p->next;
       }
       if (list==NULL||k==0||k>length)
       {
              return NULL;
       }
 
       node *p1=head;
       node *p2=head;

       for (int i=0;i<k-1;i++)
       {
              p1=p1->next;
       }

       while (p1->next!=NULL)
       {
              p1=p1->next;
              p2=p2->next;
       }
       return p2;
}