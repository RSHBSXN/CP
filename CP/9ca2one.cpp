#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    bool isPrime;
    node *left,*right;
    int leftPrimes,rightPrimes;
    node(int a){
        val = a;
        isPrime = true;
        left = right = NULL;
        for(int i=2;i*i<=val;++i){
            if(val % i){
                isPrime = false;
                break;
            }
        }
        
    }
};
node *root = NULL;
node* create(int a){
    node *New = new node(a);
    return New;
}

int main() {
    int N;
    cin >> N;
    unordered_map<int,node*> add;
    while(N--){
        int a,l,r;
        cin >> a >> l >> r;
        if(add.find(a) == add.end()){
            node *New = create(a);
            add[a] = New;
            if(!root)
                root = New;
        }
        if(l != -1){
            node *New = create(l);
            add[l] = New;
            add[a]->left = New;
        }
        if(r != -1){
            node *New = create(r);
            add[r] = New;
            add[a]->right = New;
        }
    }
    inOrder(root);
}