#include<iostream>  
using namespace std;  
void quickSort(int a[],int,int);  
int main()  
{  
    int array[]={34,65,12,43,67,5,78,10,3,70},k;  
    int len=sizeof(array)/sizeof(int);  
    cout<<"The orginal arrayare:"<<endl;  
    for(k=0;k<len;k++)  
        cout<<array[k]<<",";  
    cout<<endl;  
    quickSort(array,0,len-1);  
    cout<<"The sorted arrayare:"<<endl;  
    for(k=0;k<len;k++)  
        cout<<array[k]<<",";  
    cout<<endl;  
    system("pause");  
    return 0;  
}  
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // ���������ҵ�һ��С��x����  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // �ݹ����  
        quickSort(s, i + 1, r);  
    }  
}  
void DataSwap(int* data1, int* data2)  
{  
    int temp = *data1;  
    *data1 = *data2;  
    *data2 = temp;  
}  
void SelectionSort(int* pDataArray, int iDataNum)  
{  
    for (int i = 0; i < iDataNum - 1; i++)    //�ӵ�һ��λ�ÿ�ʼ  
    {  
        int index = i;  
        for (int j = i + 1; j < iDataNum; j++)    //Ѱ����С����������   
            if (pDataArray[j] < pDataArray[index])  
                index = j;  
  
        if (index != i)    //�����С��λ�ñ仯�򽻻�  
            DataSwap(&pDataArray[index], &pDataArray[i]);  
    }  
}  
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void insertion(int a[], int sz)
{
    for(int i=1; i  < sz; i++) {
        int j = i;
        while(j > 0 && (a[j] < a[j-1])) {
            swap(a[j], a[j-1]);
            j--;
        }
        cout << endl;
        for (int k = 0; k < sz; k++) cout << setw(3) << a[k];
    }
}

int main()
{
    int a[] = { 15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
    int size = sizeof(a)/sizeof(int);
    for (int i = 0; i < size; i++) cout << setw(3) << a[i];
    insertion(a, size);
    cout << endl;
    return 0;
}

void exchange(int A[], int i, int j)        // ����A[i]��A[j]
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // ��С����ð������
    int n = sizeof(A) / sizeof(int);                
    for (int j = 0; j < n - 1; j++)            // ÿ�����Ԫ�ؾ�������һ��"��"����������
    {
        for (int i = 0; i < n - 1 - j; i++)    // ���αȽ����ڵ�����Ԫ��,ʹ�ϴ���Ǹ������
        {
            if (A[i] > A[i + 1])            // ��������ĳ�A[i] >= A[i + 1],���Ϊ���ȶ��������㷨
            {
                exchange(A, i, i + 1);        
            }
        }
    }
    printf("ð����������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}