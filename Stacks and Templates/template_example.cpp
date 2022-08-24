#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Pair{

	T x;
	T y;

public:
	void setX(T x){
		this->x = x;
	}

	void setY(T y){
		this->y = y;
	}

	T getX(){
		return this->x;
	}

	T getY(){
		return this->y;
	}
};

template <typename T, typename V>
class diffPair{
	T x;
	V y;

public:
	void setX(T x){
		this->x = x;
	}

	void setY(V y){
		this->y = y;
	}

	T getX(){
		return this->x;
	}

	V getY(){
		return this->y;
	}
};


int main(){
	Pair<int> p1;
	p1.setX(10);
	p1.setY(20);

	cout<<p1.getX()<<" "<<p1.getY()<<endl;

	Pair<double> p2;
	p2.setX(1.20);
	p2.setY(2.40);

	cout<<p2.getX()<<" "<<p2.getY()<<endl;

	diffPair<int,double> dp1;
	dp1.setX(10);
	dp1.setY(20.12);

	cout<<dp1.getX()<<" "<<dp1.getY()<<endl;

	diffPair <int, diffPair<double,char>> tp1;

	tp1.setX(10);

	diffPair <double,char> tp2;

	tp2.setX(20.23);
	tp2.setY('a');

	tp1.setY(tp2);

	cout<<tp1.getX()<<" "<<tp1.getY().getX()<<" "<<tp1.getY().getY()<<endl;
}