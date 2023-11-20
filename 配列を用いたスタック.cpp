#include <iostream>
using namespace std;

class Stack {
private:
    int size;    // スタックのサイズ
    int top;    // データを積む位置
    int *stack;    // 配列の先頭アドレス
public:   
    Stack( int _size );
    ~Stack( );
    bool isFull( );
    bool isEmpty( );
    void push( int data );
    int pop( );
    void print( );
};

// コンストラクタの定義
Stack::Stack( int _size ) {

  size = _size;
  top = 0;
  stack = new int[size];
	
};

// デストラクタの定義
Stack::~Stack( ) {
    delete [] stack;
};

// スタックが一杯か否かを返す関数
bool Stack::isFull( ) {

  return size == top;
}

// スタックが空か否かを返す関数
bool Stack::isEmpty( ) {

  return top == 0;	
}

// 新たなデータをスタックの一番上に積む関数
void Stack::push( int data ) {

    stack[top++] = data;
}

// スタックの一番上のデータを取り出す関数
int Stack::pop( ) {

  int popedData = stack[--top];
  return popedData;
}

// スタックの内容を表示する関数
void Stack::print( ) {
    cout << "スタックの内容: ";
    for( int i = top - 1; i >= 0; i-- ) {
        cout << stack[i] << " ";
    }
    cout << endl;    
}

int main ( ) {
    Stack s1( 5 );
    int option, newData;
    bool flag = 1;
    
    while( flag ) {
        cout << "1:Push, 2:Pop, 3:スタックの内容を表示, 4:停止 >> ";
        cin >> option;
        if ( option == 1 ) {
            cout << "追加するデータを入力してください: ";
            cin >> newData;
            if(!s1.isFull()) {
                s1.push( newData );
                cout << newData << " をスタックに追加しました. " << endl;
            }
            else{
                cout << "スタックが一杯です. データを追加できません. " << endl;
            }
        }
        else if ( option == 2 ) {
	  if(!s1.isEmpty()) {
                cout << s1.pop( ) << " をスタックから取り出しました. " << endl;
            }
            else{
                cout << "スタックは空です. データを取り出せません. " << endl;
            }
        }
        else if ( option == 3 ) {
	  if(!s1.isEmpty()) {
                s1.print( );
            }
            else{
                    cout << "スタックは空です. データを表示できません. " << endl;
            }
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
