#include <iostream>
using namespace std;

class Queue {
private:
    int size;    // キューのサイズ
    int front;    // キューの先頭位置
    int rear;    // キューの最後尾位置
    int count;    // キューに保存されているデータ数
    int *queue;    // 配列の先頭アドレス
public:   
    Queue( int _size );
    ~Queue( );
    bool isFull( );
    bool isEmpty( );
    void enqueue( int data );
    int dequeue( );
    void print( );
};

// コンストラクタの定義
Queue::Queue( int _size ) {

  size = _size;
  front = 0;
  rear = 0;
  count = 0;
  queue = new int[size];
	
};

// デストラクタの定義
Queue::~Queue( ) {
    delete [] queue;
};

// キューが一杯か否かを返す関数
bool Queue::isFull( ) {

  return size == count;
}

// キューが空か否かを返す関数
bool Queue::isEmpty( ) {

  return count == 0;
}

// 新たなデータをキューの最後尾に追加する関数
void Queue::enqueue( int data ) {
  
    queue[rear] = data;

    /*これ大事*/
    rear = (rear + 1) % size;//これ大事
    /*これ大事*/
    count++;
}

// キューの先頭のデータを取り出す関数
int Queue::dequeue( ) {

  int dequeuedData = queue[front];

  front = (front + 1) % size;
  count--;
  
  return dequeuedData;
}

// キューの内容を表示する関数
void Queue::print( ) {
    cout << "キューの内容: ";
    for( int i = 0; i < count; i++ ) {
        cout << queue[( front + i ) % size] << " ";
    }
    cout << endl;    
}

int main ( ) {
    Queue q1( 6 );
    int option, newData;
    bool flag = 1;
    
    while( flag ) {
        cout << "1:Enqueue, 2:Dequeue, 3:キューの内容を表示, 4:停止 >> ";
        cin >> option;
        if ( option == 1 ) {
            cout << "追加するデータを入力してください: ";
            cin >> newData;
            if(!q1.isFull()) {
                q1.enqueue( newData );
                cout << newData << " をキューに追加しました. " << endl;
            }
            else{
                cout << "キューが一杯です．データを追加できません. " << endl;
            }
        }
        else if ( option == 2 ) {
	  if(!q1.isEmpty()) {
                cout << q1.dequeue( ) << " をキューから取り出しました. " << endl;
            }
            else {
                cout << "キューは空です. データを取り出せません. " << endl;
            }
        }
        else if ( option == 3 ) {
	  if(!q1.isEmpty()) {
                q1.print( );
            }
            else{
                cout << "キューは空です. データを表示できません. " << endl;
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
