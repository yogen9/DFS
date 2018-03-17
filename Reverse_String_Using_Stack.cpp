#include<iostream>
#include<cstring>
using namespace std;
template<class T>
class stack
{
    T s[100];
    int tos;
public:
    stack(void)
    {
        tos=0;
    }
    void push(T a)
    {
        s[tos]=a;
        tos++;
    }
    T pop(void)
    {
        tos--;
        return s[tos];
    }
};

int main()
{
    stack<char> a;
    char str[100];
    cout<<"Enter the String : ";
    cin>>str;

    for(int i=0; i<strlen(str);i++)
        a.push(str[i]);

    cout<<"Reverse String : ";
    for(int i=0; i<strlen(str);i++)
       cout<<a.pop();


}
