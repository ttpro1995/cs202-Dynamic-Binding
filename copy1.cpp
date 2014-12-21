#include<iostream>
using namespace std;
//
class A
{
public:
	A(){
		cout << "A constructor" << endl;
	}
	A(int i){
		cout << "A constructor with" << i << endl;
	}
	A(const A& src){
		cout << "A copy constructor" << endl;
	}

	~A()
	{
		cout << "A del\n";
	}

};

class B :public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}

	~B()
	{
		cout << "B del\n";
	}
};

class C :public A
{

public:
	C(){
		cout << "C constructor" << endl;
	}

	C(const C& src){
		cout << "C copy constructor" << endl;
	}
	~C()
	{
		cout << "C del\n";
	}

};


int main()
{
	/*
	cout << "Lot of A \n";
	A aa1;
	A aa2;
	A aa3;
	A aa4;
	A aa5;
	*/
	cout << "Part 1\n";
	C cc;
	C ccc = cc;//default construtor of A then copy constructor of B
	cout << "part 2\n";
	B bb;
	B bbb = bb;// copy constructor of A (anthing else ?) 
	
	
		cout << "Lot of A \n";
	A Aa1;
	A Aa2;
	A Aa3;
	A Aa4;
	A Aa5;

	cout << "Finished \n";

	return 0;

	//what create last will be delete first 
}

/*
Part 1
A constructor
C constructor
A constructor
C copy constructor
part 2
A constructor
B constructor
A copy constructor
Lot of A
A constructor
A constructor
A constructor
A constructor
A constructor
Finished
A del
A del
A del
A del
A del
B del
A del
B del
A del
C del
A del
C del
A del
Press any key to continue . . .

*/