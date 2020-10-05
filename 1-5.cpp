#include <iostream>
#include <fstream>
using namespace std;

void dessort(char *arr, int n);

int main() {

	char arr[100] = { 0, };		//������ �ҷ��� ������ �迭
	char arr2[100] = { 0, };	//N��(����)�� �־��� �迭
	int arr3[100] = { 0, };		//input������ ������ �迭
	int n = 0;					//N��
	char sort[100] = { 0, };	//������������ ������ �� ������ �迭
	int result1 = 0;		//�Է� ���ڷ� �̷���� �ִ� �հ踦 ���� �ϳ��� ���� ������ ����
	int result2 = 0;		//�Է� ���ڷ� �̷���� �ִ� �հ踦 ���� �ϳ��� ���� ������ ����
	int k = 10;				//10�� �������� ǥ���� �� ����ϴ� ����
	int p = 10;				//10�� �������� ǥ���� �� ����ϴ� ����


	ifstream fin("input.txt");	//���� �о����

	if (fin.fail()) {	//�����б⿡ �����ϸ� ����ϴ� ����ó�� �κ�
		cout << "���� �ҷ����⿡ �����߽��ϴ�." << endl;
		return 0;
	}

	for (int i = 0; i < 100; i++) { //������ �о�ͼ� arr�迭�� �����ϴ� for��
		fin >> arr[i];
	}

	fin.close();				//���� �ݱ�

	for (int i = 2; i < 100; i++) { //arr2 �迭�� 0������ arr�迭�� N�� ���ڿ� �ش��ϴ� ������ ������� �־��ִ� for��
		arr2[i - 2] = arr[i];		//arr2 �迭 0���� N���� �ش��ϴ� ���ں��� �����Ѵ�.
	}

	n = atoi(arr2);					//atoi�Լ��� �Ἥ arr2�迭�� int������ �ٲ��ָ� �ڿ� input�� �����ϰ� N(����)���� �޾ƿ� �� �ִ�.

	if (n % 2 != 0) {				//N(����)���� Ȧ���� error�� ����� ����ó��
		cout << "output: error" << endl;
		return 0;
	}

	if (n >= 20) {					//N 20���� ���� �� �̱� ������ ����ó�� �� �κ�
		cout << "output: error" << endl;
		return 0;
	}


	dessort(arr, n);	//arr�迭�� input���� �������� �Լ��� ����
	

	for (int i = 9; i < 9 + n; i++) {			//������������ ���ĵ� input���� sort[0]������ ���ʴ�� ����
		sort[i - 9] = arr[i];
	}



	for (int i = 0; i < n; i++) {				//input���� �ƽ�Ű������ 48�� ���༭ int�� �迭(arr3)�� �����Ѵ�.
		arr3[i] = sort[i] - 48;

	}


	for (int i = n - 2; i >= 0; i--) {			//0��°�� ������ arr3�迭�� ¦�� ��° �迭�� ���ؼ� �۾��� �����ϴ� for��
												//¦���� ° ������ �迭�� ������ �ش��ϴ� ���� ���ʴ�� x1 x10 x100 (10�� ����)�� �ϸ鼭 result1�� ��� �����ش�.  
		result1 += arr3[i] * (k / 10);
		k = k * 10;
		i = i - 1;
	}

	for (int i = n - 1; i > 0; i--) {			//0��°�� �������� ���� arr3�迭�� Ȧ�� ��° �迭�� ���ؼ� �۾��� �����ϴ� for��
												//Ȧ���� ° ������ �迭�� ������ �ش��ϴ� ���� ���ʴ�� x1 x10 x100 (10�� ����)�� �ϸ鼭 result2�� ��� �����ش�. 

		result2 += arr3[i] * (p / 10);
		p = p * 10;
		i = i - 1;
	}

	cout << "output: " << result1 + result2;	//result1�� result2�� ���� ���ؼ� �Է� ���ڷ� �̷���� �� ������ ������ �ִ� �հ踦 ���
	cout << endl;				
	return 0;
}



void dessort(char *arr, int n) {	//�������� ���ִ� �Լ�

	int temp = 0;

	for (int i = 9; i < 9 + n; i++) {		//arr�迭 9��°���� input��(����)���� ����ֱ� ������ i = 9 ���� ����
		for (int j = 9; j < 9 + n; j++) {	//2���� for���� ���鼭 ū�ź��� ���ʴ�� ����
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}