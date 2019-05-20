#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include<conio.h>
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
//����,����,�ܾ� �ٸ� ����

int date();
int intro();
FILE * search_file();
int income_money(int money, FILE *in_file, FILE *date);
int export_money(int money, FILE *ex_file, FILE *date);
void print_money(int money, FILE* bal_file, FILE *date);
void program_exit();
void clear();


void open_file(FILE *warning);
void new_warning(FILE *message);
void setting();
void setting_limit();
void setting_title();


void korea_food1();
void korea_food2();
void korea_food3();
void japan_food1();
void japan_food2();
void japan_food3();
void china_food1();
void china_food2();
void china_food3();
void america_food1();
void america_food2();
void america_food3();
void food_title();
void choose_food();

void main() {
	int menu = 0;
	int money = 0, sel;
	FILE *date = NULL;
	FILE *income_file;
	FILE *export_file;
	FILE *balance_file;

	income_file = fopen("income.txt", "a+");
	export_file = fopen("export.txt", "a+");
	balance_file = fopen("balance.txt", "a+");

	if (balance_file)
		printf("����� ���ϻ���\n");

	printf("���� �ڻ� �Է�: ");
	if (!(scanf("%d", &money))) {
		printf("�ùٸ� �� �Է��ض�\n");
		exit(1);
	}
	fprintf(balance_file, "ó�� �ܾ�:%d \n", money);

	while (1) {
		sel = intro();

		switch (sel) {

		case 1:
			date = search_file();
			break;

		case 2:
			money = income_money(money, income_file,date);
			clear();
			break;

		case 3:
			money = export_money(money, export_file,date);
			clear();
			break;

		case 4:
			print_money(money, balance_file,date);
			clear();
			break;

		case 5:
			choose_food();
			break;

		case 6:
			while (menu != 3)
			{
				setting_title();
				scanf("%d", &menu);
				if (menu == 1)
					setting();
				else if (menu == 2)
					break;
				else
					printf("�ٽ� �Է��Ͻÿ�.\n");
			}
			break;
		case 7:
			program_exit();
			break;

		default:
			printf("�߸��� �� �Էµ�");
			clear();
			break;

		}
	}
}
int date() {
	int Date;
	printf("��¥�� �Է��Ͻÿ� (��)20190423 ");
	scanf("%d", &Date);
	return Date;
}
void clear() {

	printf("*********************************************\n");
	printf("�ƹ�Ű�� ������ ȭ���� �ʱ�ȭ �մϴ�.");
	getch();
	system("cls");
}

void program_exit() {
	exit(1);
}
FILE * search_file() {
	char readfile[50];
	FILE *fp = NULL;

	printf("��¥�� �Է��Ͻÿ�(���� .txt ���̱� ��>0520.txt) : ");

	fscanf(stdin, "%s", readfile);
	fflush(stdin);

	fp = fopen(readfile, "a");
	return fp;
	
}

void print_money(int money, FILE* bal_file, FILE *date) {

	if (bal_file != NULL) {
		fprintf(bal_file, "�ܾ� :%d\n", money);
		fprintf(date, "�ܾ� :%d\n", money);
	}
	printf("���� �ܾ��� %d�Դϴ�\n", money);
}

int export_money(int money, FILE* ex_file, FILE *date) {
	int export;
	int num;
	if (ex_file != NULL) {
		printf("����� ���� �Է��ϼ��� \n");
		printf("=================================");
		printf("1.���� 2. ��ȭ ��Ȱ 3. ����");
		printf("=================================");

		while (1) {
			scanf("%d", &num);
			if (num < 0 || num >= 4)
				printf("�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
			else {
				printf("����� ���� �Է��ϼ��� >>");
				scanf("%d", &export);
				fprintf(ex_file, "���� : %d\n", export);
				fprintf(ex_file, "��� : %d\n", num);
				fprintf(date, "���� :%d\n", export);
				fprintf(date, "��� : %d\n", num);
				money -= export;
				break;
			}
			
		}
	}
	return money;
}

int income_money(int money, FILE* in_file, FILE *date) {
	int income;
	if (in_file != NULL) {
		printf("���� ���� �Է��ϼ��� >>");
		scanf("%d", &income);
		money += income;
		fprintf(in_file, "���� : %d\n", income);
		fprintf(date, "���� : %d\n", income);
	}
	return money;
}

int intro() {

	int num;

	puts("*********************************************");
	puts("*        ����� ���� ���α׷� v0.1         *");
	puts("*********************************************");
	puts("* 1. �� ¥             *");
	puts("* 2.  ��  ��           *");
	puts("* 3.  ��  ��           *");
	puts("* 4.  �ܾ���ȸ         *");
	puts("* 5.  ���� ��õ �ޱ�   *");
	puts("* 6.  ��  ��           *");
	puts("* 7.  ��  ��           *");
	
	puts("*********************************************");
	printf("Input >>");
	if (!(scanf("%d", &num))) {
		printf("�ùٸ� ���� �Է��ϼ���\n");
		exit(1);
	}
	return num;
}
void korea_food1()
{
	FILE *korea_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000�� ������ �ѽ��� ��õ�մϴ�.\n");
	korea_food = fopen("korea_food1.txt", "r");
	while (fscanf(korea_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);
	fclose(korea_food);
}

void korea_food2()
{
	FILE *korea_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000��~9000���� �ѽ��� ��õ�մϴ�.\n");
	korea_food = fopen("korea_food2.txt", "r");
	while (fscanf(korea_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(korea_food);
}

void korea_food3()
{
	FILE *korea_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 9000�� �̻��� �ѽ��� ��õ�մϴ�.\n ");
	korea_food = fopen("korea_food3.txt", "r");
	while (fscanf(korea_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(korea_food);
}

void japan_food1()
{
	FILE *japan_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000�� ������ �Ͻ��� ��õ�մϴ�.\n");
	japan_food = fopen("japan_food1.txt", "r");
	while (fscanf(japan_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(japan_food);
}

void japan_food2()
{
	FILE *japan_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000��~9000���� �Ͻ��� ��õ�մϴ�.\n");
	japan_food = fopen("japan_food2.txt", "r");
	while (fscanf(japan_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(japan_food);
}

void japan_food3()
{
	FILE *japan_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 9000�� �̻��� �Ͻ��� ��õ�մϴ�.\n ");
	japan_food = fopen("japan_food3.txt", "r");
	while (fscanf(japan_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(japan_food);
}

void china_food1()
{
	FILE *china_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000�� ������ �߽��� ��õ�մϴ�.\n");
	china_food = fopen("china_food1.txt", "r");
	while (fscanf(china_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(china_food);
}

void china_food2()
{
	FILE *china_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000��~9000���� �߽��� ��õ�մϴ�.\n");
	china_food = fopen("china_food2.txt", "r");
	while (fscanf(china_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(china_food);
}

void china_food3()
{
	FILE *china_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 9000�� �̻��� �߽��� ��õ�մϴ�.\n ");
	china_food = fopen("china_food3.txt", "r");
	while (fscanf(china_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(china_food);
}

void america_food1()
{
	FILE *america_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000�� ������ ����� ��õ�մϴ�.\n");
	america_food = fopen("america_food1.txt", "r");
	while (fscanf(america_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(america_food);
}

void america_food2()
{
	FILE *america_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 6000��~9000���� ����� ��õ�մϴ�.\n");
	america_food = fopen("america_food2.txt", "r");
	while (fscanf(america_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(america_food);
}

void america_food3()
{
	FILE *america_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("�ĺ� 9000�� �̻��� ����� ��õ�մϴ�.\n ");
	america_food = fopen("america_food3.txt", "r");
	while (fscanf(america_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(america_food);
}

void food_title()
{
	printf(" 1. �ѽ�\n 2. �Ͻ�\n 3. �߽�\n 4. ���\n");

}

void money_title()
{
	printf("1. 6000�� ����\n");
	printf("2. 6000��~9000��\n");
	printf("3. 9000�� �̻�\n");
}

void choose_food()
{
	int  select_menu, select_money;
	money_title();
	printf("������ �����Ͻÿ�.\n");
	scanf("%d", &select_money);
	food_title();
	printf("������ ������ �����Ͻÿ�.\n");
	scanf("%d", &select_menu);

	if (select_money == 1)
	{
		switch (select_menu)
		{
		case 1: korea_food1();
			break;
		case 2:
			japan_food1();
			break;
		case 3:
			china_food1();
			break;
		case 4:
			america_food1();
			break;
		}
	}
	if (select_money == 2)
	{
		switch (select_menu)
		{
		case 1:
			korea_food2();
			break;
		case 2:
			japan_food2();
			break;
		case 3:
			china_food2();
			break;
		case 4:
			america_food2();
			break;
		}
	}
	if (select_money == 3)
	{
		switch (select_menu)
		{
		case 1:
			korea_food3();
			break;
		case 2:
			japan_food3();
			break;
		case 3:
			china_food3();
			break;
		case 4:
			america_food3();
			break;
		}
	}
}
void setting_limit()
{
	printf("������ ������ ���Ͻÿ�.\n");
	printf("1. ����/���� : 30%����\n");
	printf("2. ����/���� : 30%~70%\n");
	printf("3. ���� ���� : 70%�̻�\n");
}

void setting_title()
{
	printf("1. ��� �޼��� ����\n");
	printf("2. �ٸ� �޴� �����ϱ�\n");
}


/*�Լ� ����*/
void open_file(FILE *warning);
void new_warning(FILE *message);

/*���� �д� �Լ�����*/
void open_file(FILE *warning)
{
	char read_message[30];
	char *dm = (char*)malloc(sizeof(char));

	while (fscanf(warning, "%s", read_message) != EOF)
	{
		printf("-���� ���޼���-\n");
		printf("%s\n", read_message);
	}

	if (warning == NULL)
	{
		printf("���� ��� �޼����� �����ϴ�. ���ο� ��� �޼����� �Է��Ͻÿ�.\n");
		new_warning(warning);
		return;
	}

	printf("���ο� ���޼����� �Է��Ͻÿ�.\n");
	new_warning(warning);
	fclose(warning);
}

void new_warning(FILE *message)
{
	char *warning_dm = (char*)malloc(sizeof(char));

	printf("���ο� ��� �޼����� �Է��մϴ�. \n");
	scanf("%s", warning_dm);
	fputs(warning_dm, message);

	fclose(message);
}

void setting()
{
	FILE *warning;
	int limit = 0;

	setting_limit();
	scanf("%d", &limit);
	switch (limit)
	{
	case 1:
		warning = fopen("warning1.txt", "r");
		open_file(warning);
		break;
	case 2:
		warning = fopen("warning2.txt", "r");
		open_file(warning);
		break;
	case 3:
		warning = fopen("warning3.txt", "r");
		open_file(warning);
		break;
	}
}