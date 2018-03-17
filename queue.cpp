#include<iostream>
#include<stdlib.h>
using namespace std;

class queue
{
	int info;
	queue *next;
public:
	queue(int n=0)
	{
		info=n;
		next=NULL;
	}

	void traverse(void);
	void enqueue(int n);
	void dequeue(queue* &first);

};

void queue::traverse(void)
{
 	queue *trav_ptr=this;
	while(trav_ptr != NULL)
	{
		cout<<trav_ptr->info<<'\t';
		trav_ptr=trav_ptr->next;
	}
}

void queue::enqueue(int n)
{
	queue *trav_ptr=this;
	queue *new_node=new queue(n);
	while(trav_ptr->next != NULL)
	{
		trav_ptr=trav_ptr->next;
	}
	trav_ptr->next=new_node;
}

void queue::dequeue(queue* &first)
{
 	queue *trav_ptr=this;
	queue *temp=trav_ptr->next;
	if(trav_ptr != NULL)
		first=temp;
	else
		{cout<<"QUEUE IS EMPTY !!";exit(0);}
	free(trav_ptr);
}

main()
{
	queue *first=new queue(1);
	next:

	cout<<"\nPRESS 1 : LIST ALL ELEMENTS OF QUEUE "<<endl;
 	cout<<"PRESS 2 : ENQUEUE "<<endl;
	cout<<"PRESS 3 : DEQUEUE "<<endl;
	cout<<"PRESS 4 : EXIT "<<endl;

	int choice;
	cout<<"Enter your choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			first->traverse();
			break;
		}
		case 2:
		{
			int n;
			cout<<"Enter element for queue : ";
			cin>>n;
			first->enqueue(n);
			first->traverse();
			break;
		}
		case 3:
		{
			first->dequeue(first);
			first->traverse();
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
	}
	goto next;

}
