#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
int k;
FILE *fp;
void rank()
{
	int j, l,x;
	char a;
	int browse3();
	int read3(int n);
	void copy();
	copy();
	x = browse3();
	printf("请选择排序关键字：\n1.收/支\n2.经手人\n3.原因\n");
	scanf("%c", &a);
	k = getchar();
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\ranfile.dat", "ab+")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	switch (a)
	{
	case '1': 
	{
		for (j = 0; j<=x; j++)
			for (l = j + 1; l <= x; l++)
			{
				if (strcmp(example[j].io, example[l].io)>0)
				{
					memcpy(&ran[1], &example[j], sizeof(CON));
					//ran[1] = example[j];
					memcpy(&example[j], &example[l], sizeof(CON));
					//example[j] = example[l];
					memcpy(&example[l], &ran[1], sizeof(CON));
					//example[l] = ran[1];
				}
			}
		for (j = 0; j<=x; j++)
			if (fwrite(&example[j], sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
		fclose(fp);
		read3(x);
	}
	; break;
	case '2': {}; break;
	case '3': {}; break;
		break;
	}
	
}
void copy()
{
	FILE *fp1, *fp2;
	fp1 = fopen("topfile.dat", "r");
	fp2 = fopen("ranfile.dat", "w");
	while (!feof(fp1)) putc(getc(fp1), fp2);
	fclose(fp1);
	fclose(fp2);
}
int browse3()//用于确定数据个数
{
	char a;
	int read(int i); int i; int n = 0;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\ranfile.dat", "r")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//读取出东西时则继续循环，若未读取出则退出循环
	{
		fread(&example[i], sizeof(CON), 1, fp);
		n = example[i].num;//n是i的最大值，就等于总量
						   //n = i;
	}
	example[n - 1].num = n;//用于确定编号
	fclose(fp);
	//read(n);
	return n;
}
int read3(int n)//显示数据
{
	int j; int i = 0; 
	int sign = 1;
	float sum=0.0;
	//float remain(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\ranfile.dat", "rb")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
	for (j = 0; j<=n; j++)//以下用于显示所有数据
	{
		fread(&example[j], sizeof(CON), 1, fp);

		printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num,example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
		putchar('\n');
	}
	for (j = 0; j<=n; j++)
	{
		fread(&example[j], sizeof(CON), 1, fp);
		printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
		if (strcmp(example[j].io, "in") == 0) sign = 1;
		else if (strcmp(example[j].io, "out") == 0) sign = -1;
		sum = sum + (example[j].figure*sign);
		putchar('\n');
	}
	fclose(fp);
	printf("                                                                                                      余额：%6.2f\n", sum);
	return 0;
}