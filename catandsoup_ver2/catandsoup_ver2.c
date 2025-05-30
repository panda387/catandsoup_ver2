#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int Intimacy = 2, soup = 0, yaongPos = HME_POS, prvCatPos = HME_POS;
char catName[16] = { 0 };

void intro();
void showState();
void drewRoom();
int rollDice();
void doInteraction();
void makeSuop();
void moveCat();

int main() {
	srand((unsigned int)time(NULL));
	intro();
	Sleep(1000);
	system("cls");
	while (1) {
		showState();
		drewRoom();
		doInteraction();
		Sleep(500);
		moveCat();
		Sleep(500);
		makeSuop();
		Sleep(2500);
		system("cls");
	}

	return 0;
}

void intro() {
	printf("****�߿��̿� ����****\n\n");
	printf(" /\\_/\\ \n");
	printf("( o.o )\n");
	printf(" > ^ < \n");
	printf("�߿����� �̸��� ���� �ּ���:");
	scanf_s("%s", catName, 16);
	printf("�߿����� �̸��� %s�Դϴ�.\n", catName);
}

void showState() {
	printf("=========���� ����=========\n");
	printf("������� ���� ����: %d��\n", soup);
	printf("������� ����(0~4): %d\n", Intimacy);
	if (Intimacy == 0) {
		printf("���縦 �����մϴ�.\n");
	}
	else if (Intimacy == 1) {
		printf("���� ���Ǳ�����Դϴ�.\n");
	}
	else if (Intimacy == 2) {
		printf("������ �����Դϴ�.\n");
	}
	else if (Intimacy == 3) {
		printf("���縦 �����մϴ�.\n");
	}
	else if (Intimacy == 4) {
		printf("�ְ��� �����Դϴ�.\n");
	}
	printf("==========================\n\n");
}
void drewRoom() {
	//�����׸���
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n");

	//Ȩ�� ���� �׸���
	//printf("#");
	for (int i = 0; i < ROOM_WIDTH; i++) {
		if (i == HME_POS)
			printf("H");
		else if (i == BWL_POS)
			printf("B");
		else if (i == 0)
			printf("#");
		else if (i == ROOM_WIDTH - 1)
			printf("#");
		else  printf(" ");
	}
	//printf("#\n");
	printf("\n");
	//�������ġ �׸���
	//printf("#");
	for (int i = 0; i < ROOM_WIDTH; i++) {
		if (i == yaongPos) printf("C");
		else if (i == prvCatPos) printf(".");
		else if (i == 0)
			printf("#");
		else if (i == ROOM_WIDTH - 1)
			printf("#");
		else printf(" ");
	}
	printf("\n");

	//�Ʒ� ���׸���
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n\n");
}

int rollDice() {
	return rand() % 6 + 1;
}

void doInteraction() {
	int choice;
	while (1) {
		printf("� ��ȣ�ۿ��� �Ͻ� �ڽ��ϱ�?\n");
		printf("0.�ƹ��͵� ��������.\n");
		printf("1.���ٵ��.\n");
		printf(">>");
		scanf_s("%d", &choice);
		if (choice == 0) {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice = rollDice();
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice <= 4 && Intimacy > 0) {
				Intimacy--;
				printf("ģ�е��� �������ϴ�.\n");
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
			}
			break;
		}
		else if (choice == 1) {
			printf("%s�� ���ٵ�� �־����ϴ�.\n", catName);
			printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice = rollDice();
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice >= 5 && Intimacy < 4) {
				Intimacy++;
				printf("ģ�е��� �������ϴ�.\n");
			}
			else {
				printf("ģ�е��� �״���Դϴ�.\n");
			}
			break;
		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
		}
	}
}
void moveCat() {
	printf("%s�̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", catName);
	printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", 6 - Intimacy);
	printf("�ֻ����� �����ϴ�. �Ǹ���...");
	int dice = rollDice();
	printf("%d�� ���Խ��ϴ�!", dice);
	int direction = (dice >= 6 - Intimacy) ? 1 : -1;
	int newpos = yaongPos + direction;

	prvCatPos = yaongPos;

	if (newpos > 0 && newpos < ROOM_WIDTH - 1)
		yaongPos = newpos;
	printf("%s������ �����Դϴ�\n", (direction == 1 ? "����" : "��"));
}
void makeSuop() {
	if (yaongPos == BWL_POS) {
		soup++;
		int randsoup = rand() % 3;
		if (randsoup == 0) {
			printf("%s�̰� ���ڼ����� ��������ϴ�\n", catName);
		}
		else if (randsoup == 1) {
			printf("%s�̰� ����� ������ ��������ϴ�\n", catName);
		}
		else if (randsoup == 2) {
			printf("%s�̰� ����ݸ� ������ ��������ϴ�\n", catName);
		}
		printf("������� ���� ����: %d\n", soup);
	}
	if (yaongPos == HME_POS) printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", catName);

}
