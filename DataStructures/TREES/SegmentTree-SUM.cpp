#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node{
    int data;
    int left,right;
};
int createSegTree(vector<int> ARR,vector<Node*> &SegTree,int segInd,int left,int right){
    if(left <= right){
        Node *NEW = new Node;
        NEW->left = left;
        NEW->right = right;
        if(left == right){
            NEW->data = ARR[left];
            SegTree[segInd] = NEW;
            return NEW->data;
        }
        else{
            int middle = (left + right)/2;
            NEW->data = createSegTree(ARR,SegTree,segInd *2+1,left,middle) + createSegTree(ARR,SegTree,segInd * 2 + 2,middle+1,right);
            SegTree[segInd] = NEW;
            
            return NEW->data;
        }
    }
    else
        return 0;
}
int getSum(vector<Node*> SegTree,int left,int right,int segInd){
    if(segInd >= SegTree.size()){
        return 0;
    }
    else{
        int nodeLeft = SegTree[segInd]->left;
        int nodeRight = SegTree[segInd]->right;
        if(right < nodeLeft || nodeRight < left)//No overLap
            return 0;
        else if(left <= nodeLeft && right >= nodeRight) // Completely Overlaps
            return SegTree[segInd]->data;
        else{//Partially Overlaps
            return getSum(SegTree,left,right,segInd*2+1) + getSum(SegTree,left,right,segInd*2+2); 
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> Array(N);
    for(int &x : Array){
        cin >> x;
    } 
    int segSize = 0;
    while(pow(2,segSize) < N){
        segSize++;
    }
    segSize = pow(2,segSize) * 2 - 1;

    vector<Node*> SegTree(segSize);
    createSegTree(Array,SegTree,0,0,Array.size()-1);
    int left,right;
    cin >> left >> right;
    cout<<getSum(SegTree,left,right,0);
}
