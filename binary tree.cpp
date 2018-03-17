#include <iostream>
using namespace std ;

class tree
{
    int info ;
    tree *left , *right ;
public :
    void addnode (int data, tree **root) ;
    void lvr_traverse () ;
    void lrv_traverse () ;
    void vlr_traverse () ;
    void del(tree **root,int data);
    tree minValueNode(tree *node);

    // constructor :
    tree (int x = 0){
        info = x ;
        left = NULL ;
        right = NULL;
    }
};

int main(){
    tree (*root)=NULL;
    cout << "(press : ctrl+z to exit )\n\n\n enter values : ";

    int x ;
    while(cin>>x){
        root -> addnode(x,&root);
    }

    cout << "\n\n";
    cout << "\tVLR : " ;
    root->vlr_traverse() ;

    cout << "\n\tLVR : " ;
    root->lvr_traverse() ;

    cout << "\n\tLRV : " ;
    root->lrv_traverse() ;

    cout << "\n\n";
    return 0 ;

}

    void tree :: addnode (int data , tree **root)
    {
        tree *newnode = new tree(data);
        tree *tp = this ;

        if( (*root) == NULL){
                (*root) = newnode ;
                return;
        }

        while(1){
            if( data <= tp->info ){
                if(tp->left ==NULL){
                    tp->left  = newnode ;
                    break;
                }
                tp = tp->left;
            }
            else{
                if(tp->right==NULL){
                      tp->right = newnode ;
                      break;
                }
                tp = tp->right;
            }
        }
    }
    void tree :: vlr_traverse(){
        tree *parent = this ;
        cout << parent->info << " " ;

        if(parent->left != NULL)
            parent->left->vlr_traverse();

        if(parent->right != NULL)
            parent->right->vlr_traverse();

    }
    void tree :: lvr_traverse(){
        tree *parent = this ;

        if(parent->left != NULL)
            parent->left->lvr_traverse();

        cout << parent->info << " ";

        if(parent->right != NULL)
            parent->right->lvr_traverse();

    }
    void tree :: lrv_traverse()
    {
        tree *parent = this ;

        if(parent->left != NULL)
            parent->left->lrv_traverse();

        if(parent->right != NULL)
            parent->right->lrv_traverse();

        cout << parent->info << " " ;
    }

    void tree::del(tree **root,int data){
        if ((*root)== NULL) return root;

        if (data < (*root)->info)
            (*root)->left = del((*root)->left, data);


        else if (data > (*root)->info)
            (*root)->right = del((*root)->right,data);
        else
        {
            if ((*root)->left == NULL)
            {
                tree *temp = (*root)->right;
                delete (*root);
                return temp;
            }
            else if ((*root)->right == NULL)
            {
                tree *temp = (*root)->left;
                delete (*root);
                return temp;
            }
            tree temp = minValueNode((*root)->right);
            (*root)->key = temp->key;
            (*root)->right = del((*root)->right, temp->key);
        }
        return (*root);
    }
    tree tree::minValueNode(tree *node)
    {
        tree* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }











