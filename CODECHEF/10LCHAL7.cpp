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
#define MAAX 1000000000
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
LL req(LL x,LL y){
    cout <<"Q "<<x << ' '<<y<<'\n';
    cout<<flush;
    LL d;
    cin >> d;
    return d;
}
bool answer(LL a,LL b,LL c, LL d){
    cout<<"A "<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    LL ans;
    cout<<flush;
    cin >> ans;
    return ans == 1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        LL A = req(0,0);
        LL B = req(0,MAAX);
        LL C = req(MAAX,0);
        LL interm = A - B + MAAX;
        LL a = req(0,interm/2);
        LL b = A - a;
        LL c = MAAX - C + b;
        LL d = MAAX - B + a;
        if(!answer(a,b,c,d)){
            break;
        }
    }
}
