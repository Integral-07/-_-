
#include<iostream>

int main(void) {

	long int num = 0;

	while (1) {

		std::cout << "���ʂ��鐔�l�����(�I��:0): ";
		std::cin >> num;
		
		if (num == 0) {   //������0�͕������e���������͂��ꂽ�ۂɃo�O�点�Ȃ����߂ł�����

			std::cout << "�I�����܂�";
			break;
		
		}
		
		std::cout << num << "�� " << (num % 2 ? "�" : "����") << " �ł��B\n" << std::endl;

	}
	return 0;
}

