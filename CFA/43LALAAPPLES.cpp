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
#define vll vector<ll>
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
    int n;
    cin >> n;
    vector<pair<int,ll>> Pos,Neg;
    while(n--){
        int x;
        ll a;
        cin >> x >> a;
        if(x < 0)
            Neg.push_back({x,a});
        else
            Pos.push_back({x,a});
    }
    sort(Neg.begin(),Neg.end(),[](pair<int,ll> a,pair<int,ll> b){
        return a.first > b.first;
    });
    sort(Pos.begin(),Pos.end(),[](pair<int,ll> a,pair<int,ll> b){
        return a.first < b.first;
    });
    int count=0;
    ll totalApples = 0;
    if(Neg.size() > Pos.size()){
        count = Pos.size();   
        totalApples = Neg[count].second;
    }
    else{
        count = Neg.size();
        if(count < Pos.size())
            totalApples = Pos[count].second;
    }
    for(int i=0;i<count;++i){
        totalApples += Pos[i].second + Neg[i].second;
    }
    cout<<totalApples<<'\n';
}