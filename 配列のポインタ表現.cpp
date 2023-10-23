#include <iostream>
using namespace std;

// クラスの宣言
class Array {
private:
	const static int size = 6;
	int array[size];
public:
	Array( );
	int getSize( );
	void put( int index, int data );
	int get( int index ); 
	void swap( int index1 , int index2 );
};

// コンストラクタの定義
Array::Array( ) {
	for ( int i = 0; i < size; i++ ) {
	  *(array + i) = 0;
	}
}

// 配列のサイズを返す関数
int Array::getSize( ) {
	return size;
}

// index 番目の配列要素に data の値を代入する関数
void Array::put( int index, int data ) {
  *(array + index) = data;
}

// index 番目の配列要素の値を返す関数
int Array::get( int index ) {
  return *(array + index);
}

// index1 番目の配列要素と index2 番目の配列要素を交換する関数
void Array::swap( int index1, int index2 ) {
	
  int temp = *(array + index1);
  *(array + index1) = *(array + index2);
  *(array + index2) = temp;
	
}

int main( ) {
	Array myArray;
	
	myArray.put(1, 2);
	myArray.put(4, 1);
	
	cout << "配列の中身: " << endl << "| ";
	for ( int i = 0; i < myArray.getSize(); i++ ) {
		cout << myArray.get(i) << " | ";
	}
	cout << endl;
	
	// 以下 swap 関数テスト用
	myArray.swap(0, 4);
	cout << "交換後の配列の中身: " << endl << "| ";
	for ( int i = 0; i < myArray.getSize(); i++ ) {
		cout << myArray.get(i) << " | ";
	}
	cout << endl;
	
	return 0;
}
