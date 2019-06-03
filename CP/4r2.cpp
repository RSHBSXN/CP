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
struct node{
    int val;
    node *left,*right;
    node(int val){
        this->val = val;
        left = right = NULL;
    }
};

node *HEAD = NULL;
node *TAIL = NULL;
unordered_map<int,node *> MAP;

void display(){
    node *PTR = HEAD;
    while(PTR){
        cout<<PTR->val<<' ';
        PTR = PTR->right;
    }
    cout<<'\n';
}
void insertBefore(node *A,node *B){
    B->right = A;
    if(A == HEAD){
        A->left = B;
        HEAD = B;
    }
    else{
        B->left = A->left;
        A->left->right = B;
        A->left = B;
    }

}
void insertAfter(node *A,node *B){
    B->right = A->right;
    B->right->left = B;
    B->left = A;
    A->right = B;

}
void deleteBefore(node *PTR){
    if(PTR != HEAD){
        PTR = PTR->left;
        if(PTR == HEAD){
            HEAD = HEAD->right;
            PTR->left = NULL;
        }
        else{
            node *PAR = PTR->left;
            PTR->right->left = PAR;
            PAR->right = PTR->right;
        }
        MAP.erase(PTR->val);
    }

}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        int num;
        cin >> num;
        MAP[num] = new node(num);
        if(HEAD == NULL){
            HEAD = MAP[num];
            TAIL = MAP[num];
        }
        else{
            MAP[num]->left = TAIL;
            TAIL->right = MAP[num];
            TAIL = MAP[num];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        int A,B;
        cin >> A;
        switch(type){
            case 1:
                cin >> B;
                if(MAP.find(A) != MAP.end()){
                    MAP[B] = new node(B);
                    insertBefore(MAP[A],MAP[B]);
                }
                break;
            case 2:
                if(MAP.find(A) != MAP.end())
                    deleteBefore(MAP[A]);
                break;
            case 3:
                cin >> B;
                if(MAP.find(A) != MAP.end()){
                    MAP[B] = new node(B);
                    insertAfter(MAP[A],MAP[B]);
                }
                break;
        }  
    }
    display();
}
