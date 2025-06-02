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
int cp = 0, feelings = 3 , lastproduceCP;
int hasMouse = 0, hasPoiter = 0, hasScrater = 0, hasTower = 0;
int homeStayTurn = 0, countTurn = 0;
char catName[16] = { 0 };

void behavior();
void produce_CP();
void intro();
void showState();
void feel();
void drewRoom();
int rollDice();
void doInteraction();
void makeSuop();
void moveCat();
void shop();
void min_game();

int main() {
	srand((unsigned int)time(NULL));
	intro();
	Sleep(1000);
	system("cls");
	while (1) {
		countTurn++;
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
		produce_CP();
		shop();
		Sleep(2000);
		system("cls"); 
		if (countTurn % 3 == 0) {
			min_game();
			Sleep(2000);
			system("cls");
		}
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
	printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", catName, lastproduceCP);
	printf("CP: %d ����Ʈ\n",cp);
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
		else if (i == CAT_TOWER)
			printf("T");
		else if (i == SCRATCHER)
			printf("S");
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
		if (hasMouse == 1) printf("2.�峭�� ��� ����ֱ�\n");
		if (hasPoiter == 1) printf("3.������ ����Ʈ�� ����ֱ�\n");
		printf(">>");
		scanf_s("%d", &choice);
		if (choice == 0) {
			feelings--;
			printf("�ƹ��͵� �����ʽ��ϴ�.\n");
			printf("%s�� ����� ���������ϴ�: %d -> %d",catName,feelings+1,feelings);
			printf("�ֻ����� ���� 5�����̸� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice = rollDice();
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice <= 5 && Intimacy > 0) {
				Intimacy--;
				printf("������� ���谡 �������ϴ�.\n");
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
			}
			break;
		}
		else if (choice == 1) {
			printf("%s�� ���ٵ�� �־����ϴ�.\n", catName);
			printf("%s�� ����� �״�� �Դϴ� : %d\n", catName, feelings);
			printf("�ֻ����� ���� 5�̻��̸� ģ�е��� �ö󰩴ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
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
		else if(choice == 2){
			printf("�峭�� ��� %s�� ����־����ϴ�.\n",catName);
			feelings++;
			printf("%s�� ����� ���� ���������ϴ� : %d -> %d\n", catName, feelings -1, feelings);
			printf("�ֻ����� ���� 4�̻��̸� ģ�е��� �ö󰩴ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice = rollDice();
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice >= 4 && Intimacy < 4) {
				Intimacy++;
				printf("ģ�е��� �������ϴ�.\n");
			}
			else {
				printf("ģ�е��� �״���Դϴ�.\n");
			}
			break;
		}
		else if (choice == 3) {
			printf("������ �����ͷ� %s�� ����־����ϴ�.\n", catName);
			feelings += 2;
			printf("%s�� ����� �� ���������ϴ� : %d -> %d\n", catName, feelings - 2, feelings);
			printf("�ֻ����� ���� 2�̻��̸� ģ�е��� �ö󰩴ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			int dice = rollDice();
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice >= 2 && Intimacy < 4) {
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

void behavior() {
	if (yaongPos == HME_POS) {
		homeStayTurn++;
		if (homeStayTurn >= 1) {
			feelings++;
			homeStayTurn = 0;
		}
	}
	else {
		homeStayTurn = 0;
		if (yaongPos == SCRATCHER) feelings++;
		else if (yaongPos == CAT_TOWER) feelings += 2;

	}

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

void produce_CP() {
	int produceCP = (feelings > 0) ? feelings - 1 + Intimacy : 0;
	lastproduceCP = produceCP;
	cp += produceCP;
}

void shop() {
	int choice;
	//���� �Ǵ� ���� ���� ���� �ǵ��� �ؾߵ� �ٵ� �� �ȵǤӤ�
	//int hasMouse = 0, hasPoiter = 0 , hasScrater = 0, hasTower = 0;
	printf("�������� ������ �� �� �ֽ��ϴ�.\n");
	printf("� ������ �����ұ��?\n");
	//printf("���� CP ����Ʈ %d\n", cp);
	printf("0. �ƹ��͵� ���� �ʴ´�.\n");
	printf("1. �峭�� �� : 1CP %s\n ",hasMouse ? "(ǰ��)" : "");
	printf("2. ������ ������: 2CP %s\n",hasPoiter ? "(ǰ��)" : "");
	printf("3. ��ũ��ó: 4CP %s \n",hasScrater ? "(ǰ��)" : "");
	printf("4. Ĺ Ÿ��: 6CP %s\n",hasTower ? "(ǰ��)" : "");
	printf(">>");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 0:
		break;
	case 1:
		if (hasMouse) {
			printf("�̹� �峭�� �㸦 �����Ͽ����ϴ�.\n");
		}
		else if (cp < 1) {
			printf("CP�� �����մϴ�.\n");
		}
		else {
			cp -= 1;
			hasMouse = 1;
			printf("�峭�� �㸦 ������. ���� CP: %d\n", cp);
		}
		break;
	case 2:
		if (hasPoiter) {
			printf("�̹� ������ �����͸� �����ϼ̽��ϴ�.\n");
		}
		else if (cp < 2) {
			printf("CP�� �����մϴ�.\n");
		}
		else {
			cp -= 2;
			hasPoiter = 1;
			printf("������ �����͸� ������.���� CP : % d\n", cp);
		}

		break;
	case 3:
		if (hasScrater) {
			printf("�̹� ��ũ��ó�� �����ϼ̽��ϴ�.\n");
		}
		else if (cp < 4) {
			printf("CP�� �����մϴ�.\n");
		}
		else {
			cp -= 4;
			hasScrater = 1;
			printf("��ũ���ĸ� ������.���� CP : % d\n", cp);
		}
		break;
	case 4:
		if (hasTower) {
			printf("�̹� ��ũ��ó�� �����ϼ̽��ϴ�.\n");
		}
		else if (cp < 6) {
			printf("CP�� �����մϴ�.\n");
		}
		else {
			cp -= 6;
			hasTower = 1;
			printf("ĹŸ���� ������.���� CP : % d\n", cp);
		}
		break;
	default:
		printf("�߸��� �Է��Դϴ�.\n");
	}
}

void min_game() {
	int num1, num2, answer, userInput;

	printf("==========================\n");
	printf("���� �̴� ����.\n");
	printf("�� ������ ���� ���纸����!\n");
	printf("==========================\n");

	num1 = rand() % 10 + 1; // 1���� 10������ ���� ����
	num2 = rand() % 10 + 1; 
	answer = num1 * num2;

	printf("%d x %d = ?\n", num1, num2);
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &userInput);
	if (userInput == answer) {
		printf("�����Դϴ�! %d x %d = %d\n", num1, num2, answer);
		feelings++;
		printf("������� ����� 1 ���� ���ϴ� %d -> %d", feelings - 1, feelings);
	} else {
		printf("Ʋ�Ƚ��ϴ�. ������ %d�Դϴ�.\n", answer);
	}

}