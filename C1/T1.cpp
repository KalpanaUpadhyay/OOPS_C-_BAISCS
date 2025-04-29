#include<iostream>
using namespace std;

class Book
{
private:
	string title;
	string author;
	double price;

public:
	void setDetails(string t,string a,double p)
	{
	  title = t;
	  author = a;
	  price = p;
	}

	void displayDeatils()
	{
	  cout<<"Book Title: "<<title<<endl;
	  cout<<"Author: "<<author<<endl;
	  cout<<"Price: Rs."<<price<<endl;
        }
};

int main()
{
   Book b1;
   b1.setDetails("The Alchimist","Paulo Coelho",200);
   b1.displayDeatils();

   return 0;
}
