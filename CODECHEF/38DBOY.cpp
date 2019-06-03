
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
int getTotal(int *H,int *K,int n,int ind,int pet){
    if(ind == n)
        return 0;
    else{
        int dis = INT32_MAX;
        int fill = INT32_MAX;
        if(pet >= H[ind]){
            dis = getTotal(H,K,n,ind+1,pet - H[ind]);
        }
        else{
            
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int H[n],K[n];
        for(int i=0;i<n;++i)
            cin >> H[i];
        for(int i=0;i<n;++i)
            cin >> K[i];
        cout<<getTotal(H,K,n,0);
    }
}
