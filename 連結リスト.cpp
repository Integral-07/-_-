#include <iostream>
using namespace std;

// クラスの宣言
class Cell {
	friend class List;    // List クラスから，このクラスに自由にアクセスできるようにする
private:
	int data;    // データ
	Cell *next;    // 次のセルのアドレスを指すポインタ
public:
	Cell( int _data, Cell *_next );
};

class List {
private:
	Cell *head;    // 連結リストの先頭要素のアドレスを指すポインタ
public:   
	List( );
	~List( );
	void addFirst( int data );
	void removeFirst( );
	void removeAt( int index );
	void print( );
};

// コンストラクタの定義
Cell::Cell( int _data, Cell *_next = NULL ) {
	data = _data; 
	next = _next;
}

List::List( ) {
	head = NULL; 
};

// デストラクタの定義
List::~List( ) {
	while( head != NULL ) {
		removeFirst( );
	}
};

// 新たなデータを連結リストの先頭に追加する関数
void List::addFirst( int data ) {
	
  Cell* p = head;
  head = new Cell(data);
  head->next = p;
	
}

// 連結リストの先頭の要素を削除する関数する関数
void List::removeFirst( ) {	
	Cell *target = head;
	if(target != NULL) {
		head = target->next;
		// cout << "データ " << target->data << " のセルを削除します. " << endl;    // 動作確認用
		delete target;
	}
}

// 連結リストの index 番目の要素を削除する関数
void List::removeAt( int index ) {


  if(head == NULL){

    return;

  }
  else if(index == 0){

    removeFirst();
    return;
  }

  Cell* target;
  Cell* prev;
  int current_index = 0;
  
  for(Cell* p=head; p!=NULL; p=p->next){

    if(current_index == index){

      target = p;

      prev->next = target->next;
      delete target;
      return;
    }

    prev = p;
    current_index++;
  }
	
}

// 連結リストの内容を表示する関数
void List::print( ) {
	
        cout << "リストの内容: ";
	
	for(Cell* p=head; p!=NULL ;p=p->next){

	  cout << p->data << ' '; 
	}
	
	cout << endl;
	
}

int main( ) { 
	List l1;
	for( int i = 0; i < 10; i++ ) {
			l1.addFirst( i );
	}
	
	l1.print();
	l1.removeAt( 0 );    // リストの先頭要素で動作確認
	l1.print();
	l1.removeAt( 2 );
	l1.print();
	l1.removeAt( 4 );
	l1.print();
	l1.removeAt( 17 );    // リストの要素数より大きな引数で動作確認
	l1.print();
	l1.removeAt( 0 );    // リストの先頭要素で動作確認
	l1.print();
	l1.removeAt( 6 );    // リストの要素数より大きな引数で動作確認
	l1.print();
	l1.removeAt( 5 );
	l1.print();
	
	return 0;
} 
