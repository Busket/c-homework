#include<stdio.h>
//#include"��ͷ.h"
//#include"add.c"
//#include"browse.c"
char k;
int main()
{
	char b;
	void add();
	void browse(); 
	void choice();
	void refer();
	void amend();
	void rank();

	do
	{
	choice();
	printf("�Ƿ���Ҫ��������(y/n)\n");
	scanf("%c", &b);
	k = getchar();
	} while (b!='n');

	putchar('\n');
	printf("��лʹ�ã�\n");
	return 0;
}
void choice()
{
		char a;
		printf("****************************\n");
		printf("����һ������༶��֧�ĳ���      ���ݴ��ʲ��ߣ������ʹ�ã���\n");
		printf("****************************\n");
		putchar(10);
		printf("��ѡ��������Ҫ�ķ���\n");
		printf("1.��Ӱ����֧��Ϣ��\n2.������а����֧��Ϣ��\n3.��ѯ�����֧��Ϣ��\n");
		printf("4.�޸İ����֧��Ϣ��\n5.��ָ���ֶ����������\n");
		putchar(10);
		scanf("%c", &a);
		k = getchar();
		switch (a)
		{
		case '1':add(); break;//�����Ϣ
		case '2':browse(); break;//���
		case '3':refer(); break;//��ѯ
		case '4':amend(); break;//�޸�
		case '5':rank(); break;
		}
}