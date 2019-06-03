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
vector<LL> length(51);
void build(){
    for(int i=0;i<51;++i){
        if(i > 0)
            length[i] = length[i-1]*2;
        else
            length[i] = 1;
    }
}
int binarySearch(LL index,LL ind){
    LL mid = length[ind]/2;
    if(mid == index){
        return ind;
    }
    else if(index > mid){
        return binarySearch(index-mid,ind-1);
    }
    else
        return binarySearch(index,ind-1);
}
int main(){
    build();
    LL n,k;
    cin >> n >> k;
    cout<<binarySearch(k,n)<<'\n';
}
