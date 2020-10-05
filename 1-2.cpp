#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	char input[100] = { 0, }; //N값을 입력 받기 위해 character배열을 선언 및 초기화
	int n = 0;
	int count[30] = { 0, };   //1부터 20까지 각각의 빈도수를 차례대로 저장 할 배열을 선언 및 초기화 

	while (1) {			//사용자가 intput값을 입력하고 숫자만 입력 받기 위해 예외처리한 while문
		cout << "Input N: ";
		cin >> input;
		n = atoi(input); //input값에 integer만 들어와야 하기 때문에 atoi함수로 character를 integer로 변화
						 //사용자가 숫자가 아닌 다른 문자열을 넣었을 경우 n = 0이다.
		if (n != 0) {	 //n이 0이아니면 사용자가 N값을 숫자로 잘 넣었기 때문에 while문을 빠져나간다.
			break;
		}
	}
	int *random = new int[n]; //사용자가 입력하는 input값에 맞게 동적배열을 할당

	srand((unsigned int)time(0)); //프로그램 실행시 항상 다른 난수를 추출하기 위한 부분

	cout << "Random number: ";
	for (int i = 0; i < n; i++) { //난수를 추출해 random배열에 차례로 저장하는 for문

		int k = rand() % 20 + 1; //k는 1~20사이의 난수를 추출한 값
		random[i] = k;			 //random배열에 1~20사이의 난수를 차례로 저장
		cout << random[i] << ' ';
	}
	cout << endl; 

	for (int i = 0; i < n; i++) { //random배열에 들어있는 값을 차례대로 나타내는 for문
		for (int j = 1; j <= 20; j++) { //random배열에 차례대로 들어있는 값을 1~20과 비교 하는 for문
			if (random[i] == j)
				count[j] = count[j] + 1;	//1~20 빈도수를 차례대로 count배열에 저장하는 부분
		}
	} 
	
	delete[] random; //동적받은 배열을 해제

	while (true) { //빈도수를 많은 것부터 차례대로 출력하고 빈도수가 같으면 수가 큰 것부터 출력하는 while문

		for (int i = 20; i >= 1; i--) { //count배열에 들어있는 20부터 1까지의 빈도수를 비교하는 for문
			if (count[i] == n) //n개 input을 입력했을 때 최대로 많이 나올수 있는 빈도수는 n이기 때문에 쓴 조건문
				cout << i << ' ' << "-" << ' ' << count[i] << endl;
		}
		n--; 
		//n값이 최대해서 0까지 계속 감소하기 때문에 빈도수는 많은 것 부터 출력
		//또한 for문을 빈도수가 들어있는 count배열을 20부터 1까지 차례대로 비교하므로 빈도수가 같으면 값이 큰 것 부터 출력
		if (n == 0) {
			break;
		} //빈도수가 0인 것은 출력하지 않기 때문에 n이 0이면 while문을 탈출
	}

	return 0;
}