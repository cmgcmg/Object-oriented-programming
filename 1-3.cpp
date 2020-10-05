#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void initialization();		//�������� 1~25�� �ʱ�ȭ �ϴ� �Լ�
void shuffle();				//������� �Ǿ��ִ� �������� �����ִ� �Լ�
void show();				//�������� ����ϴ� �Լ�
void bingocheck();			//���� �� ���� ���� 1���� �ִ��� Ȯ���ϴ� �Լ�
void usercall();			//������ ���ڸ� �Է��ϴ� �κп� �ش��ϴ� �Լ�
void comcall();				//��ǻ�Ͱ� ���ڸ� �Է��ϴ� �κп� �ش��ϴ� �Լ�

int user[5][5] = {};		//User �������� ����� ���ؼ� 2���� �迭�� ���
int computer[5][5] = {};    //computer �������� ����� ���ؼ� 2���� �迭�� ���
int userbingo = 0;			//User ������� üũ�ϱ� ���� ���� ����
int combingo = 0;			//Computer ������� üũ�ϱ� ���� ���� ����
int n = 0;					//�Է¹޴� ���� �ش��ϴ� ���� ���� , ��ǻ�Ϳ� ���� ��� ���
int checkarray[25] = { 0, };//�ߺ��� ���� Ȯ���ϱ� ���� �迭 �ϳ��� ��� (0~24���� 1~25�� ���� �Ǿ��ִ�.)

int main() {
	srand((unsigned int)time(0)); //���α׷� ����� �׻� �ٸ� ������ �����ϱ� ���� �κ�
	initialization();			  //�����ǰ� �ߺ��ȼ��� Ȯ���ϴ� �迭�� �ʱ�ȭ
	shuffle();				      //�������� �����ϰ� �����ش�.

	while (true) { //While���� ���ؼ� ��������� ����

		show();	//�������� ���
		if (userbingo == 1 && combingo != 1) { cout << "BINGO!! User Win" << endl; break; } //User�� ���� ������ ��� Stop
		else if (userbingo != 1 && combingo == 1) { cout << "BINGO!! Computer Win" << endl; break; } //Computer�� ���� ������ ��� Stop
		else if (userbingo == 1 && combingo == 1) { cout << "Both BINGO!! Both Win" << endl; break; } //User�� Computer ���ÿ� ���� �Ǿ��� ��� Stop
		usercall();		//������� �Է�
		show();			//������ �������� ���
		if (userbingo == 1 && combingo != 1) { cout << "BINGO!! User Win" << endl; break; } //User�� ���� ������ ��� Stop
		else if (userbingo != 1 && combingo == 1) { cout << "BINGO!! Computer Win" << endl; break; } //Computer�� ���� ������ ��� Stop
		else if (userbingo == 1 && combingo == 1) { cout << "Both BINGO!! Both Win" << endl; break; } //User�� Computer ���ÿ� ���� �Ǿ��� ��� Stop
		comcall();		//Computer�� �Է�
		bingocheck();	//�������� üũ
	}
	return 0;
}

void initialization() //�������� 1~25�� �ʱ�ȭ �ϴ� �Լ�
{					  //�������� 1��1������ 5��5������ �ΰ��� for���� ���ؼ� �ʱ�ȭ
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			user[i][j] = (i * 5)+j + 1;
			computer[i][j] = (i * 5)+j + 1;
		}
	}

	for (int i = 0; i < 25; i++) {
		checkarray[i] = i + 1;
	}				//checkarray�迭 0������ 24�������� 1~25�� for���� ���ؼ� �ʱ�ȭ
}

void shuffle() {  //������� �Ǿ��ִ� �������� �����ִ� �Լ�

	for (int i = 0; i < 100; i++) { //user �������� �����ִ� ������ ������ �ϱ� ���� for��
		int rand1 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int rand2 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int rand3 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int rand4 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int temp = 0;
		//������ �迭 ���� 2���� �̾Ƽ� �ڸ��� �ٲ��ִ� ������� �������� ���´�.
		temp = user[rand1][rand2];
		user[rand1][rand2] = user[rand3][rand4];
		user[rand3][rand4] = temp;
	}

	for (int i = 0; i < 100; i++) { //computer �������� �����ִ� ������ ������ �ϱ� ���� for��
		int rand1 = rand() % 5;	//1~25���� �����Լ��� �߻���Ų��.
		int rand2 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int rand3 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int rand4 = rand() % 5; //1~25���� �����Լ��� �߻���Ų��.
		int temp = 0;
		//������ �迭 ���� 2���� �̾Ƽ� �ڸ��� �ٲ��ִ� ������� �������� ���´�.
		temp = computer[rand1][rand2];
		computer[rand1][rand2] = computer[rand3][rand4];
		computer[rand3][rand4] = temp;
	}
}

void show() { //�������� ����ϴ� �Լ�

	cout << "<user bingo board>";
	cout << endl;

	for (int i = 0; i < 5; i++) { //1��1������ 5��5������ user �������� ����ϱ� ���� 2���� for��
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == '#')
				cout << (char)user[i][j] << "\t"; //���ڰ� �¾��� �� int���� �ƴ� '#'�� ����ؾ��ϹǷ� char
			else
				cout << user[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "<computer bingo board>";
	cout << endl;

	for (int i = 0; i < 5; i++) { //1��1������ 5��5������ computer�������� ����ϱ� ���� 2���� for��
		for (int j = 0; j < 5; j++) {
			if (computer[i][j] == '#')
				cout << (char)computer[i][j] << "\t"; //���ڰ� �¾��� �� int���� �ƴ� '#'�� ����ؾ��ϹǷ� char
			else
				cout << computer[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void bingocheck() { //User�� Computer�� �����ǿ��� ����1�� �Ǵ� ����1���� �������� Ȯ���ϴ� �Լ�

	for (int i = 0; i < 5; i++) {
		int userrow = 0;	//User�� ���ΰ� �������� üũ�� ���� ���� �� �ʱ�ȭ
		int usercal = 0;	//User�� ���ΰ� �������� üũ�� ���� ���� �� �ʱ�ȭ
		int comrow = 0;		//Computer�� ���ΰ� �������� üũ�� ���� ���� �� �ʱ�ȭ
		int comcal = 0;		//Computer�� ���ΰ� �������� üũ�� ���� ���� �� �ʱ�ȭ

		for (int j = 0; j < 5; j++) {
			if (user[i][j] == '#') {	
				userrow++;	//User�� ���ΰ� ������ ���
			}
			if (computer[i][j] == '#') {
				comrow++;	//Computer�� ���ΰ� ������ ���
			}
			if (user[j][i] == '#') {
				usercal++;	//User�� ���ΰ� ������ ���
			}
			if (computer[j][j] == '#') {
				comcal++;	//Computer�� ���ΰ� ������ ���
			}
		}
		if (userrow == 5 || usercal == 5) {
			userbingo = userbingo + 1;	//User�� ���γ� ���ΰ� ������ ��� Userbingo = 1
		}
		if (comrow == 5 || comcal == 5) {
			combingo = combingo + 1;	//Computer�� ���γ� ���ΰ� ������ ��� Combingo = 1
		}
	}
}

void usercall() { //User�� Input���� �ִ� �κ�

	cout << "Call a Number(1~25) : ";
	cin >> n;

	if (n < 1) {						//������ �θ��� ���� 1~25�̱� ������ ����ó���� �κ�
		cout << "Call 1~25 : " << endl;
		cin >> n;
	}
	if (n > 25) {						//������ �θ��� ���� 1~25�̱� ������ ����ó���� �κ�
		cout << "Call 1~25 : ";
		cin >> n;
	}
	if (checkarray[n - 1] == 0) {		//������ �ߺ��� ���� �Է����� ��쿡 ����ó���� �κ�
			cout << "�̹� �Է��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
			cin >> n;
		}
	
	checkarray[n - 1] = 0;				//User�� �θ� ���� 1~25�� ����ִ� Checkarray���� 0���� �ʱ�ȭ���ش�.
										//�ߺ��� ���� �߻���Ű�� �������� �ۼ��� �κ�

	for (int i = 0; i < 5; i++) {		//User�� �θ� ���� User�� Computer �����ǿ� �ִ� ���� ���ٸ� '#'ó��
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == n) user[i][j] = '#';
			if (computer[i][j] == n) computer[i][j] = '#';
		}
	}
}

void comcall() {		//Computer�� Input�� �Է��ϴ� �κ�

	while (1) {		//�̹� ����ߴ� ���� �����ϰ� 1~25�� ����ϱ� ���� While��
		n = rand() % 25 + 1;	//1~25���̿� ������ ����
		if (checkarray[n - 1] == 0) {	//���� ���� �̹� �ҷ������� ���� �ٽ� ������ ����
			n = rand() % 25 + 1;
		if (checkarray[n - 1] != 0) {	//���� ���� �̹� �ҷ������� ���� �ƴϸ� While���� Ż��
				break;
			}
		}
	}
	checkarray[n - 1] = 0;				//Computer�� �θ� ���� 1~25�� ����ִ� Checkarray���� 0���� �ʱ�ȭ���ش�.
										//�ߺ��� ���� �߻���Ű�� �������� �ۼ��� �κ�
	cout << "Computer Calls : " << n << endl; //Computer�� �θ� ���� ���

	for (int i = 0; i < 5; i++) {		//Computer�� �θ� ���� User�� Computer �����ǿ� �ִ� ���� ���ٸ� '#'ó��
		for (int j = 0; j < 5; j++) {
			if (user[i][j] == n) user[i][j] = '#';
			if (computer[i][j] == n) computer[i][j] = '#';
		}
	}
}







