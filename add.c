#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
int m = 0;
char k,c;
FILE *fp;
void add()
{
	void once();
	int i;
	do
	{
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "r")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}
	
	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//��ȡ������ʱ�����ѭ������δ��ȡ�����˳�ѭ��
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		m = example[i].num;
	}
	m = m + 1;
	example[m - 1].num = m;//����ȷ�����
	fclose(fp);
	once();
	printf("�Ƿ���������Ϣ����y/n��\n");
	scanf("%c", &c);
	k = getchar();
	putchar(10);
	} while (c!='n');
}
void save()
{
	//FILE *fp;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "ab+")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}

	if (fwrite(&example[m - 1], sizeof(CON), 1, fp) != 1) 
		printf("File write error\n");
	fclose(fp);
}
void once()
{
	float r;
		printf("���%d��\n", example[m - 1].num);//1.
		example[m - 1].num = m;
		printf("���������뻹��֧����in/out��?\n");//ѯ�����뻹��֧��
		scanf("%s", example[m - 1].io); k = getchar();
		
		//if((strcmp(example[m - 1].io,"in")!=0)||(strcmp(example[m - 1].io,"out")!=0))
			//if(example[m - 1].io !="out")
			while ((strcmp(example[m - 1].io, "in") != 0)&&(strcmp(example[m - 1].io, "out") != 0))
			{
				printf("����������������룺");
				scanf("%s", example[m - 1].io); k = getchar();
			}
		
		printf("���ʾ�������˭��");
		scanf("%s", example[m - 1].name); k = getchar();
		printf("ԭ��");
		scanf("%s", example[m - 1].reason); k = getchar();
		printf("���(����9.0)��");
		r=scanf("%f", &example[m - 1].figure); k = getchar();
		if(r==0)
			while(r==0)
			{
				printf("\a�����ʽ��������������:");
				r = scanf("%f", &example[m - 1].figure); k = getchar();
			}
		printf("��ע��");
		scanf("%s", example[m - 1].remark); k = getchar();
		example[m - 1].remark[39] = '\0';
		save();
}