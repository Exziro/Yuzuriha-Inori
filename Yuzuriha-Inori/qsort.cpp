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
//void DataSwap(int* data1, int* data2)  
//{  
//    int temp = *data1;  
//    *data1 = *data2;  
//    *data2 = temp;  
//}  
//void SelectionSort(int* pDataArray, int iDataNum)  
//{  
//    for (int i = 0; i < iDataNum - 1; i++)    //�ӵ�һ��λ�ÿ�ʼ  
//    {  
//        int index = i;  
//        for (int j = i + 1; j < iDataNum; j++)    //Ѱ����С����������   
//            if (pDataArray[j] < pDataArray[index])  
//                index = j;  
//  
//        if (index != i)    //�����С��λ�ñ仯�򽻻�  
//            DataSwap(&pDataArray[index], &pDataArray[i]);  
//    }  
//}  