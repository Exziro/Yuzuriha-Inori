#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,};
	int key =7;
	int left = 0;
	int right= sizeof(arr)/sizeof(arr[0]);
	while(left<= right){int mid =(left+right)/2;
		if(arr[mid]<key)
		{
			left=mid+1;
		}
		else if(arr[mid]>key)
		{
			right = mid - 1;
		}
		else{
			printf("�ҵ��ˣ�����Ϊ%d",arr[mid]);
		
		break;}}
	printf("����������û�� ������");
	return 0;

}