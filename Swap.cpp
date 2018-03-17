#include<iostream>
using namespace std;

template<class T>
void swap(T *a,T *b){
    T temp;
    temp=*b;
    *b=*a;
    *a=temp;
    cout<<"a : "<<*a;
    cout<<"b : "<<*b;
}
int main(){

    int a;
    int b;
    cout<<"Enter the Value\n";
    cin>>a>>b;

    swap<int>(&a,&b);
}
