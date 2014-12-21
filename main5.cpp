#include <iostream>
using namespace std;

class B{
public:
	B(){
		cout<<"B: default constructor"<<endl;
	}
	B(int t){
		cout<<"B: constructor with 1 argument"<<endl;
	}
	~B(){
		cout<<"B: destructor"<<endl;
	}
	virtual void doSth(){
		cout<<"B: do sth"<<endl;
	}
	B(const B& src){
		cout<<"B: copy constructor"<<endl;
	}
	B& operator=(const B& src){
		cout<<"B:operator="<<endl;
	}
protected:int x;
private:int y;
};
class D:public B{
public:
	D(){
		cout<<"D: default construct	or"<<endl;
	}
	D(int k,int h):B(h){
		cout<<"D: constructor with 2 argument"<<endl;
	}
	D(const D& src){
		cout<<"D: copy constructor"<<endl;
	}
	~D(){
		cout<<"D: destructor"<<endl;
	}
	void doSth(){
		cout<<"D: do sth"<<endl;
	}
	D& operator=(const D& src){
		B::operator=(src);
		cout<<"D:operator="<<endl;
	}
private:int z;
};

int main(){
	cout<<"Part A:"<<endl;
	D d(4,7);
	D x=d;
	cout<<"Part B:"<<endl;
	B* pb;
	pb=&x;
	pb->doSth();
	cout<<"Finished"<<endl;
	return 0;
}

/*
Part A:
B: constructor with 1 argument
D: constructor with 2 argument
B: default constructor
D: copy constructor
Part B
D: do sth
Finished
D: destructor
B: destructor
D: destructor
B: destructor
*/
