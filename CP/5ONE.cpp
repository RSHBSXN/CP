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
    int n;
    cin >> n;
    vector<pll> STD(n);
    for(pll &x : STD)
        cin >> x.first >> x.second;
    // sort(STD.begin(),STD.end(),[](pll a,pll b){
    //     return a.second <= b.second;
    // });
    LL poss = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;j++){
            if(STD[i].first >= STD[j].first && STD[i].first <= STD[j].second)
                poss++;
            else if(STD[j].first >= STD[i].first && STD[j].first <= STD[i].second)
                poss++;
        }
    }
    cout<<poss<<'\n';
}
