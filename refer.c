#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
FILE *fp;
int j,t;
char k,b;//k用于收集\n
void refer()
{
	void man();
	void reason();
	void figure();
	void remark();
	char a,b;
	int i, n;

	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//读取出东西时则继续循环，若未读取出则退出循环
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		n = example[i].num;//n是i的最大值，就等于总量
	}
	example[n - 1].num = n;//用于确定编号
	fclose(fp);
	do
	{
		printf("请选择您所需要的搜索字段：\n");
		printf("1.经手人。\n2.原因。\n3.金额。\n4.备注。\n");
		a = getchar();
		//k = getchar();
		switch (a)
		{
		case '1':man(n); break;//关键词：经手人
		case'2':reason(n); break;//关键词：原因
		case'3':figure(n); break;//关键词：金额
		case'4':remark(n); break;//关键词：备注
		}
		printf("您是否需要选择其他字段搜索？(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}
void man(int n)
{
	char a[8];
	do
	{
		printf("请输入您所要搜查的经手人（精确搜索）：");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb+")) == NULL)//打开文件
		{
			printf("Can not open this file\n");//若失败，则显示这个
			exit(0);
		}
		printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
			for (j = 0, t = 0; j < n; j++)
			{
				fread(&example[j], sizeof(CON), 1, fp);
				if (strcmp(example[j].name, a) == 0)
				{
					printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
					putchar('\n');
					t++;
				}
			}
			if (t == 0) printf("没有搜到您想要的！\n");
			fclose(fp);
			printf("您是否需要就当前字段重新搜索？(y/n)\n");
			scanf("%c", &b);
			k = getchar();
	}while (b != 'n');
}
void reason(int n)
{
	char a[40];
	int h, g,z=0,y=0;
	do
	{
		printf("请输入您所要搜查的原因：");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb+")) == NULL)//打开文件
		{
			printf("Can not open this file\n");//若失败，则显示这个
			exit(0);
		}
		printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
		for (j = 0, t = 0; j < n; j++)
		{
			fread(&example[j], sizeof(CON), 1, fp);
			for (h = 0; example[j].reason[h] != '\0'; h++)
			{
				for (g = 0; a[g] != '\0'; g++)
				{
					if (example[j].reason[h] == a[g]) 
					{
						z = g; break;
					}
				}
				if (example[j].reason[h] == a[g])
				{
					y = h; break;
				}
			}
			if (example[j].reason[y] == a[z])
			{
				printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
				putchar('\n');
				t++;
			}
		}
		if (t == 0) { putchar(10); printf("没有搜到您想要的！\n"); }
		fclose(fp);
		printf("您是否需要就当前关键字段重新搜索？(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}
void figure(int n)
{
	float a;
	do
	{
		printf("请输入您所要搜查的金额（精确搜索）：");
		scanf("%f",&a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb+")) == NULL)//打开文件
		{
			printf("Can not open this file\n");//若失败，则显示这个
			exit(0);
		}
		printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
		for (j = 0, t = 0; j < n; j++)
		{
			fread(&example[j], sizeof(CON), 1, fp);
			if (example[j].figure== a)
			{
				printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
				putchar('\n');
				t++;
			}
		}
		if (t == 0) 
		{
			printf("没有搜到您想要的！\n"); putchar(10);
		}
		fclose(fp);
		printf("您是否需要就当前字段重新搜索？(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}
void remark(int n)
{
	char a[40];
	int h, g, z = 0, y = 0;
	do
	{
		printf("请输入您所要搜查的备注：");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb+")) == NULL)//打开文件
		{
			printf("Can not open this file\n");//若失败，则显示这个
			exit(0);
		}
		printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
		for (j = 0, t = 0; j < n; j++)
		{
			fread(&example[j], sizeof(CON), 1, fp);
			for (h = 0; example[j].remark[h] != '\0'; h++)
			{
				for (g = 0; a[g] != '\0'; g++)
				{
					if (example[j].remark[h] == a[g])
					{
						z = g; break;
					}
				}
				if (example[j].remark[h] == a[g])
				{
					y = h; break;
				}
			}
			if (example[j].remark[y] == a[z])
			{
				printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
				putchar('\n');
				t++;
			}
		}
		if (t == 0) { putchar(10); printf("没有搜到您想要的！\n"); }
		fclose(fp);
		printf("您是否需要就当前关键字段重新搜索？(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}