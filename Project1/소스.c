#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include<conio.h>
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
//수입,지출,잔액 다른 파일

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
		printf("가계부 파일생성\n");

	printf("현재 자산 입력: ");
	if (!(scanf("%d", &money))) {
		printf("올바른 값 입력해라\n");
		exit(1);
	}
	fprintf(balance_file, "처음 잔액:%d \n", money);

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
					printf("다시 입력하시오.\n");
			}
			break;
		case 7:
			program_exit();
			break;

		default:
			printf("잘못된 값 입력됨");
			clear();
			break;

		}
	}
}
int date() {
	int Date;
	printf("날짜를 입력하시오 (예)20190423 ");
	scanf("%d", &Date);
	return Date;
}
void clear() {

	printf("*********************************************\n");
	printf("아무키나 누르면 화면을 초기화 합니다.");
	getch();
	system("cls");
}

void program_exit() {
	exit(1);
}
FILE * search_file() {
	char readfile[50];
	FILE *fp = NULL;

	printf("날짜를 입력하시오(제목에 .txt 붙이기 예>0520.txt) : ");

	fscanf(stdin, "%s", readfile);
	fflush(stdin);

	fp = fopen(readfile, "a");
	return fp;
	
}

void print_money(int money, FILE* bal_file, FILE *date) {

	if (bal_file != NULL) {
		fprintf(bal_file, "잔액 :%d\n", money);
		fprintf(date, "잔액 :%d\n", money);
	}
	printf("현재 잔액은 %d입니다\n", money);
}

int export_money(int money, FILE* ex_file, FILE *date) {
	int export;
	int num;
	if (ex_file != NULL) {
		printf("사용한 곳을 입력하세요 \n");
		printf("=================================");
		printf("1.음식 2. 문화 생활 3. 몰라");
		printf("=================================");

		while (1) {
			scanf("%d", &num);
			if (num < 0 || num >= 4)
				printf("잘 못 입력하셨습니다. 다시 입력해주세요.");
			else {
				printf("지출된 돈을 입력하세요 >>");
				scanf("%d", &export);
				fprintf(ex_file, "지출 : %d\n", export);
				fprintf(ex_file, "사용 : %d\n", num);
				fprintf(date, "지출 :%d\n", export);
				fprintf(date, "사용 : %d\n", num);
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
		printf("들어온 돈을 입력하세요 >>");
		scanf("%d", &income);
		money += income;
		fprintf(in_file, "수입 : %d\n", income);
		fprintf(date, "수입 : %d\n", income);
	}
	return money;
}

int intro() {

	int num;

	puts("*********************************************");
	puts("*        가계부 관리 프로그램 v0.1         *");
	puts("*********************************************");
	puts("* 1. 날 짜             *");
	puts("* 2.  수  입           *");
	puts("* 3.  지  츨           *");
	puts("* 4.  잔액조회         *");
	puts("* 5.  음식 추천 받기   *");
	puts("* 6.  경  고           *");
	puts("* 7.  종  료           *");
	
	puts("*********************************************");
	printf("Input >>");
	if (!(scanf("%d", &num))) {
		printf("올바른 값을 입력하세요\n");
		exit(1);
	}
	return num;
}
void korea_food1()
{
	FILE *korea_food;
	char *food = (char*)malloc(sizeof(char));
	char read_food[30];

	printf("식비가 6000원 이하인 한식을 추천합니다.\n");
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

	printf("식비가 6000원~9000원인 한식을 추천합니다.\n");
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

	printf("식비가 9000원 이상인 한식을 추천합니다.\n ");
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

	printf("식비가 6000원 이하인 일식을 추천합니다.\n");
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

	printf("식비가 6000원~9000원인 일식을 추천합니다.\n");
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

	printf("식비가 9000원 이상인 일식을 추천합니다.\n ");
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

	printf("식비가 6000원 이하인 중식을 추천합니다.\n");
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

	printf("식비가 6000원~9000원인 중식을 추천합니다.\n");
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

	printf("식비가 9000원 이상인 중식을 추천합니다.\n ");
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

	printf("식비가 6000원 이하인 양식을 추천합니다.\n");
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

	printf("식비가 6000원~9000원인 양식을 추천합니다.\n");
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

	printf("식비가 9000원 이상인 양식을 추천합니다.\n ");
	america_food = fopen("america_food3.txt", "r");
	while (fscanf(america_food, "%s", read_food) != EOF)
		printf("%s\n", read_food);

	fclose(america_food);
}

void food_title()
{
	printf(" 1. 한식\n 2. 일식\n 3. 중식\n 4. 양식\n");

}

void money_title()
{
	printf("1. 6000원 이하\n");
	printf("2. 6000원~9000원\n");
	printf("3. 9000원 이상\n");
}

void choose_food()
{
	int  select_menu, select_money;
	money_title();
	printf("가격을 선택하시오.\n");
	scanf("%d", &select_money);
	food_title();
	printf("음식의 종류를 선택하시오.\n");
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
	printf("지출의 정도를 정하시오.\n");
	printf("1. 지출/수입 : 30%이하\n");
	printf("2. 지출/수입 : 30%~70%\n");
	printf("3. 지출 수입 : 70%이상\n");
}

void setting_title()
{
	printf("1. 경고 메세지 설정\n");
	printf("2. 다른 메뉴 선택하기\n");
}


/*함수 선언*/
void open_file(FILE *warning);
void new_warning(FILE *message);

/*파일 읽는 함수모음*/
void open_file(FILE *warning)
{
	char read_message[30];
	char *dm = (char*)malloc(sizeof(char));

	while (fscanf(warning, "%s", read_message) != EOF)
	{
		printf("-이전 경고메세지-\n");
		printf("%s\n", read_message);
	}

	if (warning == NULL)
	{
		printf("이전 경고 메세지가 없습니다. 새로운 경고 메세지를 입력하시오.\n");
		new_warning(warning);
		return;
	}

	printf("새로운 경고메세지를 입력하시오.\n");
	new_warning(warning);
	fclose(warning);
}

void new_warning(FILE *message)
{
	char *warning_dm = (char*)malloc(sizeof(char));

	printf("새로운 경고 메세지를 입력합니다. \n");
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