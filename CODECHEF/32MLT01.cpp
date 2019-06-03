/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int N,K;
        cin >> N >> K;
        ll RES[N] = {0};
        ll MaxVal = INT64_MIN; 
        for(int i=0;i<N;++i){
            ll num;
            cin >> num;
            MaxVal = max(MaxVal,num);
            if(i >= K){
                RES[i] = max(num,RES[i-K] + num);
            }
            else{
                RES[i] = num;
            }
        }
        if(N >= K){
            ll Max = RES[N-K];
            for(int i=N-K+1;i<N;++i){
                Max = max(Max,RES[i]);
            }
            cout<<Max;
        }
        else{
            cout<<MaxVal;
        }
        cout<<'\n';
    }
}
