#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void initialization();		//빙고판을 1~25로 초기화 하는 함수
void shuffle();				//순서대로 되어있는 빙고판을 섞어주는 함수
void show();				//빙고판을 출력하는 함수
void bingocheck();			//가로 및 세로 빙고가 1줄이 있는지 확인하는 함수
void usercall();			//유저가 숫자를 입력하는 부분에 해당하는 함수
void comcall();				//컴퓨터가 숫자를 입력하는 부분에 해당하는 함수

int user[5][5] = {};		//User 빙고판을 만들기 위해서 2차원 배열을 사용
int computer[5][5] = {};    //computer 빙고판을 만들기 위해서 2차원 배열을 사용
int userbingo = 0;			//User 빙고수를 체크하기 위해 변수 선언
int combingo = 0;			//Computer 빙고수를 체크하기 위해 변수 선언
int n = 0;					//입력받는 값에 해당하는 변수 선언 , 컴퓨터와 유저 모두 사용
int checkarray[25] = { 0, };//중복된 수를 확인하기 위해 배열 하나를 사용 (0~24번은 1~25의 수로 되어있다.)

int main() {
	srand((unsigned int)time(0)); //프로그램 실행시 항상 다른 난수를 추출하기 위한 부분
	initialization();			  //빙고판과 중복된수를 확인하는 배열을 초기화
	shuffle();				      //빙고판을 랜덤하게 섞어준다.

	while (true) { //While문을 통해서 빙고게임을 시작

		show();	//빙고판을 출력
		if (userbingo == 1 && combingo != 1) { cout << "BINGO!! User Win" << endl; break; } //User가 먼저 빙고일 경우 Stop
		else if (userbingo != 1 && combingo == 1) { cout << "BINGO!! Computer Win" << endl; break; } //Computer가 먼저 빙고일 경우 Stop
		else if (userbingo == 1 && combingo == 1) { cout << "Both BINGO!! Both Win" << endl; break; } //User와 Computer 동시에 빙고가 되었을 경우 Stop
		usercall();		//사용자의 입력
		show();			//수정된 빙고판을 출력
		if (userbingo == 1 && combingo != 1) { cout << "BINGO!! User Win" << endl; break; } //User가 먼저 빙고일 경우 Stop
		else if (userbingo != 1 && combingo == 1) { cout << "BINGO!! Computer Win" << endl; break; } //Computer가 먼저 빙고일 경우 Stop
		else if (userbingo == 1 && combingo == 1) { cout << "Both BINGO!! Both Win" << endl; break; } //User와 Computer 동시에 빙고가 되었을 경우 Stop
		comcall();		//Computer의 입력
		bingocheck();	//빙고인지 체크
	}
	return 0;
}

void initialization() //빙고판을 1~25로 초기화 하는 함수
{					  //빙고판을 1행1열부터 5행5열까지 두개의 for문을 통해서 초기화
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			user[i][j] = (i * 5)+j + 1;
			computer[i][j] = (i * 5)+j + 1;
		}
	}

	for (int i = 0; i < 25; i++) {
		checkarray[i] = i + 1;
	}				//checkarray배열 0번부터 24번까지를 1~25로 for문을 통해서 초기화
}

void shuffle() {  //순서대로 되어있는 빙고판을 섞어주는 함수

	for (int i = 0; i < 100; i++) { //user 빙고판을 섞어주는 과정을 여러번 하기 위한 for문
		int rand1 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int rand2 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int rand3 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int rand4 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int temp = 0;
		//임의의 배열 원소 2개를 뽑아서 자리를 바꿔주는 방법으로 빙고판을 섞는다.
		temp = user[rand1][rand2];
		user[rand1][rand2] = user[rand3][rand4];
		user[rand3][rand4] = temp;
	}

	for (int i = 0; i < 100; i++) { //computer 빙고판을 섞어주는 과정을 여러번 하기 위한 for문
		int rand1 = rand() % 5;	//1~25까지 랜덤함수를 발생시킨다.
		int rand2 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int rand3 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int rand4 = rand() % 5; //1~25까지 랜덤함수를 발생시킨다.
		int temp = 0;
		//임의의 배열 원소 2개를 뽑아서 자리를 바꿔주는 방법으로 빙고판을 섞는다.
		temp = computer[rand1][rand2];
		computer[rand1][rand2] = computer[rand3][rand4];
		computer[rand3][rand4] = temp;
	}
}

void show() { //빙고판을 출력하는 함수

	cout << "<user bingo board>";
	cout << endl;

	for (int i = 0; i < 5; i++) { //1행1열부터 5행5열까지 user 빙고판을 출력하기 위한 2개의 for문
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == '#')
				cout << (char)user[i][j] << "\t"; //숫자가 맞았을 때 int형이 아닌 '#'을 출력해야하므로 char
			else
				cout << user[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "<computer bingo board>";
	cout << endl;

	for (int i = 0; i < 5; i++) { //1행1열부터 5행5열까지 computer빙고판을 출력하기 위한 2개의 for문
		for (int j = 0; j < 5; j++) {
			if (computer[i][j] == '#')
				cout << (char)computer[i][j] << "\t"; //숫자가 맞았을 때 int형이 아닌 '#'을 출력해야하므로 char
			else
				cout << computer[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void bingocheck() { //User와 Computer의 빙고판에서 가로1줄 또는 세로1줄이 빙고인지 확인하는 함수

	for (int i = 0; i < 5; i++) {
		int userrow = 0;	//User의 가로가 빙고인지 체크할 변수 선언 및 초기화
		int usercal = 0;	//User의 세로가 빙고인지 체크할 변수 선언 및 초기화
		int comrow = 0;		//Computer의 가로가 빙고인지 체크할 변수 선언 및 초기화
		int comcal = 0;		//Computer의 세로가 빙고인지 체크할 변수 선언 및 초기화

		for (int j = 0; j < 5; j++) {
			if (user[i][j] == '#') {	
				userrow++;	//User의 가로가 빙고일 경우
			}
			if (computer[i][j] == '#') {
				comrow++;	//Computer의 가로가 빙고일 경우
			}
			if (user[j][i] == '#') {
				usercal++;	//User의 세로가 빙고일 경우
			}
			if (computer[j][j] == '#') {
				comcal++;	//Computer의 세로가 빙고일 경우
			}
		}
		if (userrow == 5 || usercal == 5) {
			userbingo = userbingo + 1;	//User가 가로나 세로가 빙고일 경우 Userbingo = 1
		}
		if (comrow == 5 || comcal == 5) {
			combingo = combingo + 1;	//Computer의 가로나 세로가 빙고일 경우 Combingo = 1
		}
	}
}

void usercall() { //User가 Input값을 주는 부분

	cout << "Call a Number(1~25) : ";
	cin >> n;

	if (n < 1) {						//유저가 부르는 수는 1~25이기 때문에 예외처리한 부분
		cout << "Call 1~25 : " << endl;
		cin >> n;
	}
	if (n > 25) {						//유저가 부르는 수는 1~25이기 때문에 예외처리한 부분
		cout << "Call 1~25 : ";
		cin >> n;
	}
	if (checkarray[n - 1] == 0) {		//유저가 중복된 수를 입력했을 경우에 예외처리한 부분
			cout << "이미 입력한 숫자입니다. 다시 입력해주세요." << endl;
			cin >> n;
		}
	
	checkarray[n - 1] = 0;				//User가 부른 값을 1~25가 들어있는 Checkarray에서 0으로 초기화해준다.
										//중복된 수를 발생시키지 않으려고 작성한 부분

	for (int i = 0; i < 5; i++) {		//User가 부른 수가 User와 Computer 빙고판에 있는 수와 같다면 '#'처리
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == n) user[i][j] = '#';
			if (computer[i][j] == n) computer[i][j] = '#';
		}
	}
}

void comcall() {		//Computer가 Input을 입력하는 부분

	while (1) {		//이미 사용했던 수를 제외하고 1~25를 출력하기 위한 While문
		n = rand() % 25 + 1;	//1~25사이에 난수를 추출
		if (checkarray[n - 1] == 0) {	//난수 값이 이미 불러졌었던 수면 다시 난수를 추출
			n = rand() % 25 + 1;
		if (checkarray[n - 1] != 0) {	//난수 값이 이미 불러졌었던 수가 아니면 While문을 탈출
				break;
			}
		}
	}
	checkarray[n - 1] = 0;				//Computer가 부른 값을 1~25가 들어있는 Checkarray에서 0으로 초기화해준다.
										//중복된 수를 발생시키지 않으려고 작성한 부분
	cout << "Computer Calls : " << n << endl; //Computer가 부른 값을 출력

	for (int i = 0; i < 5; i++) {		//Computer가 부른 수가 User와 Computer 빙고판에 있는 수와 같다면 '#'처리
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == n) user[i][j] = '#';
			if (computer[i][j] == n) computer[i][j] = '#';
		}
	}
}







