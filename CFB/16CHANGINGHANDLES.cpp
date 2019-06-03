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
vi DSU;
vector<string> iTN;
unordered_map<string,int> nToI;
map<string,string> Recent;
int Find(int index){
    if(DSU[index] == -1)
        return index;
    else{
        DSU[index] = Find(DSU[index]);
        return DSU[index];
    }
}
void Union(int a,int b){
    int parA = Find(a);
    int parB = Find(b);
    DSU[parB] = parA;

}
int main(){
    int q;
    cin >> q;
    while(q--){
        string old,New;
        cin >> old >> New;
        if(nToI.find(old) == nToI.end()){
            nToI[old] = iTN.size();
            iTN.push_back(old);
            DSU.push_back(-1);
        }
        if(nToI.find(New) == nToI.end()){
            nToI[New] = iTN.size();
            iTN.push_back(New);
            DSU.push_back(-1);
        }
        Union(nToI[old],nToI[New]);
        int parOld = Find(nToI[old]);
        Recent[iTN[parOld]] = New;
    }
    cout<<Recent.size()<<'\n';
    for(auto x : Recent){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}
