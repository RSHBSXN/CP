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
void rev(queue<int> &Q,int count,int size){
    if(count == size){
        return;
    }
    else{
        int item = Q.front();
        Q.pop();
        rev(Q,count+1,size);
        Q.push(item);
    }
}
int main(){
    int n;
    cin >> n;
    queue<int> Q;
    while(n--){
        int num;
        cin >> num;
        Q.push(num);
    }
    rev(Q,0,Q.size());
    while(!Q.empty()){
        cout<<Q.front()<<'\n';
        Q.pop();
    }
}
