#include<iostream>
#include<cstdlib>
using namespace std;

class ll
{
    int info=0;
    ll* next;
public:
    ll(int n)
    {
        info=n;
        next=NULL;
    }
    void travers()
    {
        int i=1;
        ll *trav_ptr=this;
        cout<<"   NODE  :  DATA"<<endl;
        while(trav_ptr!=NULL)
        {
            cout<<"   "<<i<<"     :  "<<trav_ptr->info<<endl;
            trav_ptr=trav_ptr->next;
            i++;
        }
    }
    void travers_re()
    {
        ll*trav_ptr=this;
        cout<<trav_ptr->info<<endl;
        if(trav_ptr!=NULL)
            exit(0);
        trav_ptr=trav_ptr->next;
        travers_re();
    }
    void append(ll* next_l)
    {
        ll* trav_ptr=this;
        while(trav_ptr->next!=NULL)
            trav_ptr=trav_ptr->next;
        trav_ptr->next=next_l;
    }

    void atpos(int p,ll* obj)
    {
        int i=1;
        ll* trav_ptr=this;
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
    ll* atfirst(ll* add)
    {
        add->next=this;
        return add;
    }
    void del(int pos,ll* &first)
    {
        int i=1;
        ll* temp;
        ll* trav_ptr=this;
        while(i<=pos)
        {
            if(i==pos-1)
                temp=trav_ptr;
            if(i==pos)
                if(i==1)
                    first=trav_ptr->next;
                else
                    temp->next=trav_ptr->next;
            trav_ptr=trav_ptr->next;
            i++;
        }
    }
    void update(int data,int pos)
    {
        int i=1;
        ll* trav_ptr=this;
        while(i<=pos)
            if(i==pos)
                trav_ptr->info=data;
        trav_ptr=trav_ptr->next;
        i++;
    }
    void search(int data)
    {
        int i=1;
        ll* trav_ptr=this;
        while(trav_ptr->next!=NULL)
        {
            if(trav_ptr->info==data)
                cout<<"Position : "<<i;
        }
        trav_ptr=trav_ptr->next;
        i++;
    }
};
int main()
{
    int c;
    ll* yo=new ll(0);

    while(1)
    {
        cout<<endl<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cout<<"1.Printing All Values in Link"<<endl;
        cout<<"2.Printing All Values in Link(Recurtion)"<<endl;
        cout<<"3.Append"<<endl;
        cout<<"4.Insert Node(At Specific)"<<endl;
        cout<<"5.Add At First"<<endl;
        cout<<"6.Del"<<endl;
        cout<<"7.Update data"<<endl;
        cout<<"8.Search"<<endl;
        cout<<"9..Exit"<<endl;
        cin>>c;

        switch(c)
        {
            case 1: system("CLS");
                    cout<<endl;
                    yo->travers();
                    break;
            case 2: system("CLS");
                    cout<<endl;
                    yo->travers_re();
                    break;
            case 3: system("CLS");
                    int temp;
                    cout<<"Enter The Node Data : ";
                    cin>>temp;
                    yo->append(new ll(temp));
                    break;
            case 4: system("CLS");
                    int temp1;
                    int temp2;
                    cout<<"Enter The Position And Node Data :";
                    cin>>temp1>>temp2;
                    yo->atpos(temp1,new ll(temp2));
                    break;
            case 5: system("CLS");
                    cout<<"Enter The Node Data : ";
                    cin>>temp;
                    yo=yo->atfirst(new ll(temp));
                    break;
            case 6: system("CLS");
                    cout<<"Enter The Position :";
                    cin>>temp;
                    yo->del(temp,yo);
                    break;
            case 7: system("CLS");
                    cout<<"Enter The Position And Node Data :";
                    cin>>temp1>>temp2;
                    yo->update(temp2,temp1);
                    break;
            case 8: system("CLS");
                    cout<<"Enter the data for search :";
                    cin>>temp;
                    yo->search(temp);
                    break;
            case 9: exit(0);
                    break;
        }
    }

}
