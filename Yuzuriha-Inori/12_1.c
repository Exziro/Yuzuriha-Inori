#include<stdio.h>
#include<windows.h>
#include<assert.h>
void bubble_char(void *data,int nums,int width,int(*comp)(void *,void*))
{
	int i=0;
	int k =0;
	int j=0;
	int flag =0;
	assert(data);
	for(;i<nums-1;i++)
	{

		char *start=(char*)data;
		for(;j<nums-1;j++)
		{
			if(comp(start,start+width)>0)
				for(;k<width;k++)
				{
					start[k]^=start[k+width];
					start[k+width]^=start[k];
					start[k]^=start[k+width];
				}
				flag=1;
		}
		start+=width;
	
	if(!flag){
		break;
	}
}
}
void show(int arr[],int len)
{
	int i=0;
	for(;i<len;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}
int comp(void *x,void*y)
{
	char*_x=(char*)x;
	char*_y=(char*)y;
	return *_x-*_y;
}
int main()
{
	char arr[]="hello world";
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%s",arr);

	system("pause");
	return 0;
}