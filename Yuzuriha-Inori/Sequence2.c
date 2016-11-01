#include <stdio.h>  
#include <stdlib.h>  
#include<windows.h>
#define LIST_INIT_SIZE 1000 //���Ա�洢�ռ�ĳ�ʼ������  
#define LISTINCRESEMENT 100 //���Ա�洢�ռ�ķ�������  
#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  
typedef int elemType;//Ԫ������  
typedef struct  
{  
    elemType *List;//���Ա��׵�ַ  
    int length;//��ǰ�ĳ���  
    int listsize;//��ǰ����Ĵ洢��������elemTypeΪ��λ  
} SqList;  
  
void AgainMalloc(SqList *L)//�ռ䲻��ʱ���·���ռ�ĺ���  
{  
    elemType *newbase;//����һ����ʱ��ַ  
    newbase=(elemType *)realloc(L->List,(L->listsize+LISTINCRESEMENT)*sizeof(elemType));  
    if(!newbase) exit(OVERFLOW);  
    L->List=newbase;  
    L->listsize+=LISTINCRESEMENT;  
}  
  
//��ʼ��һ���յ����Ա�  
int InitList_Sq(SqList *L)  
{  
    L->List=(elemType *)malloc(LIST_INIT_SIZE*sizeof(elemType));  
    if(!L->List)exit(OVERFLOW);//overflow  
    L->length=0;//��ʼ��Ϊ�ձ�  
    L->listsize=LIST_INIT_SIZE;//��ʼ��Ĵ洢������ΪLIST_INIT_SIZE��elemType��λ  
    return OK;  
}  
//�����Ԫ�صĸ���  
int ListLength(SqList *L)  
{  
    return L->length;  
}  
  
//����˳���  
void TraverseList(SqList *L)  
{  
    int i;  
    for(i=0; i<L->length; i++)  
    {  
        printf("%d ",L->List[i]);  
    }  
    printf("\n");  
    return;  
}  
//���ͷ����Ԫ��  
void InsertFirst(SqList *L,elemType e)  
{  
    int i;  
    if(L->length>=L->listsize)  
        AgainMalloc(L);  
    for(i=L->length-1; i>=0; i--)  
        L->List[i+1]=L->List[i];  
    L->List[0]=e;  
    L->length++;  
    return;  
}  
  
//���β����Ԫ��  
void InsertLast(SqList *L,elemType e)  
{  
  
    if(L->length>=L->listsize)  
        AgainMalloc(L);  
    L->List[L->length]=e;  
    L->length++;  
    return;  
}  
//�ڱ��е�pos��λ��֮ǰ������Ԫ��e  
int Insert_Sq(SqList *L,elemType e,int pos)  
{  
    int i;  
    if(pos<1||pos>L->length+1) return ERROR;  
    if(L->length>=L->listsize)//�洢�ռ䲻����Ҫ�����µĿռ�  
        AgainMalloc(L);  
    for(i=L->length-1; i>=pos-1; i--)  
        L->List[i+1]=L->List[i];  
    L->List[pos-1]=e;  
    L->length++;  
    return OK;  
}  
//���Ҹ���Ԫ�ص�λ�ã������ڣ�����λ��(��1��ʼ��)���������ڣ�����-1  
void Search(SqList *L,elemType e)  
{  
    int i;  
    for(i=0; i<L->length; i++)  
    {  
        if(L->List[i]==e)  
        {  
            printf("�ҵ���%d�ڵ�%d��λ��\n",e,i+1);  
            return;  
        }  
    }  
    printf("û�ҵ�\n");  
    return;  
}  
//ɾ����pos��Ԫ�أ���������ֵ  
elemType DeleteElem(SqList *L,int pos)  
{  
    int i;  
    elemType temp;  
    if(pos<1||pos>L->length)  
    {  
        printf("posֵԽ��\n");  
        exit(1);  
    }  
    temp=L->List[pos-1];  
    for(i=pos; i<L->length; i++)  
        L->List[i-1]=L->List[i];  
    L->length--;  
    return temp;  
}  
//�ж����Ա��Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0  
int isEmpty(SqList *L)  
{  
    if(L->length==0)  
        return 1;  
    else  
        return 0;  
}  
  
//˳��������  
void Inverse(SqList *L)  
{  
    int low=0,high=L->length-1;  
    elemType temp;  
    int i;  
    for(i=0; i<L->length/2; i++)  
    {  
        temp=L->List[low];  
        L->List[low++]=L->List[high];  
        L->List[high--]=temp;  
    }  
}  
  
void MergeList(SqList *La,SqList *Lb,SqList *Lc)  
{  
	int i=0,j=0,k=0; 
    //elemType *pa=La->List;elemType *pb=Lb->List;  
    Lc->listsize=Lc->length=La->length+Lb->length;  
    Lc->List=(elemType *)malloc(sizeof(elemType));  
    if(!Lc->List) exit(OVERFLOW);  
     
    while(i<La->length&&j<Lb->length)  
    {  
        if(La->List[i]<=Lb->List[j])  
        {  
            Lc->List[k++]=La->List[i++];  
        }  
        else  
        {  
            Lc->List[k++]=Lb->List[j++];  
        }  
    }  
    while(i<La->length)  
    {  
        Lc->List[k++]=La->List[i++];  
    }  
    while(j<Lb->length)  
    {  
        Lc->List[k++]=Lb->List[j++];  
    }  
}  
int main()  
{      int length;
		    int i;  
    SqList list1;  
    InitList_Sq(&list1);  
  
    scanf("%d",&length);  

    elemType temp;  
    for(i=0; i<length; i++)  
    {  
        scanf("%d",&temp);  
        InsertLast(&list1,temp);  
    }  
    printf("�����õ����Ա�La=");  
    TraverseList(&list1);//�����õ�˳���  
    int pos;  
    scanf("%d%d",&temp,&pos);  
    Insert_Sq(&list1,temp,pos);  
    printf("����һ��Ԫ�غ�����Ա�La=");  
    TraverseList(&list1);//����һ�����ֺ�����Ա�  
    scanf("%d",&pos);  
    DeleteElem(&list1,pos);  
    printf("ɾ��һ��Ԫ�غ�����Ա�La=");  
    TraverseList(&list1);  
    scanf("%d",&temp);  
    Search(&list1,temp);//����Ԫ��  
    printf("���ú�����Ա�La=");  
    Inverse(&list1);  
    TraverseList(&list1);  
    SqList list2;  
    InitList_Sq(&list2);  
    scanf("%d",&length);  
    for(i=0; i<length; i++)  
    {  
        scanf("%d",&temp);  
        InsertLast(&list2,temp);  
    }  
  
    SqList list3;  
    MergeList(&list1,&list2,&list3);  
    printf("�ϲ�La��Lb������Ա�=");  
    TraverseList(&list3);
	
	system("pause");
    return 0; 
}  