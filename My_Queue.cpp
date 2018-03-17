#include<iostream>
#include<cstdlib>
using namespace std;

class queue
{
    int front=0;
    int rear=0;
    float *a;
    int n=0;
public:
    queue(void){
        cout<<"Enter the total number of queue member: ";
        cin>>n;
        a=new float(n);
        for(int i=0;i<=n;i++)
            a[i]=0;
    }

    void enqueue(int m){
        if(rear==n)
            cout<<"Your queue is full"<<endl;
        else
            a[++rear]=m;
    }

    void dequeue(void){
        if(front==rear){
            cout<<"queue is empty"<<endl;
            front=0;
            rear=0;
        }
        else{
            cout<<"NO. "<< ++front<<" : ";
            cout<<a[front]<<endl;
            a[front]='\0';
        }
    }

    void print(void){
        cout<<"NO  :  INFO "<<endl<<endl;
        for(int i=1;i<=n;i++)
            cout<<i<<"   :  "<<a[i]<<endl;
    }
};

int main()
{
	int ch,e_no;
	queue obj;

	while(1)
	{
	    cout<<endl<<endl;
		cout<<"1...Enqueue"<<endl;
		cout<<"2...Dequeue"<<endl;
		cout<<"3...Print"<<endl;
		cout<<"4...Exit"<<endl;
		cout<<"Enter Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: system("CLS");
                    cout<<"Enter the number that you want to be enqueue(add in queue): ";
                    cin>>e_no;
                    obj.enqueue(e_no);
                    break;

			case 2: system("CLS");
                    obj.dequeue();
                    break;

            case 3: system("CLS");
                    obj.print();
                    break;

			case 4: return 0;

			default: cout<<"Enter the valid entry..."<<endl;
                     break;
		}
	}
	return 0;
}

