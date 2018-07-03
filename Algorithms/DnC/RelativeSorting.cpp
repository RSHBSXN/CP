/*
 *  Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2. 
 *  For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[]
 *  are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, int> *A2;
void display(vector<int> Arr){
    for(int i : Arr)
        cout << i << ' ';
    
}
void swap(int &A,int &B){
    int temp = A;
    A = B;
    B = temp;
}
int partition(vector<int> &Arr,int left,int right,bool isRelative){
    int pivot = right;
    int ind = left;
    for (int i = left; i < right;i++){
        if(!isRelative){
            if(Arr[i] < Arr[pivot]){
                swap(Arr[i], Arr[ind]);
                ind++;
            }
        }
        else{
            if((*A2)[Arr[i]] < (*A2)[Arr[pivot]]){
                swap(Arr[i], Arr[ind]);
                ind++;
            }
        }
    }
    swap(Arr[ind], Arr[pivot]);
    return ind;
}
void quickSort(vector<int> &Arr,int left,int right,bool isRelative){
    if(left < right){
        int pInd = partition(Arr, left, right, isRelative);
        
        quickSort(Arr, left, pInd - 1, isRelative);
        quickSort(Arr, pInd + 1, right, isRelative);
    }
}
int main(){
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T;testcase++){
        int sizeA1, sizeA2;
        cin >> sizeA1 >> sizeA2;
        vector<int> A1(sizeA1),A2(sizeA2);
        //Input A1
        for (int indx = 0; indx < sizeA1;indx++)
            cin >> A1[indx];
        //Input A2
        unordered_map<int, int> POS;
        for (int indx = 0; indx < sizeA2;indx++){
            cin >> A2[indx];
            POS[A2[indx]] = indx+1;
        }
        ::A2 = &POS;
        //Seperate array
        vector<int> InA2;
        vector<int> NotInA2;
        for (int indx = 0; indx < sizeA1;indx++){
            if(POS[A1[indx]] == 0)
                NotInA2.push_back(A1[indx]);
            else
                InA2.push_back(A1[indx]);
        }
        //Sort those elements which are present in A2 in relative order
        quickSort(InA2, 0, InA2.size()-1, true);
        //Those elements which are not in A2 sort normally
        quickSort(NotInA2, 0, NotInA2.size() - 1, false);
        display(InA2);
        display(NotInA2);
    }
}
