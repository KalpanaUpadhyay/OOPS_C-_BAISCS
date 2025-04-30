#include<iostream>
using namespace std;


class Person{
protected:
	string name;
	int age;

public:
	void setPerson(string s,int a)
	{
	   name = s;
	   age = a;
	}


	void getPerson()
	{
	  cout<<"Name: "<<name<<endl;
	  cout<<"Age: "<<age<<endl;
	}

};

class Student:public Person{
private:
	string university;

public:
	void setStudent(string s, int a, string u)
	{
		setPerson(s,a);
		university=u;
	}

	void getStudent()
	{

           getPerson();
	   cout<<"University: "<<university<<endl;
	}

};

int main()
{
	Student s1;
	s1.setStudent("Kalpana",24,"University Of Delhi");
        s1.getStudent();

return 0;

}
