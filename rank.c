#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
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
	printf("��ѡ������ؼ��֣�\n1.��/֧\n2.������\n3.ԭ��\n");
	scanf("%c", &a);
	k = getchar();
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\ranfile.dat", "ab+")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
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
int browse3()//����ȷ�����ݸ���
{
	char a;
	int read(int i); int i; int n = 0;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\ranfile.dat", "r")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//��ȡ������ʱ�����ѭ������δ��ȡ�����˳�ѭ��
	{
		fread(&example[i], sizeof(CON), 1, fp);
		n = example[i].num;//n��i�����ֵ���͵�������
						   //n = i;
	}
	example[n - 1].num = n;//����ȷ�����
	fclose(fp);
	//read(n);
	return n;
}
int read3(int n)//��ʾ����
{
	int j; int i = 0; 
	int sign = 1;
	float sum=0.0;
	//float remain(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\ranfile.dat", "rb")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}
	printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
	for (j = 0; j<=n; j++)//����������ʾ��������
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
	printf("                                                                                                      ��%6.2f\n", sum);
	return 0;
}