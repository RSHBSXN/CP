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
#define PREC 1e-9
vi Vessels;
int getContainers(int cap){
    int curr = cap;
    int count = 1;
    for(int i=0;i<Vessels.size();++i){
        if(Vessels[i] <= curr)
            curr -= Vessels[i];
        else{
            ++count;
            curr = cap - Vessels[i];
        }
    }
    return count;
}
ll binarySearch(int m){
    ll sum = 0,Max = 0;
    for(int i=0;i<Vessels.size();++i){
        sum += Vessels[i];
        Max = max((ll)Vessels[i],Max);
    }
    ll L = Max,R = sum;
    while(R - L > 1){
        ll mid = (L + R) >> 1;
        int cont = getContainers(mid);
        if(cont <= m)
            R = mid;
        else
            L = mid;
    } 
    if(getContainers(L) <= m)
        return L;
    else
        return R;
}
int main(){
    FASTIO;
    int n,m;
    while(cin >> n >> m){
        Vessels = vi(n);
        for(int &i : Vessels)
            cin >> i;
        cout<<binarySearch(m)<<'\n';
    }
}
