#include <iostream>
using namespace std;

int main() {

	char input[100] = { 0, }; //N값을 입력 받기 위해서 character배열을 선언 및 초기화
	int i, n, k = 0;

	while (1) { //사용자가 input값을 입력하는 while문, input값이 홀수만 들어오게 설정
		
		cout << "N: "; 
		cin >> input;
		n = atoi(input); //'input'값을 atoi함수를 사용해 int로 변환한다. 이 때, 문자열을 입력받으면 0을 return
		if (n % 2 != 0) { //사용자가 입력하는 N값을 홀수만 입력해야 하기 때문에 홀수가 들어오면 While문을 빠져 나가게 설정
			break;
		}
	}

	cout << endl << endl;

	while (k <= n / 2) { //중간을 포함해서 위쪽 마름모를 출력하는 부분

		for (i = n / 2; i > k; i--) { //공백을 출력하는 for문
			cout << ' ';
		}

		for (i = 0; i <= k; i++) { //한 line에서 처음부터 중간까지 숫자를 증가시키면서 출력하는 for문
			cout << i;
		} 
		for (i = k; i > 0; i--) { //한 line에서 중간을 기준으로 숫자를 감소시키면서 출력하는 for문 
			cout << i - 1;
		}
		cout << endl;

		k = k + 1;
	}

	k = k - 1;

	while (k) { //중간을 제외한 아래쪽 마름모를 출력하는 부분

		for (i = n / 2; i >= k; i--) { //공백을 출력하는 for문
			cout << ' ';
		}

		k = k - 1;

		for (i = 0; i <= k; i++) { //한 line에서 처음부터 중간까지 숫자를 증가시키면서 출력하는 for문
			cout << i; 
		}
		for (i = k; i > 0; i--) { //한 line에서 중간을 기준으로 숫자를 감소시키면서 출력하는 for문 
			cout << i - 1;
		}
		cout << endl;

	}
	cout << endl << endl;
	return 0;

}