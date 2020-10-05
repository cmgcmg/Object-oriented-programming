#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	char input[100] = { 0, }; //N���� �Է� �ޱ� ���� character�迭�� ���� �� �ʱ�ȭ
	int n = 0;
	int count[30] = { 0, };   //1���� 20���� ������ �󵵼��� ���ʴ�� ���� �� �迭�� ���� �� �ʱ�ȭ 

	while (1) {			//����ڰ� intput���� �Է��ϰ� ���ڸ� �Է� �ޱ� ���� ����ó���� while��
		cout << "Input N: ";
		cin >> input;
		n = atoi(input); //input���� integer�� ���;� �ϱ� ������ atoi�Լ��� character�� integer�� ��ȭ
						 //����ڰ� ���ڰ� �ƴ� �ٸ� ���ڿ��� �־��� ��� n = 0�̴�.
		if (n != 0) {	 //n�� 0�̾ƴϸ� ����ڰ� N���� ���ڷ� �� �־��� ������ while���� ����������.
			break;
		}
	}
	int *random = new int[n]; //����ڰ� �Է��ϴ� input���� �°� �����迭�� �Ҵ�

	srand((unsigned int)time(0)); //���α׷� ����� �׻� �ٸ� ������ �����ϱ� ���� �κ�

	cout << "Random number: ";
	for (int i = 0; i < n; i++) { //������ ������ random�迭�� ���ʷ� �����ϴ� for��

		int k = rand() % 20 + 1; //k�� 1~20������ ������ ������ ��
		random[i] = k;			 //random�迭�� 1~20������ ������ ���ʷ� ����
		cout << random[i] << ' ';
	}
	cout << endl; 

	for (int i = 0; i < n; i++) { //random�迭�� ����ִ� ���� ���ʴ�� ��Ÿ���� for��
		for (int j = 1; j <= 20; j++) { //random�迭�� ���ʴ�� ����ִ� ���� 1~20�� �� �ϴ� for��
			if (random[i] == j)
				count[j] = count[j] + 1;	//1~20 �󵵼��� ���ʴ�� count�迭�� �����ϴ� �κ�
		}
	} 
	
	delete[] random; //�������� �迭�� ����

	while (true) { //�󵵼��� ���� �ͺ��� ���ʴ�� ����ϰ� �󵵼��� ������ ���� ū �ͺ��� ����ϴ� while��

		for (int i = 20; i >= 1; i--) { //count�迭�� ����ִ� 20���� 1������ �󵵼��� ���ϴ� for��
			if (count[i] == n) //n�� input�� �Է����� �� �ִ�� ���� ���ü� �ִ� �󵵼��� n�̱� ������ �� ���ǹ�
				cout << i << ' ' << "-" << ' ' << count[i] << endl;
		}
		n--; 
		//n���� �ִ��ؼ� 0���� ��� �����ϱ� ������ �󵵼��� ���� �� ���� ���
		//���� for���� �󵵼��� ����ִ� count�迭�� 20���� 1���� ���ʴ�� ���ϹǷ� �󵵼��� ������ ���� ū �� ���� ���
		if (n == 0) {
			break;
		} //�󵵼��� 0�� ���� ������� �ʱ� ������ n�� 0�̸� while���� Ż��
	}

	return 0;
}