/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct tree{
    int data;
    tree *left,*right;
    tree(){
        left = right = NULL;
    }
    tree(int data){
        this->data = data;
        
    }
};
bool areSame(tree *r1,tree *r2){
    if(((!r1) ^ (!r2))){
        return false;
    }
    else if(!r1)
        return true;
    else{
        return r1->data == r2->data && areSame(r1->left,r2->left) && areSame(r1->right,r2->right);
    }
}
int height(tree *root){
    if(!root)
        return 0;
    else
        return 1 + max(height(root->left),height(root->right));
}

bool isHeightBalanced(tree *r1){
    if(!r1)
        return true;
    else{
        int leftHeight = height(r1->left);
        int rightHeight = height(r1->right);
        if(abs(leftHeight - rightHeight) <= 1){
            return isHeightBalanced(r1->left) && isHeightBalanced(r1->right);
        }  
        else
            return false;

    }
}
void printPaths(tree *t);
int printPathSum(tree *t,int number){
    if(!t->left && !t->right){
        number = number * 10 + t->data;
        return number;
    }
    else{
        int sum = 0;
        if(t->left)
            sum += printPathSum(t->left,number * 10 + t->data);
        if(t->right)
            sum += printPathSum(t->right,number * 10 + t->data);
        return sum;
    }
}

int main(){
}1
