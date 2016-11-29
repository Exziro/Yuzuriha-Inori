#include<stdio.h>
#include<windows.h>
#include<assert.h>
int *S_bubble(void *arr,int n,int width,int *comp(void *,void *))
{
	int i =0;
	int j=0;
	int flag =0;
	int k=0;
	char *start=(char*)arr;
	assert(arr);
	for(i=0;i<n;i++){
		{for(j=0;j<n-1-i;j++)
		{if(comp(start,start+width)>0)
		{
			for(k=0;k<width;k++)
				start[k]^=start[k+width];
				start[k+width]^=start[k];
				start[k]^=start[k+width];
		}
		start+=width;}
	}flag=1;
	if(flag!=0)
		break;
		}
}

