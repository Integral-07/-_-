#include <iostream>
using namespace std;

// クラスの宣言
class Node {
    friend class BinaryTree;    // BinaryTree クラスから，このクラスに自由にアクセスできるようにする
private:
    int data;    // データ
    Node *left;    // 左の子ノードを指すポインタ
    Node *right;    // 右の子ノードを指すポインタ
public:
    Node( int _data );
};

class BinaryTree {
private:
    Node *root;    // 二分探索木の根のノードを指すポインタ
public:   
    BinaryTree( );
    ~BinaryTree( );
    void insertNode( int d ) { root = insertNode( root, d ); }
    Node *insertNode( Node *r, int d );
    void printInorder(  ){ printInorder( root ); }
    void printInorder( Node *r );
    void printPreorder(  ){ printPreorder( root ); }
    void printPreorder( Node *r );
    void printPostorder(  ){ printPostorder( root ); }
    void printPostorder( Node *r );
    Node *removeAll( Node *r );
};

// コンストラクタの定義
Node::Node( int _data ) {
    data = _data; 
    left = NULL;
    right = NULL;
}

BinaryTree::BinaryTree( ) {
    root = NULL; 
};

// デストラクタの定義
BinaryTree::~BinaryTree( ) {
    root = removeAll( root );
};

// 二分探索木のノード r 以下の部分木にデータ d を挿入する関数
Node * BinaryTree::insertNode( Node *r, int d ) {

  if( r == NULL ){

    r = new Node( d );

  }
  else if(r->data > d){
    
    r->left = insertNode(r->left, d);
    
  }
  else{

    r->right = insertNode(r->right, d);
  }

  return r;
}

// 二分探索木のノード r 以下の部分木をインオーダーでなぞり，データを表示する関数
void BinaryTree::printInorder( Node *r ) {

  if( r == NULL ){
    
    return;
  }
  else{

    printInorder( r->left );
    cout << r->data << " ";   
    printInorder( r->right );
  }
}

// 二分探索木のノード r 以下の部分木をプリオーダーでなぞり，データを表示する関数
void BinaryTree::printPreorder( Node *r ) {

  if( r == NULL ){

    return;
  }
  else{

    cout << r->data << " ";
    printPreorder( r->left );
    printPreorder( r->right );
  }
	
}

// 二分探索木のノード r 以下の部分木をポストオーダーでなぞり，データを表示する関数
void BinaryTree::printPostorder( Node *r ) {

  if( r == NULL ){

    return;
  }
  else{

    printPostorder( r->left );
    printPostorder( r->right );
    cout << r->data << " ";
  }
	
}

// 二分探索木のノード r 以下の部分木をすべて削除する関数
Node * BinaryTree::removeAll( Node *r ) {

  if( r == NULL ){

    return r;
  }
  else{

    if( r->left != NULL ){

      r->left = removeAll( r->left );
    }
    if( r->right != NULL ){

      r->right != removeAll( r->right );
    }

    cout << r->data << "was deleted." << endl;
    delete r;
    r = NULL;
    return r;
  }
	
}

int main(  ) {
    BinaryTree bt1;
    int option;

    bt1.insertNode( 9 );
    bt1.insertNode( 3 );
    bt1.insertNode( 6 );
    bt1.insertNode( 2 );
    bt1.insertNode( 5 );
    bt1.insertNode( 1 );
    bt1.insertNode( 7 );
    bt1.insertNode( 55 );
    bt1.insertNode( 63 );
    bt1.insertNode( 24 );
        
    cout << "二分探索木のデータを表示します．\n1: インオーダー, 2: プリオーダー, 3: ポストオーダー >> ";
    cin >> option;
           
    if(option == 1) {
        bt1.printInorder( );
        cout << endl;
    }
    else if(option == 2) {
      //bt1.printPreorder( );
        cout << endl;
    }
    else if(option == 3) {
      //bt1.printPostorder( );
        cout << endl;
    }
    else {
        cout << "1〜3　の数字を入力してください. " << endl;
    }
    return 0;
}
