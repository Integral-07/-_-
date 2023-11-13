#include <iostream>
using namespace std;

// クラスの宣言
class Cell {
	friend class Stack;    // Stackクラスから，このクラスに自由にアクセスできるようにする
private:
	int data;    // データ
	Cell *next;    // 次のセルのアドレスを指すポインタ
public:
	Cell( int _data, Cell *_next );
};

class Stack {
private:
	Cell *top;    // スタックの一番上の要素のアドレスを指すポインタ
public:   
	Stack( );
	~Stack( );
	void push( int data );
	int pop( );
	void print( );
};

// コンストラクタの定義
Cell::Cell( int _data, Cell *_next = NULL ) {
	data = _data; 
	next = _next;
}

Stack::Stack( ) {
	top = NULL; 
};

// デストラクタの定義
Stack::~Stack( ) {
	while( top != NULL ) {
		pop( );
	}
};

// 新たなデータをスタックの一番上に積む関数
void Stack::push( int data ) {

  top = new Cell(data, top);
  cout << data << "をスタックに追加しました" << endl;
	
}

// スタックの一番上のデータを取り出す関数
int Stack::pop( ) {

  if(top == NULL){

    cout << "スタックは空です.データを取り出せません." << endl;
    
    return -1;
  }
	
  int popedData = top->data;
  Cell* oldTop = top;
  top = top->next;

  delete oldTop;
  
  return popedData;	
}

// スタックの内容を表示する関数
void Stack::print( ) {
	if(top == NULL) {
		cout << "スタックは空です. データを表示できません. " << endl;
		return;
	}
	cout << "スタックの内容: ";
	for( Cell* p = top; p != NULL ; p = p->next ) {
		cout << p->data << " ";
	}
	cout << endl;
}

int main( ) { 
	Stack s1;
	int option, newData;
	bool flag = 1;
	
	while(flag) {
		cout << "1:Push, 2:Pop, 3:スタックの内容を表示, 4:停止 >> ";
		cin >> option;
		if ( option == 1 ) {
			cout << "追加するデータを入力してください: ";
			cin >> newData;
			s1.push( newData );
		}
		else if ( option == 2 ) {
			int value = s1.pop( );	
			if ( value != -1 ) {
				cout << value << " をスタックから取り出しました. " << endl;
			}
		}
		else if ( option == 3 ) {
			s1.print( );
		}
		else if ( option == 4 ) {
			flag = 0;
		}
		else {
			cout << "1〜4 の数字を入力してください. " << endl;
		}
	}
		
	return 0;
} 

