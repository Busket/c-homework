#pragma once
/*#include"main.c"
#include"add.c"
#include"browse.c"*/
#define N 80
typedef struct class_fee
{
	int num;//编号          4个字节
	char io[4];//收入/支出  4个字节
	char name[8];//经手人   8个字节
	char reason[40];//原因  40~
	float figure;//金额     4~
	char remark[40];//备注  40~
}CON;
CON example[N], ran[N];