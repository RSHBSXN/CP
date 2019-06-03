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
void findSum(vector<vector<int>> &RES,vector<int> A,vector<int> subRes,int index,int sum,int X){
    if(index == A.size()){
        if(sum == X)
            RES.push_back(subRes);
    }
    else{
        if(sum + A[index] <= X){
            subRes.push_back(A[index]);
            findSum(RES,A,subRes,index,sum + A[index],X);
            subRes.pop_back();
        }
        findSum(RES,A,subRes,index+1,sum,X);
    }
}

int main(){
    int N;
    cin >> N;
    vi ARR(N);
    for(int &i : ARR)
        cin >> i;
    MATRIX RES;
    int k;
    cin >> k;
    findSum(RES,ARR,vector<int>(),0,0,k);
    for(int i=0;i<RES.size();++i){
        for(int j=0;j<RES[i].size();++j){
            cout<<RES[i][j]<<' ';
        }
        cout<<'\n';
    }
}
