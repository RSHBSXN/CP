#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
    int ht;
};
int UpdateHeight(node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftHeight = UpdateHeight(root->left);
        int rightHeight = UpdateHeight(root->right);
        root->ht = max(leftHeight,rightHeight)+1;
        return root->ht;
    }
}
void LL(node **root,node *PAR,node *A,node *B,node *IN){
    if(*root == A){
        *root = B;
    }
    else{
        node **add = &((PAR->left == A)?PAR->left:PAR->right);
        *add = B;  
    }
    A->left = B->right;
    B->right = A; 

}
void RR(node **root,node *PAR,node *A,node *B,node *IN){
    if(*root == A){
        *root = B;
    }
    else{
        node **add = &((PAR->left == A)?PAR->left:PAR->right);
        *add = B;  
    }
    A->right = B->left;
    B->left = A; 
}
void LR(node **root,node *PAR,node *A,node *B,node *IN){
    node *B2 = (B->val > IN->val)?B->left:B->right;
    RR(root,A,B,B2,IN);
    LL(root,PAR,A,B2,IN);
}
void RL(node **root,node *PAR,node *A,node *B,node *IN){
    node *B2 = (B->val > IN->val)?B->left:B->right;
    LL(root,A,B,B2,IN);
    RR(root,PAR,A,B2,IN);
}
string getRot(node *A,node *IN,node* &B,int count = 0){
    if(count >= 2)
        return "";
    if(IN->val < A->val){
        if(count == 0)
            B = A->left;
        return "L" + getRot(A->left,IN,B,count+1);
    }
    else{
        if(count == 0)
            B = A->right;
        return "R" + getRot(A->right,IN,B,count+1);
    }
}
void balance(node **root,node *PAR,node *A,node *IN){
    node *B;
    string rot = getRot(A,IN,B);
    cout<<"unbalanced "<<rot<<'\n';
    if(rot == "LL")
        LL(root,PAR,A,B,IN);
    else if(rot == "RR")
        RR(root,PAR,A,B,IN);
    else if(rot == "LR")
        LR(root,PAR,A,B,IN);
    else if(rot == "RL")
        RL(root,PAR,A,B,IN);
    
    UpdateHeight(*root);
}
void insert(node **root,node *PAR,node *PTR,node *NEW){
    if(*root == NULL)//TREE is empty
        *root = NEW;
    else{
        //check whether NEW is greater or less than present node
        if(PTR == NULL){
            node **add = &((PAR->val > NEW->val)?PAR->left:PAR->right);
            *add = NEW;
        }
        else{
            if(PTR->val > NEW->val)
                insert(root,PTR,PTR->left,NEW);
            else
                insert(root,PTR,PTR->right,NEW);
            int leftHeight,rightHeight;
            leftHeight = (PTR->left)?PTR->left->ht:0;
            rightHeight = (PTR->right)?PTR->right->ht:0;
            int diff = leftHeight - rightHeight;
            if(abs(diff) >= 2){
                balance(root,PAR,PTR,NEW);
                leftHeight = (PTR->left)?PTR->left->ht:0;
                rightHeight = (PTR->right)?PTR->right->ht:0;
            }
            if(PTR->ht == leftHeight || PTR->ht == rightHeight)
                PTR->ht += 1;
            //Height has also been set till this line
            //After this we need to calculate balance factor which is the difference of the height of subtrees
        }
    }
}

int main(){
    /*Driver function*/
    node* root = NULL;
    int N;
    cin >> N;
    int maxH = 0;
    for(int i=1;i<=N;i++){
        int val;
        cin >>  val;
        node *New = new node;
        New->val = val;
        New->left = NULL;
        New->right = NULL;
        New->ht = 1; 
        insert(&root,NULL,root,New);
        LevelOrder(root);
    }
    
}
