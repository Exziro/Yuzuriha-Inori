#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <string.h>

void *my_memmove(void *dst, void *src, int count)
{
	assert(dst);
	assert(src);

	char *_dst = (char*)dst;
	char *_src = (char*)src;
	char *ret = _dst;

	if (_src < _dst && _src + count > _dst){//ºó-¡·Ç°
		char *_dst_end = _dst + count - 1;
		char *_src_end = _src + count - 1;
		while (count--){
			*_dst_end = *_src_end;
			_dst_end--, _src_end--;
		}

	}else{
		while (count--){
			*_dst = *_src;
			_dst++, _src++;
		}
	}
	return ret;
}

int main()
{
	char name[] = "abcdef";
	printf("%d\n", sizeof(name[0]));
	printf("%d\n", sizeof(&name));
	printf("%d\n", sizeof(*name));
	printf("%d\n", sizeof(&name + 1));
	printf("%d\n", sizeof(name + 1));
	printf("%d\n", sizeof(name));
	printf("%d\n", strlen(name));
	printf("%d\n", strlen(&name));
	printf("%d\n", strlen(&name + 1));
	printf("%d\n", strlen(name + 1));
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a)); 
	//printf("%d\n", sizeof(a + 0));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1]));
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(&a + 1));
	//printf("%d\n", sizeof(&a[0]));
	//printf("%d\n", sizeof(&a[0] + 1));
	//printf("%d\n", sizeof(*&a));

	//printf("%p\n", a);
	//printf("%p\n", &a);
	//printf("%p\n", a+1);
	//printf("%p\n", &a+1);
	//printf("%d\n", sizeof(void*));
	//printf("%d\n", sizeof(void));
	//int a = 0;
	/*char src[32] = "hello bit";
	char dst[32];
	my_memmove(src+1, src, strlen(src) + 1);
	printf("%s\n", src);*/
	system("pause");
	return 0;
}