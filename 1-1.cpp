#include <iostream>
using namespace std;

int main() {

	char input[100] = { 0, }; //N���� �Է� �ޱ� ���ؼ� character�迭�� ���� �� �ʱ�ȭ
	int i, n, k = 0;

	while (1) { //����ڰ� input���� �Է��ϴ� while��, input���� Ȧ���� ������ ����
		
		cout << "N: "; 
		cin >> input;
		n = atoi(input); //'input'���� atoi�Լ��� ����� int�� ��ȯ�Ѵ�. �� ��, ���ڿ��� �Է¹����� 0�� return
		if (n % 2 != 0) { //����ڰ� �Է��ϴ� N���� Ȧ���� �Է��ؾ� �ϱ� ������ Ȧ���� ������ While���� ���� ������ ����
			break;
		}
	}

	cout << endl << endl;

	while (k <= n / 2) { //�߰��� �����ؼ� ���� ������ ����ϴ� �κ�

		for (i = n / 2; i > k; i--) { //������ ����ϴ� for��
			cout << ' ';
		}

		for (i = 0; i <= k; i++) { //�� line���� ó������ �߰����� ���ڸ� ������Ű�鼭 ����ϴ� for��
			cout << i;
		} 
		for (i = k; i > 0; i--) { //�� line���� �߰��� �������� ���ڸ� ���ҽ�Ű�鼭 ����ϴ� for�� 
			cout << i - 1;
		}
		cout << endl;

		k = k + 1;
	}

	k = k - 1;

	while (k) { //�߰��� ������ �Ʒ��� ������ ����ϴ� �κ�

		for (i = n / 2; i >= k; i--) { //������ ����ϴ� for��
			cout << ' ';
		}

		k = k - 1;

		for (i = 0; i <= k; i++) { //�� line���� ó������ �߰����� ���ڸ� ������Ű�鼭 ����ϴ� for��
			cout << i; 
		}
		for (i = k; i > 0; i--) { //�� line���� �߰��� �������� ���ڸ� ���ҽ�Ű�鼭 ����ϴ� for�� 
			cout << i - 1;
		}
		cout << endl;

	}
	cout << endl << endl;
	return 0;

}