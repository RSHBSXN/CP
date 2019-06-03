#include <iostream>
using namespace std;
struct node{
    int value;
    node *left,*right;
    node(int value){
        left = right = NULL;
    }
};
node* insert(node* &root,node *ptr,int value){
    if(root == NULL)
        return new node(value);
    else{
        if(ptr == NULL)
            return new node(value);
        else if(ptr->value >= value){
            ptr->left = insert(root,ptr->left,value);
            return ptr->left;
        }
        else{
            ptr->right = insert(root,ptr->right,value);
            return ptr->right;
        }
    }
}
void inOrder(node *root){
    if(root == NULL)
        return;
    else{
        inOrder(root->left);
        cout<<root->value<<' ';
        inOrder(root->right);
        return;
    }
}
int main(){
    int N;
    cin >> N;
    node *root = NULL;
    for(int i=0;i<N;++i){
        int num;
        cin >> num;
        root = insert(root,root,num);
    }
    inOrder(root);
}