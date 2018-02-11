#include<stdio.h>
#include<stdlib.h>
#include"标头.h"
int l = 0; int x = 0; char k;
FILE *fp;
void amend()
{
	int a, c, d;
	char b;
	int browse2();
	void change(int c, int d);
	c = browse2();
	do
	{
		printf("请选择需要修改的项目编号：");
		scanf("%d", &a);
		k = getchar();
		if (a>c)
		{
			do
			{
				printf("输入错误！请重新输入：");
				scanf("%d", &a);
				k = getchar();
			} while (a>c);
		}
		change(a, c);//a是要修改的编号，c是编号总数 
		printf("是否需要修改其他编号的信息？（y/n）");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');

}
void change(int c, int d)//a是要修改的编号，c是编号总数 
{
	char a, b;
	int i;
	float r=0.0;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb+")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	do
	{
		//fread(&example[c-1], sizeof(CON), 1, fp);
		printf("请选择要修改的项目：\n1.收/支\n2.经手人\n3.原因\n4.金额\n5.备注\n");
		scanf("%c", &a);
		k = getchar();
		for(i=0;i<c;i++)
			fseek(fp,i*sizeof(CON), 0);
		switch (a)
		{
		case '1':
		{
			//fread(example[c - 1].io, sizeof(CON), 1, fp);
			fseek(fp, 4, 1);
			printf("请问是收入还是支出（in/out）?\n");//询问收入还是支出
			scanf("%s", example[c - 1].io); k = getchar();
			while ((strcmp(example[c - 1].io, "in") != 0) && (strcmp(example[c - 1].io, "out") != 0))
			{
				printf("输入错误，请重新输入：");
				scanf("%s", example[c - 1].io); k = getchar();
			}
			if (fwrite(example[c - 1].io, 4, 1, fp) != 1)
				printf("File write error\n");
			rewind(fp);
			//fclose(fp);
		}; break;
		case '2':
		{
			fseek(fp, 8, 1);
			printf("请问经办人是谁：");
			scanf("%s", example[c - 1].name); k = getchar();
			if (fwrite(example[c - 1].name, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp);
			//fclose(fp);
		}; break;
		case '3':
		{
			fseek(fp, 16, 1);
			printf("原因：");
			scanf("%s", example[c - 1].reason); k = getchar();
			if (fwrite(example[c - 1].reason, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp); 
		}; break;
		case '4': 
		{
			fseek(fp, 56, 1);
			printf("金额(例：9.0)：");
			scanf("%f", &example[c - 1].figure); k = getchar();
			if (r == 0)
				while (r == 0)
				{
					printf("\a输入格式有误，请重新输入:");
					r = scanf("%f", &example[c - 1].figure); k = getchar();
				}
			if (fwrite(&example[c - 1].figure, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp); 
		}; break;
		case '5': 
		{
			fseek(fp, 60, 1);
			printf("备注：");
			scanf("%s", example[c - 1].remark); k = getchar();
			example[c - 1].remark[39] = '\0';
			if (fwrite(&example[c - 1].remark, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp);
		}; break;
		}
		printf("是否需要修改此编号的其他信息？（y/n）");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
	fclose(fp);
}


//用于显示所有的信息，以方便选择进行更改,并带回最大编号
int browse2(void)
{
	int read2(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "r")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}

	for (l = 0; (fread(&example[l], sizeof(CON), 1, fp)) == 1; l++)//读取出东西时则继续循环，若未读取出则退出循环
	{
		fread(&example[l], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		x = example[l].num;//n是i的最大值，就等于总量
						   //x = l;
	}
	example[x - 1].num = x;//用于确定编号
	fclose(fp);
	read2(x);
	//a = getchar();
	return l+1;
}
int read2(int x)
{
	int j;
	//float remain(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "rb")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	printf("编号 收/支  经手人  原因                                                                              金额   备注\n");
	for (j = 0; j<x//以下函数用于显示所有数据
		; j++)
	{
		fread(&example[j], sizeof(CON), 1, fp);

		printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
		putchar('\n');
	}
	fclose(fp);
	return 0;
}