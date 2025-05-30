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
	printf("****야옹이와 수프****\n\n");
	printf(" /\\_/\\ \n");
	printf("( o.o )\n");
	printf(" > ^ < \n");
	printf("야옹이의 이름을 지어 주세요:");
	scanf_s("%s", catName, 16);
	printf("야옹이의 이름은 %s입니다.\n", catName);
}

void showState() {
	printf("=========현재 상태=========\n");
	printf("현재까지 만든 수프: %d개\n", soup);
	printf("집사와의 관계(0~4): %d\n", Intimacy);
	if (Intimacy == 0) {
		printf("집사를 혐오합니다.\n");
	}
	else if (Intimacy == 1) {
		printf("간식 자판기취급입니다.\n");
	}
	else if (Intimacy == 2) {
		printf("쓸만한 집사입니다.\n");
	}
	else if (Intimacy == 3) {
		printf("집사를 좋아합니다.\n");
	}
	else if (Intimacy == 4) {
		printf("최고의 집사입니다.\n");
	}
	printf("==========================\n\n");
}
void drewRoom() {
	//윗벽그리기
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n");

	//홈과 냄비 그리기
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
	//고양이위치 그리기
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

	//아래 벽그리기
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
		printf("어떤 상호작용을 하시 겠습니까?\n");
		printf("0.아무것도 하지않음.\n");
		printf("1.쓰다듬기.\n");
		printf(">>");
		scanf_s("%d", &choice);
		if (choice == 0) {
			printf("아무것도 하지 않습니다.\n");
			printf("4/6의 확률로 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
			int dice = rollDice();
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice <= 4 && Intimacy > 0) {
				Intimacy--;
				printf("친밀도가 떨어집니다.\n");
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			}
			break;
		}
		else if (choice == 1) {
			printf("%s의 쓰다듬어 주었습니다.\n", catName);
			printf("2/6의 확률로 친밀도가 높아집니다.\n주사위를 굴립니다. 또르륵...\n");
			int dice = rollDice();
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice >= 5 && Intimacy < 4) {
				Intimacy++;
				printf("친밀도가 높아집니다.\n");
			}
			else {
				printf("친밀도는 그대로입니다.\n");
			}
			break;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
		}
	}
}
void moveCat() {
	printf("%s이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", catName);
	printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", 6 - Intimacy);
	printf("주사위를 굴립니다. 또르륵...");
	int dice = rollDice();
	printf("%d가 나왔습니다!", dice);
	int direction = (dice >= 6 - Intimacy) ? 1 : -1;
	int newpos = yaongPos + direction;

	prvCatPos = yaongPos;

	if (newpos > 0 && newpos < ROOM_WIDTH - 1)
		yaongPos = newpos;
	printf("%s쪽으로 움직입니다\n", (direction == 1 ? "냄비" : "집"));
}
void makeSuop() {
	if (yaongPos == BWL_POS) {
		soup++;
		int randsoup = rand() % 3;
		if (randsoup == 0) {
			printf("%s이가 감자수프를 만들었습니다\n", catName);
		}
		else if (randsoup == 1) {
			printf("%s이가 양송이 수프를 만들었습니다\n", catName);
		}
		else if (randsoup == 2) {
			printf("%s이가 브로콜리 수프를 만들었습니다\n", catName);
		}
		printf("현재까지 만든 수프: %d\n", soup);
	}
	if (yaongPos == HME_POS) printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", catName);

}
