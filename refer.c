#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
FILE *fp;
int j,t;
char k,b;//k�����ռ�\n
void refer()
{
	void man();
	void reason();
	void figure();
	void remark();
	char a,b;
	int i, n;

	if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb")) == NULL)//���ļ�
	{
		printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
		exit(0);
	}

	for (i = 0; (fread(&example[i], sizeof(CON), 1, fp)) == 1; i++)//��ȡ������ʱ�����ѭ������δ��ȡ�����˳�ѭ��
	{
		fread(&example[i], sizeof(CON), 1, fp);
		//printf("%d", example[i].num);
		n = example[i].num;//n��i�����ֵ���͵�������
	}
	example[n - 1].num = n;//����ȷ�����
	fclose(fp);
	do
	{
		printf("��ѡ��������Ҫ�������ֶΣ�\n");
		printf("1.�����ˡ�\n2.ԭ��\n3.��\n4.��ע��\n");
		a = getchar();
		//k = getchar();
		switch (a)
		{
		case '1':man(n); break;//�ؼ��ʣ�������
		case'2':reason(n); break;//�ؼ��ʣ�ԭ��
		case'3':figure(n); break;//�ؼ��ʣ����
		case'4':remark(n); break;//�ؼ��ʣ���ע
		}
		printf("���Ƿ���Ҫѡ�������ֶ�������(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}
void man(int n)
{
	char a[8];
	do
	{
		printf("����������Ҫ�Ѳ�ľ����ˣ���ȷ��������");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb+")) == NULL)//���ļ�
		{
			printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
			exit(0);
		}
		printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
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
			if (t == 0) printf("û���ѵ�����Ҫ�ģ�\n");
			fclose(fp);
			printf("���Ƿ���Ҫ�͵�ǰ�ֶ�����������(y/n)\n");
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
		printf("����������Ҫ�Ѳ��ԭ��");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb+")) == NULL)//���ļ�
		{
			printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
			exit(0);
		}
		printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
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
		if (t == 0) { putchar(10); printf("û���ѵ�����Ҫ�ģ�\n"); }
		fclose(fp);
		printf("���Ƿ���Ҫ�͵�ǰ�ؼ��ֶ�����������(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}
void figure(int n)
{
	float a;
	do
	{
		printf("����������Ҫ�Ѳ�Ľ���ȷ��������");
		scanf("%f",&a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb+")) == NULL)//���ļ�
		{
			printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
			exit(0);
		}
		printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
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
			printf("û���ѵ�����Ҫ�ģ�\n"); putchar(10);
		}
		fclose(fp);
		printf("���Ƿ���Ҫ�͵�ǰ�ֶ�����������(y/n)\n");
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
		printf("����������Ҫ�Ѳ�ı�ע��");
		scanf("%s", a);
		k = getchar();
		if ((fp = fopen("C:\\Users\\www\\Desktop\\C���Գ�����ƴ���ҵ\\c���Դ���ҵ\\c���Դ���ҵ\\topfile.dat", "rb+")) == NULL)//���ļ�
		{
			printf("Can not open this file\n");//��ʧ�ܣ�����ʾ���
			exit(0);
		}
		printf("��� ��/֧  ������  ԭ��                                                                              ���   ��ע\n");
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
		if (t == 0) { putchar(10); printf("û���ѵ�����Ҫ�ģ�\n"); }
		fclose(fp);
		printf("���Ƿ���Ҫ�͵�ǰ�ؼ��ֶ�����������(y/n)\n");
		scanf("%c", &b);
		k = getchar();
	} while (b != 'n');
}