#include <iostream>
#include <utility>
#include <fstream>
#include <string>
using namespace std;
struct DLL{
    string val;
    DLL *next;
    DLL *prev;
};
void InsertBeg(DLL **head,DLL **rear,string val){
    DLL *NEW = new DLL;
    NEW->val = val;
    NEW->next = NULL;
    NEW->prev = NULL;
    if(*head == NULL){
        *head = NEW;
        *rear = NEW;
    }
    else{
        NEW->next = *head;
        (*head)->prev = NEW;
        *head = NEW;
    }
}
void InsertEnd(DLL **head,DLL **rear,string val){
    DLL *NEW = new DLL;
    NEW->val = val;
    NEW->next = NULL;
    NEW->prev = NULL;
    if(*head == NULL){
        *head = NEW;
        *rear = NEW;
    }
    else{
        (*rear)->next = NEW;
        NEW->prev = *rear;
        *rear = NEW;
    }
}
void DeleteBeg(DLL **head,DLL **rear){
    if(*head == *rear){
        *head = NULL;
        *rear = NULL;
    }
    else{
        (*head)->next->prev = NULL;
        (*head) = (*head)->next;
    }
}
void DeleteEnd(DLL **head,DLL **rear){
    if(*head == *rear){
        *head = NULL;
        *rear = NULL;
    }
    else{
        (*rear)->prev->next = NULL;
        (*rear) = (*rear)->prev;
    }
}
void Display(DLL *head){
    while(head){
        cout << head->val<<' ';
        head = head->next;
    }
    cout << endl;
}
