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
vi merge(vi ARR,int left,int right){
    int mid = (left + right)/2;
    vi A(mid - left + 1),B()
    int i = 0,j = 0,k = left;
    for(;i < ARR.size() && j < ARR2.size();){
        if(ARR[i] <= ARR2[j])
            RES[k++] = ARR[i++];
        else
            RES[k++] = ARR2[j++];

    }
    while(i < ARR.size())
        RES[k++] = ARR[i++];
    while(j < ARR2.size())
        RES[k++] = ARR[j++];
    return RES;
}
int main(){
    int n,m;
    cin >> n >> m;
    vi ARR1(n),ARR2(m);
    for(int &i : ARR1)
        cin >> i;
    for(int &i : ARR2)
        cin >> i;
    vi RES = merge(ARR1,ARR2);
    for(int &i : RES)
        cout<<i<<' ';
}
