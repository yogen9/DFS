#include<iostream>
#include<stdlib.h>
using namespace std;

class dll
{
    int info;
    dll *prev,*next;
public:

    static int count;
    dll(int n=0)
    {
        info=n;
        prev=NULL;
        next=NULL;
        count++;
    }

    void traverse_forward(void);
    void traverse_backward(void);
    void append_node(dll *new_node);
    int insert_after(int n,dll *new_node);
    dll* insert_node_first(dll *new_node);
    void insert_node_at_location(dll *new_node,int location);
    int delete_node(int n,dll *first);
    dll* second_node(void);

};
int dll::count;

void dll::traverse_forward(void)
{
    dll *trav_ptr=this;
    while(trav_ptr != NULL)
    {
        cout<<trav_ptr->info<<'\t';
        trav_ptr=trav_ptr->next;
    }
}
void dll::traverse_backward(void)
{
    dll *trav_ptr=this;
    while(trav_ptr->next != NULL)
    {
        trav_ptr=trav_ptr->next;
    }
    do
    {
        cout<<trav_ptr->info<<'\t';
        trav_ptr=trav_ptr->prev;
    }
    while(trav_ptr != NULL);
}
void dll::append_node(dll *new_node)
{
    dll *trav_ptr=this;
    while(trav_ptr->next != NULL)
    {
        trav_ptr=trav_ptr->next;
    }
    new_node->prev=trav_ptr;
    trav_ptr->next = new_node;
}

int dll::insert_after(int n,dll *new_node)
{
    dll *trav_ptr=this;
    while(trav_ptr != NULL)
    {
        if(trav_ptr->info==n)
            break;
        trav_ptr=trav_ptr->next;
    }

    if(trav_ptr != NULL)
    {
        dll *temp_node=trav_ptr->next;

        new_node->next=trav_ptr->next;
        new_node->prev=trav_ptr;
        temp_node->prev=new_node;
        trav_ptr->next=new_node;

        return 0;
    }
    else
    {
        append_node(new_node);
        return 1;
    }

}

void dll:: insert_node_at_location(dll *new_node,int location)
{
    dll* trav_ptr=this;
    dll*  trav_prev;
    int counter=0;


        while(trav_ptr != NULL)
        {
            counter++;
            if(counter==location)
                break;
            trav_prev=trav_ptr;
            trav_ptr=trav_ptr->next;
        }
        if(trav_ptr!=NULL)
        {
            new_node->next=trav_ptr;
            new_node->prev=trav_prev;
            trav_prev->next=new_node;
            trav_ptr->prev=new_node;
        }

}

dll* dll::insert_node_first(dll *new_node)
{
        dll *trav_ptr= this;
        new_node->next=trav_ptr;
        trav_ptr->prev=new_node;
        return new_node;
}

int dll::delete_node(int n,dll *first)
{
    dll *trav_ptr=this;
    dll *trav_prev=NULL;
    while(trav_ptr != NULL)
    {
        if(trav_ptr->info==n)
            break;
        trav_prev=trav_ptr;
        trav_ptr=trav_ptr->next;
    }

    if(trav_ptr != NULL)
    {
        if(trav_prev==NULL)
        {
            count=count-2;
            return 2;
        }

        (trav_ptr->next)->prev = trav_ptr->prev;
        (trav_ptr->prev)->next = trav_ptr->next;


        free(trav_ptr);
        count=count-2;
        return 0;
    }
    else
        return 1;
}

dll* dll:: second_node(void)
{
    dll *trav_ptr=this;
    free(new dll(trav_ptr->info));
    return trav_ptr->next;

}

main()
{
    int choice;
    dll *first=new dll(1);

next:

    cout<<endl<<"PRESS 1 : FOR LISTING ALL NODES "<<endl;
    cout<<"PRESS 2 : TRAVERSE BACKWARD "<<endl;
    cout<<"PRESS 3 : APPEND NEW NODE "<<endl;
    cout<<"PRESS 4 : INSERT NEW NODE AFTER OTHER NODE "<<endl;
    cout<<"PRESS 5 : INSERT NEW NODE AT PARTICULAR LOCATION"<<endl;
    cout<<"PRESS 6 : UPDATE NODE"<<endl;
    cout<<"PRESS 7 : DELETE NODE "<<endl;
    cout<<"PRESS 8 : SORT LIST"<<endl;
    cout<<"PRESS 9 : SEARCH LIST"<<endl;
    cout<<"PRESS 10 : FOR EXIT "<<endl;

    cout<<"ENTER YOUR CHOICE : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    {
        first->traverse_forward();
        break;
    }
    case 2:
    {
        first->traverse_backward();
        break;
    }
    case 3:
    {
        int in;
        cout<<"Enter info for new node : ";
        cin>>in;
        dll *append_node=new dll(in);
        first->append_node(append_node);
        first->traverse_forward();
        break;
    }
    case 4:
    {
        int new_in,old_in;
        int ans;
        cout<<"Enter info for new node : ";
        cin>>new_in;
        cout<<"Enter a info of old node after which you want to insert new node : ";
        cin>>old_in;
        dll *insert_node=new dll(new_in);
        ans=first->insert_after(old_in,insert_node);
        if(ans==0)
            cout<<"OLD NODE IS FOUND !!"<<endl;
        else
            cout<<"OLD NODE IS NOT FOUND !! :--> NEW NODE IS APPENDED "<<endl;
        first->traverse_forward();
        break;
    }
    case 5:
    {
        int new_in,location;
        cout<<"TOTAL NUMBERS OF NODES : "<<first->count<<endl;
        cout<<"Enter location of new node to insert : ";
        cin>>location;
        cout<<"Enter info for new node : ";
        cin>>new_in;
        dll *insert_node=new dll(new_in);
        if(location==1)
        {
          dll* temp=first->insert_node_first(insert_node);
          if(temp!=NULL)
                first=temp;
        }
        else
            first->insert_node_at_location(insert_node,location);
        first->traverse_forward();
        break;

    }
    case 7:
    {
        int in;
        cout<<"Enter info for node to be delete : ";
        cin>>in;

        int ans=first->delete_node(in,first);
        if(ans==0)
            cout<<"NODE IS FOUND AND DELETED!!"<<endl;
        else if(ans==1)
            cout<<"NODE IS NOT FOUND !!"<<endl;
        else
        {
            dll *temp=first->second_node();
            if(temp != NULL)
                first=temp;
        }
        first->traverse_forward();
        break;
    }
    case 10:
    {
        exit(0);
        break;
    }

    }
    goto next;
}
