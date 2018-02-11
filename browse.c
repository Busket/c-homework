#include<stdio.h>
#include<stdlib.h>
#include"标头.h"
int i = 0; int n = 0;
FILE *fp;
void browse()
{
	char a;
	int read(int i); int i;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "r")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//读取出东西时则继续循环，若未读取出则退出循环
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		n = example[i].num;//n是i的最大值，就等于总量
		//n = i;
	}
	example[n - 1].num = n;//用于确定编号
	fclose(fp);
	read(n);
	//a = getchar();
}
int read(int n)
{
	int j; 
	int sign = 1;
	float sum = 0.0;
	//float remain(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
	for(j=0;j<n;j++)
	{
		fread(&example[j], sizeof(CON), 1, fp);
		
		printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
		if (strcmp(example[j].io, "in") == 0) sign = 1;
		else if (strcmp(example[j].io, "out") == 0) sign = -1;
		sum = sum + (example[j].figure*sign);
		putchar('\n');
	}
	fclose(fp);
	printf("                                                                                                      余额：%6.2f\n",sum);
	//scanf("%c", &a);
	return 0;
}
float remain(int x)
{
	int sign=1;
	float sum=0.0;
	int j;
	for (j = 0; j<x; j++)
	{
		if (example[j].io == "in") sign = 1;
		if (example[j].io == "out") sign = -1;
		sum = sum + (sign*example[j].figure);
	}
	return sum;
}