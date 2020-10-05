#include <iostream>
using namespace std;


bool CompareString(const char *str1, const char *str2);	//���ڿ��� ��ҹ��� ������� �����ִ� �Լ�

int main() {

	char str1[64] = { 0, };		//ù ��° ��Ʈ���� ������ �迭�� ����
	char str2[64] = { 0, };		//�� ��° ��Ʈ���� ������ �迭�� ����

	cout << "str1 : ";
	cin.getline(str1, 64);		//getline�� ����� ����ڰ� �Է��� ��Ʈ���� str1�� ����

	cout << "str2 : ";
	cin.getline(str2, 64);		//getline�� ����� ����ڰ� �Է��� ��Ʈ���� str2�� ����

	if (CompareString(str1, str2) == true) cout << "They are eqaul." << endl;
	else cout << "The are Different." << endl;	//CompareString�Լ��� Str1, Str2�� ������ ����� ���

}

bool CompareString(const char *str1, const char *str2) {		//���ڿ��� ��ҹ��� ���� �����ִ� �Լ�

	int count = 0;			
	int overlap = 0;		//���ڿ��� ������ �� �� �� ���Ҵ��� üũ�ϴ� ������ ���� �� �ʱ�ȭ

	while (1) {	//���ڿ��� ���ϴ� While��

		if (str1[count] == NULL && str2[count] == NULL) {	//�ΰ��� ��Ʈ���� �ѹ��ڿ��� ���ϴٰ� ������ �� ����
			break;
		}

		if (str1[count] == str2[count]) {		//�Է� ���� String 2���� ��ҹ��� ���� ���� �׳� ���� ���� ��� Overlap + 1
			overlap = overlap + 1;
		}
		if (str1[count] + 32 == str2[count]) {  //�ƽ�Ű �ڵ�� ������ �� ��ҹ����� ���̴� 32�̴�.
			overlap = overlap + 1;				//Str1�� �ҹ����̰� Str2�� �빮���̸� Overlap = Overlap + 1
		}
		if (str1[count] == str2[count] + 32) {  //�ƽ�Ű �ڵ�� ������ �� ��ҹ����� ���̴� 32�̴�.
			overlap = overlap + 1;				//Str1�� �빮���̰� Str2�� �ҹ����̸� Overlap = Overlap + 1
		}

		count = count + 1;						//���� ���ڿ��� ���ϱ� ���ؼ� Count�� ����
		
	}

	if (overlap == count) return true;		 //���ڿ��� ���� Ƚ���� ���ڿ��� ���Ҵ� Ƚ���� ������ ���� ���ڿ��̱� ������ true�� return�Ѵ�.
	else if (overlap != count) return false;//���ڿ��� ���� Ƚ���� ���ڿ��� ���Ҵ� Ƚ���� �ٸ��� �ٸ� ���ڿ��̱� ������ false�� return�Ѵ�.
}

