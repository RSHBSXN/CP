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
struct el{
    int val,ind;
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<el> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i].val;
        arr[i].ind = i+1;
    }
    sort(arr.begin(),arr.end(),[](el &a ,el &b){
        return a.val < b.val;
    });
    int i,total = 0;
    for(i = 0;i<n && total+arr[i].val <= k;++i){
        total += arr[i].val;
    }
    cout<<i<<'\n';
    for(int j=0;j<i;++j)
        cout<<arr[j].ind<<' ';
    
}
