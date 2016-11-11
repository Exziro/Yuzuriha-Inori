#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)

int fib(int n)
{
	if (n < 3){
		return 1;
	}
	int pre_data = 1;
	int ppre_data = 1;
	int data = 1;
	while (n > 2){
		ppre_data = pre_data;
		pre_data = data;
		data = pre_data + ppre_data;
		n--;
	}
	return data;
}

int main()
{
	printf("Please Enter: ");
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

////void swap(char *x, char *y)
////{
////	*x ^= *y;
////	*y ^= *x;
////	*x ^= *y;
////}
////
////void reverse(char *start, char *end)
////{
////	assert(start);
////	assert(end);
////
////	while (start < end){
////		swap(start, end);
////		start++, end--;
////	}
////}
////
////
//////1
//////void strShift(char *str, int len, int step)
//////{
//////	assert(str);
//////	assert(len > 0);
//////	step %= len;
//////	int i = 0;
//////	for (; i < step; i++){
//////		char tmp = str[0];
//////		int j = 0;
//////		for (; j < len - 1; j++){
//////			str[j] = str[j 
//////				+ 1];
//////		}
//////		str[j] = tmp;
//////	}
//////}
////
////void strShift(char *str, int len, int step)
////{
////	assert(str);
////	assert(len > 0);
////	step %= len;
////	char* start = str;
////	char* middle = str + step - 1;
////	char* end = str + len - 1;
////	reverse(start, middle);
////	reverse(middle+1, end);
////	reverse(start, end);
////}
////3.
//void strShift(char* str, int len, int step)
//{
//	assert(str);
//	assert(len>0);
//	step %= len;
//	char* buf = (char*)malloc(sizeof(char)*len*2+1);
//	strcpy(buf, str);
//	strcat(buf, str);
//	strncpy(str, buf+step, len);
//	free(buf);
//	buf = NULL;
//}
//int isShiftStr(char *src, char *dst)
//{
//	assert(src);
//	assert(dst);
//	if (strlen(src) == strlen(dst)){
//		int len = strlen(src);
//		char* buf = (char*)malloc(sizeof(char)*len * 2 + 1);
//		strcpy(buf, src);
//		strcat(buf, src);
//
//		if (strstr(buf, dst) == NULL){
//			return 0;
//		}
//		free(buf);
//		buf = NULL;
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char str[] = "ABCD1234";
//	char src[] = "1234ABCE";
//	int len = strlen(str);
//	printf("Please Enter: ");
//	int k = 0;
//	scanf("%d", &k);
//
//	printf("before: %s\n", str);
//
//	strShift(str, len, k);
//
//	printf("after: %s\n", str);
//
//	printf("is shift string? %d\n", isShiftStr(str, src));
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int total = 30;
//	int bottles = 30;
//	while (bottles > 1){
//		total += bottles / 2;
//		bottles = bottles / 2 + bottles % 2;
//	}
//
//	printf("%d, %d\n", total, bottles);
//
//	system("pause");
//	return 0;
//}
//void swap(char *x, char *y)
//{
//	*x ^= *y;
//	*y ^= *x;
//	*x ^= *y;
//}
//void reverse(char *msg, int len)
//{
//	assert(msg);
//	assert(len > 0);
//
//	char *start = msg;
//	char *end = msg + len - 1;
//
//	while (start < end){
//		swap(start, end);
//		start++, end--;
//	}
//}
//
//int main()
//{
//	char msg[] = "abcdefg";//gfedcba
//
//	printf("before : %s\n", msg);
//
//	reverse(msg, strlen(msg));
//
//	printf("after : %s\n", msg);
//	system("pause");
//	return 0;
//}
//char *my_strstr(const char *dststr, const char *substr)
//{
//	assert(dststr);
//	assert(substr);
//
//	if ( strlen(dststr) < strlen(substr)){
//		return NULL;
//	}
//	const char *dst_start = dststr;
//	const char *sub_start = substr;
//	const char *dst_end = dst_start + strlen(dststr) - strlen(substr);
//
//	while (dst_start <= dst_end){
//		char *pos = dst_start;
//		while( *sub_start != '\0' &&\
//			*dst_start == *sub_start ){
//
//			dst_start++, sub_start++;
//
//		}
//		if (*sub_start == '\0'){
//			return pos;
//		}
//		else{
//			dst_start = pos + 1;
//			sub_start = substr;
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	//printf("%s\n", strstr( "abcdhellocdfhelloc","hello"));
//	printf("%s\n", my_strstr( "abchello","hello"));
//	system("pause");
//	return 0;
//}

//#define EXANGE(x) ((((x)&0x55555555)<<1) |\
//	(((x)&0xAAAAAAAA)>>1))
//
//int main()
//{
//	printf("Please Enter: ");
//	unsigned int data = 0;
//	scanf("%u", &data);
//
//	printf("%u -> %u\n", data, EXANGE(data));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	system("pause");
//	return 0;
//}
