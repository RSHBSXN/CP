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
int findGreaterOrEq(vi &ARR,int num){
    int L = 0,R = ARR.size()-1;
    while(R - L > 1){
        int mid = (L + R)/2;
        if(ARR[mid] < num){
            L = mid+1;
        }
        else if(ARR[mid] >= num){
            R = mid;
        }
    }
    int ind;
    if(ARR[L] >= num)
        ind = L;
    else if(ARR[R] >= num)
        ind = R;
    else
        ind = -1;
    return ind;
}
int main(){
    FASTIO;
    int n,m;
    cin >> n >> m;
    vi A(n),B(m);
    for(int &i : A)
        cin >> i;
    for(int &i : B)
        cin >> i;
    int add = 0;
    for(int i=0;i<n;++i){
        sort(B.begin(),B.end());
        int ind = findGreaterOrEq(B,A[i]);
        if(ind == -1){
            add++;
        }
        else
            B[ind] = -1;
    }   
    cout<<add<<'\n';
}
