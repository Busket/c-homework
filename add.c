#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
int m = 0;
char k,c;
FILE *fp;
void add()
{
	void once();
	int i;
	do
	{
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "r")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}
	
	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//读取出东西时则继续循环，若未读取出则退出循环
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		m = example[i].num;
	}
	m = m + 1;
	example[m - 1].num = m;//用于确定编号
	fclose(fp);
	once();
	printf("是否继续添加信息？（y/n）\n");
	scanf("%c", &c);
	k = getchar();
	putchar(10);
	} while (c!='n');
}
void save()
{
	//FILE *fp;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C语言程序设计大作业\\c语言大作业\\c语言大作业\\topfile.dat", "ab+")) == NULL)//打开文件
	{
		printf("Can not open this file\n");//若失败，则显示这个
		exit(0);
	}

	if (fwrite(&example[m - 1], sizeof(CON), 1, fp) != 1) 
		printf("File write error\n");
	fclose(fp);
}
void once()
{
	float r;
		printf("编号%d：\n", example[m - 1].num);//1.
		example[m - 1].num = m;
		printf("请问是收入还是支出（in/out）?\n");//询问收入还是支出
		scanf("%s", example[m - 1].io); k = getchar();
		
		//if((strcmp(example[m - 1].io,"in")!=0)||(strcmp(example[m - 1].io,"out")!=0))
			//if(example[m - 1].io !="out")
			while ((strcmp(example[m - 1].io, "in") != 0)&&(strcmp(example[m - 1].io, "out") != 0))
			{
				printf("输入错误，请重新输入：");
				scanf("%s", example[m - 1].io); k = getchar();
			}
		
		printf("请问经办人是谁：");
		scanf("%s", example[m - 1].name); k = getchar();
		printf("原因：");
		scanf("%s", example[m - 1].reason); k = getchar();
		printf("金额(例：9.0)：");
		r=scanf("%f", &example[m - 1].figure); k = getchar();
		if(r==0)
			while(r==0)
			{
				printf("\a输入格式有误，请重新输入:");
				r = scanf("%f", &example[m - 1].figure); k = getchar();
			}
		printf("备注：");
		scanf("%s", example[m - 1].remark); k = getchar();
		example[m - 1].remark[39] = '\0';
		save();
}