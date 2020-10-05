#include <iostream>
using namespace std;


bool CompareString(const char *str1, const char *str2);	//문자열을 대소문자 상관없이 비교해주는 함수

int main() {

	char str1[64] = { 0, };		//첫 번째 스트링을 저장할 배열을 선언
	char str2[64] = { 0, };		//두 번째 스트링을 저장할 배열을 선언

	cout << "str1 : ";
	cin.getline(str1, 64);		//getline을 사용해 사용자가 입력한 스트링을 str1에 저장

	cout << "str2 : ";
	cin.getline(str2, 64);		//getline을 사용해 사용자가 입력한 스트링을 str2에 저장

	if (CompareString(str1, str2) == true) cout << "They are eqaul." << endl;
	else cout << "The are Different." << endl;	//CompareString함수를 Str1, Str2에 적용해 결과를 출력

}

bool CompareString(const char *str1, const char *str2) {		//문자열을 대소문자 없이 비교해주는 함수

	int count = 0;			
	int overlap = 0;		//문자열을 비교했을 때 몇 번 같았는지 체크하는 변수를 선언 및 초기화

	while (1) {	//문자열을 비교하는 While문

		if (str1[count] == NULL && str2[count] == NULL) {	//두개의 스트링이 한문자열씩 비교하다가 끝나면 비교 종료
			break;
		}

		if (str1[count] == str2[count]) {		//입력 받은 String 2개가 대소문자 구분 없이 그냥 같은 값일 경우 Overlap + 1
			overlap = overlap + 1;
		}
		if (str1[count] + 32 == str2[count]) {  //아스키 코드로 비교했을 때 대소문자의 차이는 32이다.
			overlap = overlap + 1;				//Str1이 소문자이고 Str2가 대문자이면 Overlap = Overlap + 1
		}
		if (str1[count] == str2[count] + 32) {  //아스키 코드로 비교했을 때 대소문자의 차이는 32이다.
			overlap = overlap + 1;				//Str1이 대문자이고 Str2가 소문자이면 Overlap = Overlap + 1
		}

		count = count + 1;						//다음 문자열을 비교하기 위해서 Count가 증가
		
	}

	if (overlap == count) return true;		 //문자열을 비교한 횟수가 문자열이 같았던 횟수랑 같으면 같은 문자열이기 때문에 true를 return한다.
	else if (overlap != count) return false;//문자열을 비교한 횟수와 문자열이 같았던 횟수가 다르면 다른 문자열이기 때문에 false를 return한다.
}

