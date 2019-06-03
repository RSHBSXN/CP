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
int getTimes(int n){
    if(n == 1)
        return 1;
    else if((n & (n-1)) == 0)
        return n;
    int i;
    for(i=2;i<n;i*=2);
    i /= 2;
    return (n - i) * 2;
}
int main(){
    priority_queue<int,vector<int>,greater<int>> PQ;
    int n;
    cin >> n;
    LL count = 0;
    while(n--){
        int num;
        cin >> num;
        PQ.push(-num);
        count += num;
    }
    while(PQ.size() >= 2){
        LL numOne = -PQ.top();
        PQ.pop();
        LL numTwo = -PQ.top();
        PQ.pop();
        count += numOne + numTwo;
        PQ.push(-(numOne + numTwo));
    }
    cout<<count<<'\n';
}
