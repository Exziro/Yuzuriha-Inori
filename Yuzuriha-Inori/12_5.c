#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	printf("hello bit");
	fflush(stdout);
	sleep(3);//Sleep();
	//exit(123);
//	int i = 0;
//	for(; i < 100; i++){
//		printf("%d: %s\n", i, strerror(i));
//	}
	// errno, perror
	//int *p = NULL;//(int*)malloc(10000000000000000000000000000);
	//printf("%s\n", p);
	//FILE *fp = fopen("log.txt", "r");//r w a r+ w+ a+
	//if(NULL == fp){
	//	//printf("%d, %s\n", errno, strerror(errno));
	//	perror("fopen");
	//	return 1;
	//}

	return 0;
}
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

struct person{
	char name[64];
	char sex;
	int age;
}man[3] = {
	{"zhangsan", 'm', 32},
	{"lisi", 'w', 21},
	{"wangwu", 'm', 43},
};

int main()
{
	//int ch;
	//ch = fgetc(stdin);
	//printf("%c\n", ch);
	//ch = fgetc(stdin);
	//printf("%c\n", ch);
	//ungetc(ch, stdin);
	//char buf[32];
	//fgets(buf, 32, stdin);
	//printf("%s\n", buf);
	//float a = 1234.5678;
	//char buf[32];
	//sprintf(buf, "%f", a);

	//printf("%s\n", buf);
	//char a[] = "1234";
	//int b = 0;
	//sscanf(a, "%d", &b);
	//printf("%d\n", b);
	//system("pause");
	FILE * fp = fopen("new_file.txt", "r+");
	if (NULL == fp){
		perror("fopen");
		return 1;
	}

	//fwrite(man, sizeof(man[0]), 3, fp);
	/*struct person buf;
	int i = 3;
	while (i--){
		fread(&buf, sizeof(struct person), 1, fp);
		printf("%s, %c, %d\n", buf.name, buf.sex, buf.age);
	}
*/
	/*char buf[100];
	while (fgets(buf, sizeof(buf), fp) != NULL){
		printf("read: %s", buf);
	}*/
	//int i = 10;
	//while (i--){
	//	printf("pos : %d\n", ftell(fp));
	//	fputc('a'+i, fp);
	//	//const char *msg = "hello world\n";
	//	//fputs(msg, fp);
	//}
	//fseek(fp, 3, 0);
	//fputc('A', fp);
	////fputc('B', fp);

	fputs("hello bit\n", fp);
	char buf[32];
	buf[0] = '\0';
	fseek(fp, 1, 0);
	fgets(buf, 32, fp);
	printf("result: %s\n", buf);


	printf("fopen success\n");
	fclose(fp);

	printf("fclose done...\n");
	system("pause");
	return 0;
}
