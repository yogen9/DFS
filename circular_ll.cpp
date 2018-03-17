#include<iostream>
#include<cstdlib>
using namespace std;

class cll
{
    int info=0;
    cll* next;
public:
    cll(int n)
    {
        info=n;
        next=this;
    }
    void travers()
    {
        int i=1;
        cll *trav_ptr=this;
        cll *first=this;
        cout<<"   NODE  :  DATA"<<endl;
        do
        {
            cout<<"   "<<i<<"     :  "<<trav_ptr->info<<endl;
            trav_ptr=trav_ptr->next;
            i++;
        }while(trav_ptr!=first);
    }

    void append(cll* next_l)
    {
        cll* trav_ptr=this;
        cll* first=this;
        do{
            trav_ptr=trav_ptr->next;
        }while(trav_ptr->next!=first);

        trav_ptr->next=next_l;
        next_l->next=first;
    }

    void atpos(int p,cll* obj)
    {
        int i=1;
        cll* trav_ptr=this;
        while(i<=p)
        {
            if(i==p)
            {
                obj->next=trav_ptr->next;
                trav_ptr->next=obj;
            }
            i++;
            trav_ptr=trav_ptr->next;
        }
    }
    cll* atfirst(cll* add)
    {
        add->next=this;
        cll *first=this;
        cll* trav_ptr=this;
        do{
            trav_ptr=trav_ptr->next;
        }while(trav_ptr->next!=first);
        trav_ptr->next=add;
        return add;
    }
    void del(int pos,cll* first)
    {
        int i=1;
        cll* temp;
        cll* trav_ptr=this;
        while(i<=pos)
        {
            if(i==pos-1)
                temp=trav_ptr;
            if(i==pos)
                temp->next=trav_ptr->next;
            trav_ptr=trav_ptr->next;
            i++;
        }
    }

    void update(int data,int pos)
    {
        int i=1;
        cll* trav_ptr=this;
        cll *first=this;
        while(i<=pos && trav_ptr->next!=first)
            if(i==pos)
                trav_ptr->info=data;
        trav_ptr=trav_ptr->next;
        i++;
    }
    void search(int data)
    {
        int i=1;
        cll* trav_ptr=this;
        cll* first=this;
        do
        {
            if(trav_ptr->info==data)
                cout<<"Position : "<<i;
            trav_ptr=trav_ptr->next;
            i++;
        }while(trav_ptr->next!=first);

    }
};
int main()
{
    int c;
    cll* yo=new cll(0);

    while(1)
    {
        cout<<endl<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cout<<"1.Printing All Values in Link"<<endl;
        cout<<"2.Append"<<endl;
        cout<<"3.Insert Node(At Specific)"<<endl;
        cout<<"4.Add At First"<<endl;
        cout<<"5.Del"<<endl;
        cout<<"6.Update data"<<endl;
        cout<<"7.Search"<<endl;
        cout<<"8..Exit"<<endl;
        cin>>c;

        switch(c)
        {
            case 1: system("CLS");
                    cout<<endl;
                    yo->travers();
                    break;
            case 2: system("CLS");
                    int temp;
                    cout<<"Enter The Node Data : ";
                    cin>>temp;
                    yo->append(new cll(temp));
                    break;
            case 3: system("CLS");
                    int temp1;
                    int temp2;
                    cout<<"Enter The Position And Node Data :";
                    cin>>temp1>>temp2;
                    yo->atpos(temp1,new cll(temp2));
                    break;
            case 4: system("CLS");
                    cout<<"Enter The Node Data : ";
                    cin>>temp;
                    yo=yo->atfirst(new cll(temp));
                    break;
            case 5: system("CLS");
                    cout<<"Enter The Position :";
                    cin>>temp;
                    yo->del(temp,yo);
                    break;
            case 6: system("CLS");
                    cout<<"Enter The Position And Node Data :";
                    cin>>temp1>>temp2;
                    yo->update(temp2,temp1);
                    break;
            case 7: system("CLS");
                    cout<<"Enter the data for search :";
                    cin>>temp;
                    yo->search(temp);
                    break;
            case 8: exit(0);
                    break;
        }
    }

}
