
#include<iostream>

int main(void) {

	long int num = 0;

	while (1) {

		std::cout << "判別する数値を入力(終了:0): ";
		std::cin >> num;
		
		if (num == 0) {   //ここの0は文字リテラルが入力された際にバグらせないためでもある

			std::cout << "終了します";
			break;
		
		}
		
		std::cout << num << "は " << (num % 2 ? "奇数" : "偶数") << " です。\n" << std::endl;

	}
	return 0;
}

