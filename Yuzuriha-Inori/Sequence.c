#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
const int MAXLISTSIZE=180;    //Ԥ��Ĵ洢�ռ��������
typedef struct seqlist
{
    ElemType *data_address; //�洢�ռ��ַ
    int listlength ;        //��ǰ����
    int listsize;            //��������洢����(��sizeof(ElemType)Ϊ��λ)
}seqlist;                    //�׳�˳���

// ���������ӿ�(��������)
int ListInsert(seqlist *L,int pos,ElemType e);
int LocateElem(seqlist *L, ElemType e, int (*compare)(ElemType, ElemType));
int ListEmpty(seqlist *L);
int ListFull(seqlist *L);
int UpdateElem(seqlist *L,int pos,ElemType e);
int ListDelete(seqlist *L,int pos);
int ListLength(seqlist *L);
void InitList(seqlist *L);
void PrintList(seqlist *L);
void DestroyList(seqlist *L);
void ClearList(seqlist *L);
ElemType GetElem(seqlist *L,int pos);

//����һ�����洢����Ϊmaxsize �Ŀյ�˳���L
void InitList(seqlist *L) //
{
    printf("--------Start InitList()--------\n");  
    L->data_address = (ElemType *)malloc( MAXLISTSIZE * sizeof(ElemType) );
    if( L->data_address==NULL ) 
    {
        exit(1);                //�洢����ʧ��,�����˳�
    }
    L->listsize = MAXLISTSIZE;    //��˳�����Դ洢Ԫ�ص��������
    L->listlength = 0;            //˳���ĳ�ʼ����Ϊ
    printf("--------End InitList()--------\n");      
}

// ��˳���L�в��ҵڸ�ֵ��e �����ж�����compare()��Ԫ�أ�
// ���ҵ����򷵻�����L �е�λ�򣬷��򷵻ء�
int LocateElem(seqlist *L, ElemType e, int (*compare)(ElemType, ElemType))
{
    int i = 1;        // i �ĳ�ֵΪ��Ԫ�ص�λ��
    ElemType *p = L->data_address;    // p �ĳ�ֵΪ��Ԫ�صĴ洢λ��
    while (i <= L->listlength && !(*compare)(*p++,e))
    {
        ++i;    // ���ν����ж�
    }
    if (i <= L->listlength)
    {
        return i;    // �ҵ������ж�����������Ԫ��Ϊ��i ��Ԫ��
    }else
    {
        return 0;    // �����Ա��в����������ж�������Ԫ��
    }
}// LocateElem

//��ȡposλ�õ�Ԫ�ص�ֵ 
ElemType GetElem(seqlist *L,int pos)
{
    if(pos<1 || pos > L->listlength)
    {
        printf("GetElem :: pos is illegal.\n");
        exit(1);
    }
    return (L->data_address[pos-1]);
}  

//�滻posλ��Ԫ�ص�ֵ
int UpdateElem(seqlist *L,int pos,ElemType e)
{
    if(pos<1 || pos>L->listlength){
        printf("pos is illegal!\n");
        return 0;
    }
    L->data_address[pos-1] = e;
    return 1;
}  

//���洢�ռ䲻���ҡ�pos��Listlength(L)+1������˳���L�ĵ�pos��Ԫ��֮ǰ�����µ�Ԫ��e�ҷ���,���򷵻�.
int ListInsert(seqlist *L,int pos,ElemType e)
{    
    int j;
    if (pos < 1 || pos > L->listlength+1)    // ����λ�ò��Ϸ�,�Ϸ�λ����(1) ��(��+1)
    { 
        printf("ListInsert:::Error pos\n");
        return 0;
    }
    if (L->listlength >= L->listsize)        // ��ǰ�洢�ռ��������޷�����
    {    
        printf("ListInsert:::Error full of Store Space\n");
        return 0;
    }
    for ( j=L->listlength-1; j >= pos-1; --j)
    {
        L->data_address[j+1] = L->data_address[j];    // ����λ�ü�֮���Ԫ������,
        //�ڱ���Ԫ��L->data_address[L->listlength-1] ����pos��Ԫ��L->data_address[pos-1]���������
    }                    
    L->data_address[pos-1] = e;        // ����e
    ++L->listlength;                // ����
    return 1;
}

//��ӡ˳���ʮ��Ԫ��һ��
void PrintList(seqlist *L)
{
    int n,i;
    n = ListLength(L);
    printf("*******************************************************************\n");  
    for(i=1;i<=n;++i)
    {
        printf("%6d",GetElem(L,i));
        if((i)%10==0)
            printf("\n");
    }
    printf("\n");  
    printf("*******************************************************************\n");  
}

//��������ر���Ԫ�ظ���
int ListLength(seqlist *L)
{     
    return(L->listlength);   
}

//�ж��Ƿ���� 
int equal(int x,int y)   
{   
    if(x==y)
    {   
        return 1; 
    }else 
    { 
        return 0;   
    }
}

//��ձ�Ԫ��
void ClearList(seqlist *L)
{     
    L->listlength = 0;   
}

//����˳���
void DestroyList(seqlist *L)
{
    free(L->data_address);   
    L->listlength = 0;
    L->listsize = 0;
}

//�ж�˳����Ƿ�Ϊ��
int ListEmpty(seqlist *L)
{
    if(L->listlength == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//�ж�˳����Ƿ�����
int ListFull(seqlist *L)
{
    if(L->listlength==L->listsize)
    {
        return   1;
    }else
    {
        return   0;
    }
}

// ����pos��Listlength(L)�����˳���L ��ɾ����pos ��Ԫ���ҷ���1�����򷵻�0
int ListDelete(seqlist *L,int pos)
{
    int i;
    if( ListEmpty(L) ){
        printf("ListDelete:::seqlist is Empty!");
        return 0;
    }
    
    if(pos<1 || pos>L->listlength)
    {
        printf("ListDelete:::pos is illegal!");
        return 0;
    }
    
    for(i=pos;i<L->listlength;++i)
    {
        L->data_address[i-1] = L->data_address[i];
    }
    L->listlength--;
    return 1;
}

// ����pos��Listlength(L)�����˳���L ��ɾ����pos ��Ԫ���ҷ���1�����򷵻�0, *eΪ��ɾ��Ԫ�ص�ֵ
int ListDeleteE(seqlist *L,int pos,ElemType *e)
{
    int i;
    if( ListEmpty(L) ){
        printf("ListDeleteE:::seqlist is Empty!\n");
        return 0;
    }
    
    if(pos<1 || pos>L->listlength)
    {
        printf("ListDeleteE:::pos is illegal!\n");
        return 0;
    }
    i=pos;
    *e = L->data_address[i-1];//��Ҫɾ����ֵ����e
    for(;i<L->listlength;++i)
    {
        //�ӵ�pos+1��Ԫ��(L->data_address[pos])���ڱ���Ԫ��(L->data_address[L->listlength-1])������ǰ��
        L->data_address[i-1] = L->data_address[i]; 
    }
    L->listlength--; //����һ
    return 1;
}
/*
��֪����A ��B�����������ϵĲ�����ʹA��A��B����B ���ٵ�������
�����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA ��,
�㷨ִ��֮�����Ա�LB ���ٴ��ڡ�
*/
void Union(seqlist *LA, seqlist *LB)
{
    ElemType e;
    int La_len = ListLength(LA);    //������Ա�LA �ĳ���
    while (ListEmpty(LB) == 0)        //���δ���LB ��Ԫ��ֱ��LB Ϊ�ձ�ֹ
    {    
        ListDeleteE(LB,1,&e);        //��LB ��ɾ���ڸ�����Ԫ�ز�����e
        if (LocateElem(LA,e,equal) == 0)
        {
            ListInsert(LA,++La_len,e);// ��LA�в����ں�e ֵ��ͬ������Ԫ��ʱ���в���
        }
    }
    DestroyList(LB);// �������Ա�LB��
}


/* ��֪һ��"�Ǵ�����" B���Թ���һ������A��ʹA ��ֻ����B ������ֵ������ͬ������Ԫ�ء�
 * �������Ա�LA��ʹ��ֻ����LB������ֵ����ͬ������Ԫ��,�㷨���ı����Ա�LB��
 */
void Purge(seqlist *LA, seqlist *LB)
{
    int i;
    ElemType e;
    int La_len = 0;
    int Lb_len = ListLength(LB);        // �����Ա�LB �ĳ���
    InitList(LA);                        // ����һ���յ����Ա�LA
    for (i = 1; i <= Lb_len; i++)        // ���δ���LB ��ÿ��Ԫ��
    {
        e = GetElem(LB, i);                // ȡLB �е�i ������Ԫ�ظ���e
        if (LocateElem(LA, e, equal) == 0)
        {
            ListInsert(LA, ++La_len, e);// ��LA �в����ں�e ֵ��ͬ������Ԫ��ʱ���в���
        }
    } 
} 

/*
  �б����������Ƿ���ȡ�
  ����������ȵĳ�ֱ�Ҫ���������Ǿ�����ͬ��Ԫ�ء�
  �������Ա��ʾ����ʱ���������Ա�ĳ���Ӧ����ȣ�
  �ұ�����������Ԫ�ض���һһ��Ӧ��
  ����ͬ������Ԫ���ڸ��Ե����Ա��е�"λ��"��һ����ͬ��
  �����ɴˣ�"�б��������Ա��е�����Ԫ���Ƿ���ȫ��ͬ"���㷨��
  ����˼��Ϊ��
  �����б����ߵı��Ƿ���ȣ��ڱ���ȵ�ǰ���£�
  �������һ�����е�����Ԫ�أ���������һ�������ҵ�������ȵ�Ԫ�صĻ���
  ��ɵõ�"�������Ա��ʾ�ļ������"�Ľ��ۣ�
  ��֮��ֻҪ��һ��Ԫ������һ�����в����ҵ����Ԫ��ʱ����ɵó�"����"�Ľ��ۡ�
  
����㷨�Ƿ����κ�����¶���ȷ���᲻�������������� 
��Ȼ������㷨˼�뻹��һ��ǰ���ǣ���֪���Ϸ��ϼ������е�Լ��"�����е�Ԫ�ض��Ǳ˴������"��������Ҳ�뵽�˰ɡ�����
    
���"����"�е�Ԫ�ز��ܱ�֤�����죬��ô���������㷨Ӧ���д��  
�����б�ÿ��LA �е�Ԫ����LB �ж�����֮�⣬��Ӧ�������б�LB ��ÿ��Ԫ�ض�����LA ���ҵ���ͬ�ߡ��㲻������дһ������㷨��     
*/


//�����Ա�LA ��LB ����������ȣ�����������Ԫ��Ҳ��ͬ���򷵻�TRUE,���򷵻�FALSE.
int isEqual(seqlist *LA, seqlist *LB)
{
    ElemType e;
    int La_len = ListLength(LA);
    int Lb_len = ListLength(LB);
    if ( La_len != Lb_len )
    {
        return 0; // ����ĳ��Ȳ���
    }else
    {
        int i = 1;
        while ( i<= La_len )
        {
            e = GetElem( LA, i);    // ȡ��LA ��һ��Ԫ��
            if ( LocateElem(LB, e, equal) != 0 )
            {
                i++;    // ���δ�����һ��
            }else
            {
                return 0;    // LB��û�к͸�Ԫ����ͬ��Ԫ��
            }
        } 
        return 1;
    } 
}


//��������
int main()
{
    int i;
	int a[10];
    seqlist L;
    ElemType e;
    InitList(&L);                    //��ʼ��˳���
    srand((unsigned int)time(0));//srand(seed)���ڸ�rand()�����趨���ӡ�
		printf("������ʮ�����֣�");
	  for(i=0;i<10;i++)
	  {
		  scanf("%d",&a[i]);}
    for(i=0;i<10;++i)
    {
        ListInsert(&L,i,a[i]);    //�����Ԫ��
    }
    
    PrintList(&L);
    printf("length:%d, listSize:%d \n",L.listlength,L.listsize);

//  DestroyList(&L);
//     PrintList(&L);
//  printf("length:%d, listSize:%d \n",L.listlength,L.listsize);

    if(LocateElem(&L,0,equal) == 0)
    {
        printf("��˳�����û��Ԫ��ֵΪ\n");
    }else
    {
        printf("��һ��ֵΪ��Ԫ��λ��: %d \n",LocateElem(&L,0,equal));
    }
	printf("%d\n",L.listlength);
	printf("%d  ",L.listlength);
    return 0;
}