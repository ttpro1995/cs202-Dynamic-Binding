#include <iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"A constructor"<<endl;
	}
	A(int i){
		cout<<"A constructor with" <<i<<endl;
	}
	A(const A& src){
		cout<<"A copy constructor"<<endl;
	}
	A& operator=(const A& rhs){
		cout<<"Assignment of A"<<endl;
	}
	~A(){
		cout<<"A destructor"<<endl;
	}
	virtual void doSth(int i=7) const{
		cout<<"A::doSth with"<<i<<endl;
	}
};
class B: public A{
public:
	B():A(1){
		cout<<"B constructor"<<endl;
	}
	B& operator=(const B& rsh){
		cout<<"Assignment of B"<<endl;
	}
	void doSth(int i) const {
		cout<<"B::doSth with"<<i<<endl;
	}
	~B(){
		cout<<"B destructor"<<endl;
	}
};
void test(const A&a){
	A a2=a;
	a2.doSth(2);
	a.doSth(5);
}
int main(){
	B memberb;
	A membera=memberb;
	test(memberb);
	membera.doSth();
	cout<<"Finished"<<endl;
	return 0;
}
/*
A constructor with1
B constructor
A copy constructor
A copy constructor
A::doSth with2
B::doSth with5
A destructor
A::doSth with7
A destructor
B destructor
A destructor
*/