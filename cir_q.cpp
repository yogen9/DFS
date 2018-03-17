#include<iostream>
using namespace std;

int front=0,rear=-1;
int q[5];

void add(int n)
{
	rear++;
	q[rear%5]=n;
	cout<<"FRONT : "<<front<<'\t'<<"REAR : "<<rear<<endl;
}

int remove(void)
{
	front++;
	cout<<"FRONT : "<<front<<'\t'<<"REAR : "<<rear<<endl;
	int temp=q[(front-1)%5];
	q[(front-1)%5]=555;
	return temp;
}

void traverse(void)
{
	for(int i=0;i<rear;i++)
	{
		cout<<q[i%5]<<'\t';
	}
}

main()
{
	add(1);
     	add(2);
	add(3);
	add(4);
	add(3);
	add(4);
	traverse();
	cout<<remove();
	cout<<remove();
	cout<<remove();
	cout<<remove()<<endl;
	traverse();
}
