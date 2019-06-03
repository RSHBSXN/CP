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
    int n,t;
    cin >>n >> t;
    int minT = INT32_MAX,ind = 0;
    for(int i=1;i<=n;++i){
        int a,b;
        cin >> a >> b;
        int T = 0;
        if(a >= t)
            T = a;
        else{
            T = ((t-a)/b) * b;
            if((t-a) % b != 0)
                T += b;
            T += a;
        }
        if(T < minT){
            minT = T;
            ind = i;
        }
    }
    cout<<ind<<'\n';
        
}
