#include<stdio.h>
#include<stdlib.h>
#include"��ͷ.h"
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
		printf("��ѡ����Ҫ�޸ĵ���Ŀ��ţ�");
		scanf("%d", &a);
		k = getchar();
		if (a>c)
		{
			do
			{
				printf("����������������룺");
				scanf("%d", &a);
				k = getchar();
			} while (a>c);
		}
		change(a, c);//a��Ҫ�޸ĵı�ţ�c�Ǳ������ 
		printf("�Ƿ���Ҫ�޸�������ŵ���Ϣ����y/n��");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');

}
void change(int c, int d)//a��Ҫ�޸ĵı�ţ�c�Ǳ������ 
{
	char a, b;
	int i;
	float r=0.0;
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb+")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}
	do
	{
		//fread(&example[c-1], sizeof(CON), 1, fp);
		printf("��ѡ��Ҫ�޸ĵ���Ŀ��\n1.��/֧\n2.������\n3.ԭ��\n4.���\n5.��ע\n");
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
			printf("���������뻹��֧����in/out��?\n");//ѯ�����뻹��֧��
			scanf("%s", example[c - 1].io); k = getchar();
			while ((strcmp(example[c - 1].io, "in") != 0) && (strcmp(example[c - 1].io, "out") != 0))
			{
				printf("����������������룺");
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
			printf("���ʾ�������˭��");
			scanf("%s", example[c - 1].name); k = getchar();
			if (fwrite(example[c - 1].name, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp);
			//fclose(fp);
		}; break;
		case '3':
		{
			fseek(fp, 16, 1);
			printf("ԭ��");
			scanf("%s", example[c - 1].reason); k = getchar();
			if (fwrite(example[c - 1].reason, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp); 
		}; break;
		case '4': 
		{
			fseek(fp, 56, 1);
			printf("���(����9.0)��");
			scanf("%f", &example[c - 1].figure); k = getchar();
			if (r == 0)
				while (r == 0)
				{
					printf("\a�����ʽ��������������:");
					r = scanf("%f", &example[c - 1].figure); k = getchar();
				}
			if (fwrite(&example[c - 1].figure, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp); 
		}; break;
		case '5': 
		{
			fseek(fp, 60, 1);
			printf("��ע��");
			scanf("%s", example[c - 1].remark); k = getchar();
			example[c - 1].remark[39] = '\0';
			if (fwrite(&example[c - 1].remark, sizeof(CON), 1, fp) != 1)
				printf("File write error\n");
			rewind(fp);
		}; break;
		}
		printf("�Ƿ���Ҫ�޸Ĵ˱�ŵ�������Ϣ����y/n��");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
	fclose(fp);
}


//������ʾ���е���Ϣ���Է���ѡ����и���,�����������
int browse2(void)
{
	int read2(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "r")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}

	for (l = 0; (fread(&example[l], sizeof(CON), 1, fp)) == 1; l++)//��ȡ������ʱ�����ѭ������δ��ȡ�����˳�ѭ��
	{
		fread(&example[l], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		x = example[l].num;//n��i�����ֵ���͵�������
						   //x = l;
	}
	example[x - 1].num = x;//����ȷ�����
	fclose(fp);
	read2(x);
	//a = getchar();
	return l+1;
}
int read2(int x)
{
	int j;
	//float remain(int x);
	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}
	printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
	for (j = 0; j<x//���º���������ʾ��������
		; j++)
	{
		fread(&example[j], sizeof(CON), 1, fp);

		printf("%4d   %-5s%-8s%-80s%5.1f    %-80s", example[j].num, example[j].io, example[j].name, example[j].reason, example[j].figure, example[j].remark);
		putchar('\n');
	}
	fclose(fp);
	return 0;
}