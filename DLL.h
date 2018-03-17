#include<iostream>
using namespace std;

class dll
{
    char info;
    dll *prev;
    dll *next;
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
    while(trav_ptr!= NULL)
    {
        cout<<trav_ptr->info<<'\t';
        trav_ptr=trav_ptr->next;
    }
}

void dll::traverse_backward(void)
{
    dll *trav_ptr=this;
    while(trav_ptr->next!= NULL)
        trav_ptr=trav_ptr->next;

    while(trav_ptr!= NULL);
    {
        cout<<trav_ptr->info<<'\t';
        trav_ptr=trav_ptr->prev;
    }
}

void dll::append_node(dll *new_node)
{
    dll *trav_ptr=this;
    while(trav_ptr->next != NULL)
        trav_ptr=trav_ptr->next;

    new_node->prev=trav_ptr;
    trav_ptr->next = new_node;
}

int dll::insert_after(int n,dll *new_node)
{
    dll *trav_ptr=this;
    while(trav_ptr!= NULL)
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

        trav_ptr->next=new_node;
        temp_node->prev=new_node;

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
