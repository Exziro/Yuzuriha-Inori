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