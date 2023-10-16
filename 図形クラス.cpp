#include<iostream>
#include<iomanip>
using namespace std;

const double PI = 3.1415;

// 図形の基本クラス
class Shape{
protected:
  double px;
  double py;

  string shapeType = ""; 

public:
  Shape(int _px, int _py):px(_px), py(_py){

  }

  string getShapeType(){

     return shapeType;
  }

  virtual double calcArea() = 0;
  double getLocationX(){ return px; }
  double getLocationY(){ return py; }

};


// 円クラス（図形クラスの派生クラス
class Circle : public Shape{
private:
  double r;

  string shapeType = "円";

public:
  Circle(double _px, double _py, double _r):Shape(_px, _py), r(_r){
  }

  double calcArea() override { return r*r*PI; }
};

// 正方形クラス（図形クラスの派生クラス）
class Square : public Shape{
private:
  double length;

  string shapeType = "正方形";

public:
  Square(double _px, double _py, double _len): Shape(_px, _py), length(_len){

  }

  double calcArea() override { return length * length; }
  
};


int main(){
    
    Circle c1( 1.0, 2.0, 3.0 );   // 引数は順に，位置の x 座標，位置の y 座標，円の半径
    Square s1( 2.0, 1.0, 2.0 );   // 引数は順に，位置の x 座標，位置の y 座標，一辺の長さ
    Circle c2( 3.0, 2.0, 2.0 );   // 引数は順に，位置の x 座標，位置の y 座標，円の半径

    cout << c1.getShapeType() << endl;
    cout << "位置: ( x, y ) = ( " << c1.getLocationX() << ", " << c1.getLocationY() << " )" << endl;
    cout << "面積: " << c1.calcArea() <<  endl;
    cout << endl;
    
    cout << s1.getShapeType() << endl;
    cout << "位置: ( x, y ) = ( " << s1.getLocationX() << ", " << s1.getLocationY() << " )" << endl;
    cout << "面積: "<< s1.calcArea() <<  endl;
    cout << endl;

    cout << c2.getShapeType() << endl;
    cout << "位置: ( x, y ) = ( " << c2.getLocationX() << ", " << c2.getLocationY() << " )" << endl;
    cout << "面積: " << c2.calcArea() <<  endl;    
    cout << endl; 
    
    return 0;
}
