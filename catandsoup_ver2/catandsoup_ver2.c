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
	//cp 포인트
	printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", catName, lastproduceCP);
	printf("CP: %d 포인트\n",cp);
	//기분
	printf("%s이 기분(0 ~ 3): %d\n", catName, feelings);
	if (feelings == 0) {
		printf("기분이 매우 나쁩니다.\n");
	}
	else if (feelings == 1) {
		printf("지루해 합니다.\n");
	}
	else if (feelings == 2) {
		printf("식빵을 굽습니다.\n");
	}
	else if (feelings == 3) {
		printf("골골송을 부릅니다.\n");
	}
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

void feel() {
	int dice = rollDice();
	printf("주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", 6 - Intimacy);
	printf("주사위를 굴립니다. 또르르...\n");
	printf("%d가 나왔습니다\n", dice);
	if (dice < 6 - Intimacy && feelings > 0) {
		feelings--;
		printf("%s의 기분이 나빠집니다: %d -> %d\n", catName, feelings + 1, feelings);
	}
}

void doInteraction() {
	int choice;
	while (1) {
		printf("어떤 상호작용을 하시 겠습니까?\n");
		printf("0.아무것도 하지않음.\n");
		printf("1.쓰다듬기.\n");
		if (hasMouse == 1) printf("2.장난감 쥐로 놀아주기\n");
		if (hasPoiter == 1) printf("3.레이저 포인트로 놀아주기\n");
		printf(">>");
		scanf_s("%d", &choice);
		if (choice == 0) {
			feelings--;
			printf("아무것도 하지않습니다.\n");
			printf("%s의 기분이 나빠졌습니다: %d -> %d",catName,feelings+1,feelings);
			printf("주사위의 눈이 5이하이면 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
			int dice = rollDice();
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice <= 5 && Intimacy > 0) {
				Intimacy--;
				printf("집사와의 관계가 나빠집니다.\n");
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			}
			break;
		}
		else if (choice == 1) {
			printf("%s의 쓰다듬어 주었습니다.\n", catName);
			printf("%s의 기분은 그대로 입니다 : %d\n", catName, feelings);
			printf("주사위의 눈이 5이상이면 친밀도가 올라갑니다.\n주사위를 굴립니다. 또르륵...\n");
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
		else if(choice == 2){
			printf("장난감 쥐로 %s와 놀아주었습니다.\n",catName);
			feelings++;
			printf("%s의 기분이 조금 좋아졌습니다 : %d -> %d\n", catName, feelings -1, feelings);
			printf("주사위의 눈이 4이상이면 친밀도가 올라갑니다.\n주사위를 굴립니다. 또르륵...\n");
			int dice = rollDice();
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice >= 4 && Intimacy < 4) {
				Intimacy++;
				printf("친밀도가 높아집니다.\n");
			}
			else {
				printf("친밀도는 그대로입니다.\n");
			}
			break;
		}
		else if (choice == 3) {
			printf("레이저 포인터로 %s와 놀아주었습니다.\n", catName);
			feelings += 2;
			printf("%s의 기분이 꽤 좋아졌습니다 : %d -> %d\n", catName, feelings - 2, feelings);
			printf("주사위의 눈이 2이상이면 친밀도가 올라갑니다.\n주사위를 굴립니다. 또르륵...\n");
			int dice = rollDice();
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice >= 2 && Intimacy < 4) {
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

//아 왜 안되 진짜 ㅇㄴ 로ㅓㄴㅇㅁ오ㅕㅑㅐ
void moveCat() {
	prvCatPos = yaongPos; // 이전 위치 저장

	
	// 기분 겁나 좋음
	if (feelings == 3) {
		if (yaongPos < BWL_POS) yaongPos++;
	}
	//그냥 그럴떄
	else if (feelings == 2) {
		printf("%s이는 기분 좋게 식빵을 굽고 있습니다.\n", catName);
	}
	//아 어렵다
	else if (feelings == 1) {
		//여기 기구가 없을 경우 만들기 나중에 
		int hasTower = (CAT_TOWER > 0 && CAT_TOWER < ROOM_WIDTH - 1);
		int hasScratcher = (SCRATCHER > 0 && SCRATCHER < ROOM_WIDTH - 1);
		if (!hasTower && !hasScratcher) {
			printf("방에 놀이 기구가 없어 %s의 기분이 더 나빠집니다.\n", catName);
			if (feelings > 0) feelings--;
		}
		// 거기 계산 절댓값으로 해보기
		int distTower = abs(yaongPos - CAT_TOWER);
		int distScratcher = abs(yaongPos - SCRATCHER);
		int target;
		if (distTower < distScratcher) target = CAT_TOWER; 
		else if (distScratcher < distTower) target = SCRATCHER;
		else target = (CAT_TOWER < SCRATCHER) ? CAT_TOWER : SCRATCHER; // 둘 다 같으면 더 왼쪽

		if (yaongPos < target) yaongPos++;
		else if (yaongPos > target) yaongPos--;
	}
	// 기분이 매우 나쁘면 집쪽으로
	else if (feelings == 0) {
		if (yaongPos > HME_POS) yaongPos--;
		printf("기분이 매우 나쁜 %s이는 집으로 갑니다.\n", catName);
	}

	//맵 밖으로 안나게 하기
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

void produce_CP() {
	int produceCP = (feelings > 0) ? feelings - 1 + Intimacy : 0;
	lastproduceCP = produceCP;
	cp += produceCP;
}

void shop() {
	int choice;
	//실행 되는 동안 값이 유지 되도록 해야됨 근데 왜 안되ㅣㅈ
	//int hasMouse = 0, hasPoiter = 0 , hasScrater = 0, hasTower = 0;
	printf("상점에서 물건을 살 수 있습니다.\n");
	printf("어떤 물건을 구매할까요?\n");
	//printf("보유 CP 포인트 %d\n", cp);
	printf("0. 아무것도 사지 않는다.\n");
	printf("1. 장난감 쥐 : 1CP %s\n ",hasMouse ? "(품절)" : "");
	printf("2. 레이저 포인터: 2CP %s\n",hasPoiter ? "(품절)" : "");
	printf("3. 스크래처: 4CP %s \n",hasScrater ? "(품절)" : "");
	printf("4. 캣 타워: 6CP %s\n",hasTower ? "(품절)" : "");
	printf(">>");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 0:
		break;
	case 1:
		if (hasMouse) {
			printf("이미 장난감 쥐를 구매하였습니다.\n");
		}
		else if (cp < 1) {
			printf("CP가 부족합니다.\n");
		}
		else {
			cp -= 1;
			hasMouse = 1;
			printf("장난감 쥐를 구매함. 남은 CP: %d\n", cp);
		}
		break;
	case 2:
		if (hasPoiter) {
			printf("이미 레이저 포인터를 구매하셨습니다.\n");
		}
		else if (cp < 2) {
			printf("CP가 부족합니다.\n");
		}
		else {
			cp -= 2;
			hasPoiter = 1;
			printf("레이저 포인터를 구매함.남은 CP : % d\n", cp);
		}

		break;
	case 3:
		if (hasScrater) {
			printf("이미 스크래처를 구매하셨습니다.\n");
		}
		else if (cp < 4) {
			printf("CP가 부족합니다.\n");
		}
		else {
			cp -= 4;
			hasScrater = 1;
			printf("스크래쳐를 구매함.남은 CP : % d\n", cp);
		}
		break;
	case 4:
		if (hasTower) {
			printf("이미 스크래처를 구매하셨습니다.\n");
		}
		else if (cp < 6) {
			printf("CP가 부족합니다.\n");
		}
		else {
			cp -= 6;
			hasTower = 1;
			printf("캣타워를 구매함.남은 CP : % d\n", cp);
		}
		break;
	default:
		printf("잘못된 입력입니다.\n");
	}
}

void min_game() {
	int num1, num2, answer, userInput;

	printf("==========================\n");
	printf("랜덤 미니 게임.\n");
	printf("두 숫자의 곱을 맞춰보세요!\n");
	printf("==========================\n");

	num1 = rand() % 10 + 1; // 1부터 10까지의 랜덤 숫자
	num2 = rand() % 10 + 1; 
	answer = num1 * num2;

	printf("%d x %d = ?\n", num1, num2);
	printf("정답을 입력하세요: ");
	scanf_s("%d", &userInput);
	if (userInput == answer) {
		printf("정답입니다! %d x %d = %d\n", num1, num2, answer);
		feelings++;
		printf("고양이의 기분이 1 좋아 집니다 %d -> %d", feelings - 1, feelings);
	} else {
		printf("틀렸습니다. 정답은 %d입니다.\n", answer);
	}

}