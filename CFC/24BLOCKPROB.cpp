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
struct block{
    int data;
    block *next;
    block(int d){
        data = d;
    }
};
/*
    move a onto b
        place all blocks above block a and block b to init positions
        block a place to block b 
    
    move a over b
        place all blocks above block a to init positions
        block a place to top of stack of block b
    
    pile a onto b
        place all block stacked above block b to init
        blocks above a including a to block b
    
    pile a over b
        blocks above a including block a to top of block b
    
    PRESENT array tells about block present in which stack
    STACK is array of pointers stores the linked list of stacks

    void toInit(x): place block x to its initial position.
    block* find(x): find the location of x in the STACK array
        returns null if it is the first element of STACK[i]
 
    moveOver(a,b):  find(a) go till null, place all to init
                    then place a to b's top
                    make present location of a as b

    moveOnto(a,b):  find(a) go till null and place all blocks to init pos
                    find(b) go till null and place all blocks to init pos
                    make b->next = a
                    make present location of a as b
    
    pileOnto(a,b):  find(b) go till null and place all blocks to init pos
                    find(a) and make b->next = a
                    move in a and make there present location as b
    
    pileOver(a,b):  move till end of b and then make ptr->next as a
                    then move in a and make present locations as b

*/
vector<block*> STACK;
vector<int> PRESENT;
block* toInit(block* &x){
    block *next = x->next;
    STACK[x->data] = x;
    PRESENT[x->data] = x->data;
    x->next = NULL;
    return next;
}
block* findPar(int a){
    int stk = PRESENT[a];
    block* ptr = STACK[stk];
    if(ptr->data == a){
        return NULL;
    }
    while(ptr->next->data != a){
        ptr = ptr->next;
    }
    return ptr;
}
block* find(int a){
    block *par = findPar(a);
    if(par == NULL)
        return STACK[PRESENT[a]];
    else    
        return par->next;
}
block* gotoLast(int a){
    block* ptr = find(a);
    while(ptr->next){
        ptr = ptr->next;
    }
    return ptr;
}
void placeToInit(int a){
    block *par = findPar(a);
    if(par == NULL){
        par = STACK[PRESENT[a]];
    }
    else
        
        
}
int main(){
    int n;
    cin >> n;

}
