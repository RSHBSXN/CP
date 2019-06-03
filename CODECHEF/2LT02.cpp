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
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pii> Res;
        int N,P;
        cin >> N >> P;
        set<int> R;
        set<int> C;
        for(int i=1;i<=N;i++){
            R.insert(i);
            C.insert(i);
        }
        while(P--){
            int r,c;
            cin >> r >> c;
            R.erase(r);
            C.erase(c);
        }
        set<int> :: iterator itr = R.begin(),itrC = C.begin();
        for(;itr != R.end() && itrC != C.end();itr++,itrC++){
            Res.push_back({*itr,*itrC});
        }
        cout<<Res.size()<<' ';
        for(pii x : Res)
            cout<<x.first<<' '<<x.second<<' ';
        cout<<'\n';
    }
}
