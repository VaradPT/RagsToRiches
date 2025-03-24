#include <iostream>
using namespace std;
int main()
{
     cout<<"Hello world";
     
     getSum(2,10);
       
}
/*Keywords used sofar :
Datatypes: int, bool, char, long, string,
endl:? gobal:? using namespace std:? */
const int n=5;//Value cannot change after initialization
int num=9; 
char al='a';
string sr="Stringg";
long ln;
double db;

void funct()
{
    //Function
}

void getSum(int a, int b)
{
    int sum = a+b;
    cout<<"The sum is: "<<sum;
}

class Car
{
    string Brand;
    string Model;
    int year;
};