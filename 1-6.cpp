#include <iostream>
using namespace std;

int fibonacci(int n);	//피보나치 함수

int main() {
	int n = 0;					//2 x n 직사각형의 수를 계산할 때 쓰이는 n 변수
	char input[100] = { 0, };	//Test Case에 입력 받을 Char형 배열
	int count = 0;				//Test Case에 Char형 배열을 입력받았는데 int로 받을 변수 


	while (1) { //사용자가 input값을 입력하는 while문, input값이 홀수만 들어오게 설정

		cout << "Test Case: ";
		cin >> input;
		count = atoi(input);	//'input'값을 atoi함수를 사용해 int로 변환한다. 이 때, 문자열을 입력받으면 0을 return
		if (count != 0) break;	//입력받은 값이 int형이 아니라 문자열이면 다시 input값을 받아오도록 예외 처리
	}

	while (count != 0) {	//Test Case에 들어온 수만큼 While문을 반복, count가 0이면 종료

		
			cout << "Enter n = ";
			cin >> n;
			while (1) {		//N값이 50보다 크면 다시 입력받도록 예외처리
				if (n <= 50) break;
				cout << "Enter n = ";
				cin >> n;
			}

			cout << "-> Output : " << fibonacci(n) << endl;	//입력받은 n값에 따른 피보나치 수열을 적용한 값을 출력
		
		count--;			//한번 출력 이후 count를 감소시켜 준다.

	}
	return 0;
}


int fibonacci(int n) {	//피보나치 수열을 반복문으로 수행
						
	int temp, current = 1;
	int last = 0;
	if (n < 2) return n;
	else {
		for (int i = 2; i <= n + 1; i++) { //피보나치 수열을 for문을 통해서 n값에 따라 값을 구한다.
			temp = current;
			current += last;
			if (current > 1000) {		   //만약 n값에 해당하는 'Current'값이 1000보다 크면 나머지로 출력
				current = current % 1000;
			}
			last = temp;
		}
		return current;
	}
}