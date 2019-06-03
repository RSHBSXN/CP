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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int pos = 0,neg = 0;
        for(int i=0;i<n;++i){
            int num;
            cin >> num;
            if(num > 0)   
                pos++;
            else
                neg++;
        }
        if(pos == 0)
            pos = neg;
        else if(neg == 0)
            neg = pos;
        cout<<max(pos,neg)<<' '<<min(pos,neg)<<'\n';
    }
}
