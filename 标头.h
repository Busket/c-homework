#pragma once
/*#include"main.c"
#include"add.c"
#include"browse.c"*/
#define N 80
typedef struct class_fee
{
	int num;//���          4���ֽ�
	char io[4];//����/֧��  4���ֽ�
	char name[8];//������   8���ֽ�
	char reason[40];//ԭ��  40~
	float figure;//���     4~
	char remark[40];//��ע  40~
}CON;
CON example[N], ran[N];