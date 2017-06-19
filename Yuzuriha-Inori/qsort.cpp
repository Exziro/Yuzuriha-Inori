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