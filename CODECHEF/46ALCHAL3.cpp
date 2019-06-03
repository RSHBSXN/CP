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
    int rdir[] = {0,0,1,-1};
    int cdir[] = {1,-1,0,0};
    while(t--){
        int a,b;
        int pl;
        cin >> a >> b >> pl;
        set<pii> Plants;
        while(pl--){
            int r,c;
            cin >> r >> c;
            Plants.insert({r,c});
        }
        ll count = 0;
        for(auto &x : Plants){
            for(int i=0;i<4;++i){
                pii adjc = {x.first + rdir[i],x.second + cdir[i]};
                if(Plants.find(adjc) == Plants.end()){
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }   
}
