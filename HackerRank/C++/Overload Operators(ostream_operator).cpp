/*
Problem:
https://www.hackerrank.com/challenges/overload-operators/problem

Resources:
https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
https://www.geeksforgeeks.org/operator-overloading-c/
https://pencilprogrammer.com/cpp-programs/add-subtract-complex-numbers-using-operator-overloading/
*/

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
Complex operator + (const Complex &number1, const Complex &number2)
{
    Complex result;
    result.a = number1.a + number2.a;
    result.b = number1.b + number2.b;
    return result;
}
//<< should print a complex number in the format "a+ib"
ostream &operator <<(ostream &out, const Complex &number)
{
    out << number.a;
    out << (number.b < 0 ? "-i" : "+i") << number.b << endl;
    return out;
}
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
