#include <iostream>
#include <vector>

using namespace std;

class Array {
private:
    vector<int> array;
public:
    void insert( int value ){ array.push_back( value ); }
    int getSize( ){ return (int)array.size( ); }
    void selection_sort(  );
    void insertion_sort(  );
    void bubble_sort(  );
    void print(  );
};

// 選択ソートを行う関数
void Array::selection_sort( ) {

  for(int i=0; i<array.size()-1; i++){

    int min = i;
    for(int j=i+1; j<array.size(); j++){

      if(array[min] > array[j]){

	min = j;
      }
    }
    swap(array[i], array[min]);
  }
} 

// バブルソートを行う関数
void Array::bubble_sort( ) {

  for(int i=0; i<array.size(); i++){
    for(int j=array.size()-1; j > i ; j--){

      if(array[j-1] > array[j]){

        //int temp = array[j];
        //array[j] = array[j+1];
        //array[j+1] = temp;
	swap(array[j-1], array[j]);
      }
    }
  }
	
}

// 挿入ソートを行う関数
void Array::insertion_sort( ) {

    for (int i = 1; i < array.size() ; i++) {
        int key = array[i];
        int j = i - 1;

	for(; j>=0 && array[j]>key ;j--){

	  array[j+1] = array[j];
	}

	array[j + 1] = key;
    }
	
}

// 配列の内容を表示する関数
void Array::print(  ) {
    for ( int i = 0; i < (int)array.size( ); i++ ) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(  ) {

    Array a1;

    a1.insert( 56 );
    a1.insert( 34 );
    a1.insert( 57 );
    a1.insert( 64 );    
    a1.insert( 3 );   
    a1.insert( 87 );
    a1.insert( 85 );
    a1.insert( 37 );
    a1.insert( 21 );    
    a1.insert( 4 );   
    a1.insert( 68 );
    a1.insert( 62 );
    a1.insert( 42 );
    a1.insert( 55 );    
    a1.insert( 63 );    
    a1.insert( 95 );
    a1.insert( 7 );
    a1.insert( 32 );
    a1.insert( 78 );    
    a1.insert( 11 );   

    cout << "要素数: " << a1.getSize( ) << endl;
    cout << "ソート前: ";
    a1.print(  );

    a1.selection_sort(  );    // ここで，ソートを行う関数を呼び出す

    cout << "ソート後: ";
    a1.print(  );       

    return 0;
}
