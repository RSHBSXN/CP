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
int binarySearch(vi ARR){
    int l = 0,r = ARR.size()-1;
    while(r - l > 1){
        bool changed = false;
        int mid = (r + l)/2;
        if(mid != 0 && ARR[mid-1] == ARR[mid]){
            mid--;
            changed = true;
        }
        if((mid & 1) == 0){
            if(changed)
                l = mid+1;
            else
                l = mid;
        }
        else{
            r = mid;
        }
    }
    if(l == 0 || ARR[l] != ARR[l-1] && (l != ARR.size() || ARR[l] != ARR[l+1]))
        return l;
    else
        return r;
}
int main(){
    int n;
    cin >> n;
    vi ARR(n);
    for(int &i : ARR)
        cin >> i;
    cout<<binarySearch(ARR)<<'\n';
}
