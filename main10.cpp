#include<iostream>
using namespace std;
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

Finished
Base Destructed with m_i 3
Base Destructed with m_i 5
Derived Destructed with m_i 2
Base Destructed with m_i 2
*/


//derived go first then base class
/*correct answer
Base Constructed with m_i 2
Base Constructed with m_i 3
Base Constructed with m_i 5
Derived Constructed with m_i 2

Finished
Derived Destructed with m_i2
Base Destructed with m_i5
Base Destructed with m_i3
Base Destructed with m_i2
Press any key to continue . . .

*/