#include<stdio.h>
//#include"标头.h"
//#include"add.c"
//#include"browse.c"
char k;
int main()
{
	char b;
	void add();
	void browse(); 
	void choice();
	void refer();
	void amend();
	void rank();

	do
	{
	choice();
	printf("是否还需要其他服务？(y/n)\n");
	scanf("%c", &b);
	k = getchar();
	} while (b!='n');

	putchar('\n');
	printf("感谢使用！\n");
	return 0;
}
void choice()
{
		char a;
		printf("****************************\n");
		printf("这是一个管理班级收支的程序。      （容错率不高，请谨慎使用！）\n");
		printf("****************************\n");
		putchar(10);
		printf("请选择您所需要的服务。\n");
		printf("1.添加班费收支信息。\n2.浏览所有班费收支信息。\n3.查询班费收支信息。\n");
		printf("4.修改班费收支信息。\n5.按指定字段排序并浏览。\n");
		putchar(10);
		scanf("%c", &a);
		k = getchar();
		switch (a)
		{
		case '1':add(); break;//添加信息
		case '2':browse(); break;//浏览
		case '3':refer(); break;//查询
		case '4':amend(); break;//修改
		case '5':rank(); break;
		}
}