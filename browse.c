#include<stdio.h>
#include<stdlib.h>
#include"��ͷ.h"
int i = 0; int n = 0;
FILE *fp;
void browse()
{
	char a;
	int read(int i); int i;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "r")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//��ȡ������ʱ�����ѭ������δ��ȡ�����˳�ѭ��
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		n = example[i].num;//n��i�����ֵ���͵�������
		//n = i;
	}
	example[n - 1].num = n;//����ȷ�����
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
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}
	printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
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
	printf("                                                                                                      ��%6.2f\n",sum);
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