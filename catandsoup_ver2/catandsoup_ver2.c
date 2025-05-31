#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 15
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define CAT_TOWER 5
#define SCRATCHER 10

int Intimacy = 2, soup = 0, yaongPos = HME_POS, prvCatPos = HME_POS;
int cp = 0, feelings = 3;
char catName[16] = { 0 };

void intro();
void showState();
void feel();
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
		feel();
		Sleep(1000);
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
	//cp ����Ʈ
	printf("CP: %d ����Ʈ\n", cp);
	//���
	printf("%s�� ���(0 ~ 3): %d\n", catName, feelings);
	if (feelings == 0) {
		printf("����� �ſ� ���޴ϴ�.\n");
	}
	else if (feelings == 1) {
		printf("������ �մϴ�.\n");
	}
	else if (feelings == 2) {
		printf("�Ļ��� �����ϴ�.\n");
	}
	else if (feelings == 3) {
		printf("������ �θ��ϴ�.\n");
	}
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
		/*else if (i == CAT_TOWER)
			printf("T");
		else if (i == SCRATCHER)
			printf("S");*/
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

void feel() {
	int dice = rollDice();
	printf("�ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", 6 - Intimacy);
	printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
	printf("%d�� ���Խ��ϴ�\n", dice);
	if (dice < 6 - Intimacy && feelings > 0) {
		feelings--;
		printf("%s�� ����� �������ϴ�: %d -> %d\n", catName, feelings + 1, feelings);
	}
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

//�� �� �ȵ� ��¥ ���� �Τä��������Ť���
void moveCat() {
	prvCatPos = yaongPos; // ���� ��ġ ����

	
	// ��� �̳� ����
	if (feelings == 3) {
		if (yaongPos < BWL_POS) yaongPos++;
	}
	//�׳� �׷���
	else if (feelings == 2) {
		printf("%s�̴� ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n", catName);
	}
	//�� ��ƴ�
	else if (feelings == 1) {
		//���� �ⱸ�� ���� ��� ����� ���߿� 
		int hasTower = (CAT_TOWER > 0 && CAT_TOWER < ROOM_WIDTH - 1);
		int hasScratcher = (SCRATCHER > 0 && SCRATCHER < ROOM_WIDTH - 1);
		if (!hasTower && !hasScratcher) {
			printf("�濡 ���� �ⱸ�� ���� %s�� ����� �� �������ϴ�.\n", catName);
			if (feelings > 0) feelings--;
		}
		// �ű� ��� �������� �غ���
		int distTower = abs(yaongPos - CAT_TOWER);
		int distScratcher = abs(yaongPos - SCRATCHER);
		int target;
		if (distTower < distScratcher) target = CAT_TOWER; 
		else if (distScratcher < distTower) target = SCRATCHER;
		else target = (CAT_TOWER < SCRATCHER) ? CAT_TOWER : SCRATCHER; // �� �� ������ �� ����

		if (yaongPos < target) yaongPos++;
		else if (yaongPos > target) yaongPos--;
	}
	// ����� �ſ� ���ڸ� ��������
	else if (feelings == 0) {
		if (yaongPos > HME_POS) yaongPos--;
		printf("����� �ſ� ���� %s�̴� ������ ���ϴ�.\n", catName);
	}

	//�� ������ �ȳ��� �ϱ�
	if (yaongPos < 1) yaongPos = 1;
	if (yaongPos > ROOM_WIDTH - 2) yaongPos = ROOM_WIDTH - 2;
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
