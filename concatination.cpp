#include<iostream>
#include<cstring>
using namespace std;

class dll
{
    char info;
    dll *prev;
    dll *next;
public:
    static int count;
    dll(char n='\0')
    {
        info=n;
        prev=NULL;
        next=NULL;
    }

    void traverse_forward(void)
    {
        dll *trav_ptr=this;
        while(trav_ptr!= NULL)
        {
            cout<<trav_ptr->info;
            trav_ptr=trav_ptr->next;
        }
    }

    void append_node(dll *new_node)
    {
        dll *trav_ptr=this;
        while(trav_ptr->next != NULL)
            trav_ptr=trav_ptr->next;

        new_node->prev=trav_ptr;
        trav_ptr->next = new_node;
    }

};

int main()
{
    string a,b;

    cout<<"Enter the First String : ";
    getline(cin,a);
    cout<<"Enter the Second String : ";
    getline(cin,b);

    dll *test=new dll();

    for(int i=0;i<a.length();i++)
        test->append_node(new dll(a[i]));
    for(int i=0;i<b.length();i++)
        test->append_node(new dll(b[i]));

    cout<<"After Concatination of Two Strings : ";
    test->traverse_forward();
}
