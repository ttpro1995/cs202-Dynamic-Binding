#include<iostream>
using namespace std;
class neutral1
{
public:
neutral1()
{
cout<<"neutral1 constructor \n";
}
~neutral1()
{
cout<<"neutral1 destructor \n";
}
}

class A
{
  public:
    A(int n=2): m_i(n)
    {
       std::cout<<"Base Constructed with m_i "<<m_i<<endl;
    }
    ~A()
    {
    cout<<"Base Destructed with m_i"<<m_i<<endl
  
    }

  protected:
   int m_i;//2
};

class B: public A
{
  public:
   B(int n ): m_a1(m_i  + 1), m_a2(n)
   {
     cout<<"Derived Constructed with m_i "<<m_i<<std::endl;
   }

   ~B()
   {
     std::cout<<"Derived Destructed with m_i"<<m_i<<std::endl; 
   }

  private:
   A m_a1;//3
   A m_a2;//5
   neutral1 Neu1;
};

int main()
{
   B b(5);
  cout<<"\nFinished\n";
  return 0;
}
/*
Base Constructed with m_i 2
Base Constructed with m_i 3
Base Constructed with m_i 5
Derived Constructed with m_i 2
neutral1 constructor 

Finished
Derived Destructed with m_i 2
Base Destructed with m_i 3
Base Destructed with m_i 5
neutral1 destructor
Base Destructed with m_i 2
*/

/*Correct answer

Base Constructed with m_i 2
Base Constructed with m_i 3
Base Constructed with m_i 5
neutral1 constructor 
Derived Constructed with m_i 2

Finished

Derived Destructed with m_i 2
neutral1 destructor
Base Destructed with m_i 5
Base Destructed with m_i 3
Base Destructed with m_i 2

*/
//constructor order
/*A base class construct go first
from top to bottom in definition order in B
then B constructor
*/