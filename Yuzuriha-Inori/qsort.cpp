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
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
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
    for (int i = 0; i < iDataNum - 1; i++)    //从第一个位置开始  
    {  
        int index = i;  
        for (int j = i + 1; j < iDataNum; j++)    //寻找最小的数据索引   
            if (pDataArray[j] < pDataArray[index])  
                index = j;  
  
        if (index != i)    //如果最小数位置变化则交换  
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

void exchange(int A[], int i, int j)        // 交换A[i]和A[j]
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    int n = sizeof(A) / sizeof(int);                
    for (int j = 0; j < n - 1; j++)            // 每次最大元素就像气泡一样"浮"到数组的最后
    {
        for (int i = 0; i < n - 1 - j; i++)    // 依次比较相邻的两个元素,使较大的那个向后移
        {
            if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
            {
                exchange(A, i, i + 1);        
            }
        }
    }
    printf("冒泡排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}