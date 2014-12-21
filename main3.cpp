#include <iostream>
using namespace std;

class Base{
public:
	Base(){
		cout<<"Base constructor"<<endl;
	}
	virtual void print()=0;
};
class DerivedA:public Base{
public:
	DerivedA(int x){
		cout<<"DerivedA constructor"<<endl;
		a=x;
	}
	void print(){
		cout<<"DerivedA = "<<a<<endl;
	}
private:
	int a;
};
class DerivedB:public Base{
public:
	DerivedB(int x){
		cout<<"DerivedB constructor"<<endl;
		b=x;
	}
	void print(){
		cout<<"DerivedB = "<<b<<endl;
	}
private:
	int b;
};

class Project{
public:
	Project(){
		cout<<"Project constructor"<<endl;
		listObj=new Base*[3];
		listObj[0]=new DerivedA(2);
		listObj[1]=new DerivedB(5);
		listObj[2]=new DerivedA(10);
	}
	~Project(){
		for(int i=0;i<3;i++)
			delete listObj[i];
		delete []listObj;
		cout<<"Project destructor"<<endl;
	}
	void process(){
		for(int i=0;i<3;i++){
			listObj[i]->print();
		}
	}
private:
	Base **listObj;
};
int main(){
	Project p;
	p.process();
	return 0;
}

/*
Base constructor
DerivedA constructor
Base constructor
DerivedB constructor
Base constructor
DerivedA constructor
DerivedA = 2 
DerivedB = 5
DerivedA = 10
Project destructor

*/

