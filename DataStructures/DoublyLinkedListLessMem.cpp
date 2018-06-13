#include <iostream>
using namespace std;
struct DNODE{
    int data;
    DNODE *pxn;//Using xor operation stores the xor of prev and next node
};
void insertNext(DNODE *&head,DNODE* &prev,DNODE* &pres,int data){
    DNODE *PTR = new DNODE;
    PTR->data = data;
    if(pres == NULL){
        head = PTR;
        pres = PTR;
    }
    else{
        PTR->pxn = (DNODE *)((uintptr_t)pres ^ (uintptr_t)NULL);
        pres->pxn = (DNODE *)((uintptr_t)prev ^ (uintptr_t)PTR);
        prev = pres;
        pres = PTR;
    }
}
int MoveFwd(DNODE* &prev,DNODE* &PTR){
    int data = (PTR)->data;
    DNODE *temp = PTR;
    (PTR) = (DNODE *)((uintptr_t)prev ^ (uintptr_t) (PTR)->pxn);
    prev = temp;
    return data;
}
int main(){
    DNODE *prev = NULL, *head = NULL;
    DNODE *PTR = NULL;
    insertNext(head, prev, PTR, 4);
    insertNext(head, prev, PTR, 5);
    insertNext(head, prev, PTR, 6);
    PTR = head;
    prev = NULL;
    while(PTR){
        cout << MoveFwd(prev, PTR)<<'\t';
    }
}
