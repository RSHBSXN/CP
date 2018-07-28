#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int data;
	int left,right;
};
int initSegTree(vector<node> &TREE,vector<int> Arr,int left,int right,int SegInd);
int initSegTree(vector<node> &TREE,vector<int>Arr,int left,int right,int segInd = 0){
	if(left <= right){
		node NEW;
		NEW.left = left;
		NEW.right = right;
		if(left == right){
			NEW.data = left;
			TREE[segInd] = NEW;
			return NEW.data;
		}
		else{
			int middle = (left + right) /2;
			int leftInd = initSegTree(TREE,Arr,left,middle,segInd * 2 + 1);
			int rightInd = initSegTree(TREE,Arr,middle+1,right,segInd * 2 + 2);
			NEW.data = (Arr[leftInd] < Arr[rightInd])?leftInd:rightInd;
			TREE[segInd] = NEW;
			return NEW.data;
		}
	}
	else{
		return INT32_MAX;
	}
}
int findMin(vector<node>&TREE,vector<int> &ARR,int left,int right,int segInd = 0){
	if(segInd < TREE.size()){
		int nodeLeft = TREE[segInd].left;
		int nodeRight = TREE[segInd].right;
		if(nodeLeft >= left && nodeRight <= right){
			return TREE[segInd].data; 
		}
		else if(nodeRight < left || nodeLeft > right)
			return INT32_MAX;
		else{
			int lft = findMin(TREE,ARR,left,right,segInd * 2 + 1);
			int rght = findMin(TREE,ARR,left,right,segInd * 2 + 2);
			if(lft == INT32_MAX && rght == INT32_MAX){
			
			return (ARR[lft] < ARR[rght])?lft:rght;
		}
	}
	else
		return INT32_MAX;
}
int maxArea(vector<int> &ARR,vector<node>&TREE,int left,int right){

}
int main(){
	int N;
	cin >> N;
	vector<int> ARR(N);
	for(int &x : ARR){
		cin >> x;
	}
	int segSize = 0;
	while(pow(2,segSize) < N){
		segSize++;
	}
	segSize = pow(2,segSize);
	segSize = segSize * 2 -1;
	vector<node> SEGTREE(segSize);
	initSegTree(SEGTREE,ARR,0,ARR.size()-1);
	int left;
	int right;
	cin >> left >> right;
	findMin(SEGTREE,left,right);
	
}
