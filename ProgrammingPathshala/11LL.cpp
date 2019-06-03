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
    int data;
    node *next;
};
int mid(node *FPTR,node *SPTR){
    if(SPTR != NULL)
        return -1;
    if( !FPTR || !FPTR->next)
        return SPTR->data;
    else
        return mid(FPTR->next->next,SPTR->next);
}
node* Merge(node *headOne,node *headTwo){
    node *head = NULL;
    node *ptr1 = headOne,*ptr2 = headTwo;
    node *ptr = NULL;
    while(ptr1 && ptr2){
        node *&p = ptr1;
        if(ptr2->data < ptr1->data)
            p = ptr2;
        if(head == NULL){
            head = p;
            ptr = p;
        }
        else{
            ptr->next = p;
        }
        p = p->next;
        ptr->next = NULL;
    }
    if(ptr1 != NULL){
        if(head == NULL)
            head = ptr1;
        else
            head->next = ptr1;
    }
    else
        if(head == NULL)
            head = ptr2;
        else
            head->next = ptr2;  
    return head;
}
node* removeDupl(node *head){
    if(head){
        node *start = head;
        node *ptr = start->next;
        while(ptr){
            if(ptr->data != start->data){
                start->next = ptr;
                start = ptr;
            }
            ptr = ptr->next;
        }
        start->next = NULL;
    }
    return head;
}
node* segregate(node* head){
    node *oddHead = NULL,*evenHead = NULL;
    node *ptrO = NULL,*ptrE = NULL;
    node *ptr = head;
    while(ptr){
        if((ptr->data & 1)){
            if(ptrO){
                ptrO->next = ptr;
            }
            else{
                oddHead = ptr;
                ptrO = oddHead;
            }
            ptrO = ptrO->next;
        }
        else{
            if(ptrE)
                ptrE->next = ptr;
            else{
                evenHead = ptr;
                ptrE = evenHead;
            }
            ptrE = ptrE->next;
        }
        ptr = ptr->next;
    }
    if(oddHead){
        ptrE->next = evenHead;
    }
    else
        oddHead = evenHead;
    return oddHead;
}
