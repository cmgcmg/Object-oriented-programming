#include <iostream>
#include <fstream>
using namespace std;

void dessort(char *arr, int n);

int main() {

	char arr[100] = { 0, };		//파일을 불러와 저장할 배열
	char arr2[100] = { 0, };	//N값(숫자)를 넣어줄 배열
	int arr3[100] = { 0, };		//input값들을 저장할 배열
	int n = 0;					//N값
	char sort[100] = { 0, };	//내림차순으로 정렬한 뒤 저장할 배열
	int result1 = 0;		//입력 숫자로 이루어진 최대 합계를 구할 하나의 수를 저장할 변수
	int result2 = 0;		//입력 숫자로 이루어진 최대 합계를 구할 하나의 수를 저장할 변수
	int k = 10;				//10의 제곱수를 표현할 때 사용하는 변수
	int p = 10;				//10의 제곱수를 표현할 때 사용하는 변수


	ifstream fin("input.txt");	//파일 읽어오기

	if (fin.fail()) {	//파일읽기에 실패하면 출력하는 예외처리 부분
		cout << "파일 불러오기에 실패했습니다." << endl;
		return 0;
	}

	for (int i = 0; i < 100; i++) { //파일을 읽어와서 arr배열에 저장하는 for문
		fin >> arr[i];
	}

	fin.close();				//파일 닫기

	for (int i = 2; i < 100; i++) { //arr2 배열에 0번부터 arr배열에 N에 숫자에 해당하는 값부터 순서대로 넣어주는 for문
		arr2[i - 2] = arr[i];		//arr2 배열 0번은 N값에 해당하는 숫자부터 시작한다.
	}

	n = atoi(arr2);					//atoi함수를 써서 arr2배열을 int형으로 바꿔주면 뒤에 input은 무시하고 N(숫자)값만 받아올 수 있다.

	if (n % 2 != 0) {				//N(숫자)값이 홀수면 error를 출력한 예외처리
		cout << "output: error" << endl;
		return 0;
	}

	if (n >= 20) {					//N 20보다 작은 수 이기 때문에 예외처리 한 부분
		cout << "output: error" << endl;
		return 0;
	}


	dessort(arr, n);	//arr배열을 input값을 내림차순 함수를 적용
	

	for (int i = 9; i < 9 + n; i++) {			//내림차순으로 정렬된 input값을 sort[0]번부터 차례대로 저장
		sort[i - 9] = arr[i];
	}



	for (int i = 0; i < n; i++) {				//input값을 아스키값으로 48을 빼줘서 int형 배열(arr3)에 저장한다.
		arr3[i] = sort[i] - 48;

	}


	for (int i = n - 2; i >= 0; i--) {			//0번째를 포함한 arr3배열에 짝수 번째 배열에 대해서 작업을 수행하는 for문
												//짝수번 째 마지막 배열의 수부터 해당하는 값을 차례대로 x1 x10 x100 (10의 제곱)을 하면서 result1에 계속 더해준다.  
		result1 += arr3[i] * (k / 10);
		k = k * 10;
		i = i - 1;
	}

	for (int i = n - 1; i > 0; i--) {			//0번째를 포함하지 않은 arr3배열에 홀수 번째 배열에 대해서 작업을 수행하는 for문
												//홀수번 째 마지막 배열의 수부터 해당하는 값을 차례대로 x1 x10 x100 (10의 제곱)을 하면서 result2에 계속 더해준다. 

		result2 += arr3[i] * (p / 10);
		p = p * 10;
		i = i - 1;
	}

	cout << "output: " << result1 + result2;	//result1과 result2의 값을 더해서 입력 숫자로 이루어진 두 숫자의 가능한 최대 합계를 출력
	cout << endl;				
	return 0;
}



void dessort(char *arr, int n) {	//내림차순 해주는 함수

	int temp = 0;

	for (int i = 9; i < 9 + n; i++) {		//arr배열 9번째부터 input값(숫자)들이 들어있기 떄문에 i = 9 부터 시작
		for (int j = 9; j < 9 + n; j++) {	//2개의 for문을 돌면서 큰거부터 차례대로 정렬
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}