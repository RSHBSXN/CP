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
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        string N;
        char d;
        cin >> N >> d;
        int minD = '9';
        for(int i=0;i<N.length();++i){
            if(N[i] < minD)
                minD = N[i];
        }
        string res;
        if(minD >= d){
            res.assign(N.length(),d);
        }
        else{
            for(int i=0;i<N.length();){
                int minInd = i;
                for(int j = i+1;j<N.length();++j){
                    if(N[minInd] > N[j]){
                        minInd = j;
                    }
                }
                if(N[minInd] >= d){
                    break;
                }
                else{
                    res += N[minInd];
                    i = minInd + 1;
                }
            }
            res = res + string(N.length() - res.length(),d);
        }
        cout<<res<<'\n';
    }
}
