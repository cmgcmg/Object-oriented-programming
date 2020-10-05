#include <iostream>
using namespace std;

int fibonacci(int n);	//�Ǻ���ġ �Լ�

int main() {
	int n = 0;					//2 x n ���簢���� ���� ����� �� ���̴� n ����
	char input[100] = { 0, };	//Test Case�� �Է� ���� Char�� �迭
	int count = 0;				//Test Case�� Char�� �迭�� �Է¹޾Ҵµ� int�� ���� ���� 


	while (1) { //����ڰ� input���� �Է��ϴ� while��, input���� Ȧ���� ������ ����

		cout << "Test Case: ";
		cin >> input;
		count = atoi(input);	//'input'���� atoi�Լ��� ����� int�� ��ȯ�Ѵ�. �� ��, ���ڿ��� �Է¹����� 0�� return
		if (count != 0) break;	//�Է¹��� ���� int���� �ƴ϶� ���ڿ��̸� �ٽ� input���� �޾ƿ����� ���� ó��
	}

	while (count != 0) {	//Test Case�� ���� ����ŭ While���� �ݺ�, count�� 0�̸� ����

		
			cout << "Enter n = ";
			cin >> n;
			while (1) {		//N���� 50���� ũ�� �ٽ� �Է¹޵��� ����ó��
				if (n <= 50) break;
				cout << "Enter n = ";
				cin >> n;
			}

			cout << "-> Output : " << fibonacci(n) << endl;	//�Է¹��� n���� ���� �Ǻ���ġ ������ ������ ���� ���
		
		count--;			//�ѹ� ��� ���� count�� ���ҽ��� �ش�.

	}
	return 0;
}


int fibonacci(int n) {	//�Ǻ���ġ ������ �ݺ������� ����
						
	int temp, current = 1;
	int last = 0;
	if (n < 2) return n;
	else {
		for (int i = 2; i <= n + 1; i++) { //�Ǻ���ġ ������ for���� ���ؼ� n���� ���� ���� ���Ѵ�.
			temp = current;
			current += last;
			if (current > 1000) {		   //���� n���� �ش��ϴ� 'Current'���� 1000���� ũ�� �������� ���
				current = current % 1000;
			}
			last = temp;
		}
		return current;
	}
}