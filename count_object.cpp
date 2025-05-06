#include<iostream>
using namespace std;

class A
{
public:
	static int cnt; //most imp: otherwise in main it will be reset

	A()
       {
	 cnt++;
       }

       ~A()
       {
	 cnt--;
       }
};
// Initialize static variable outside the class
// In ISO C++ (pre-C++17), you cannot initialize non-const static members inside the class definition. You must initialize them outside the class.
int A::cnt = 0;

int main()
{
   A a;
   A b;
   A c;

   cout<<"Objects cnt: "<<A::cnt<<endl;
return 0;
}
