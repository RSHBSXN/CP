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
    vi array(n);
    vi maxRight(n);
    for(int &i : array)
        cin >> i;   
    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            maxRight[i] = array[i];
        }
        else
            maxRight[i] = max(maxRight[i+1],array[i]);
    }
    for(int i=0;i<n;++i){
        if(i < n-1){
            if(array[i] > maxRight[i+1])
                cout<<0;
            else
                cout<<maxRight[i+1] - array[i] + 1;
        }
        else
            cout<<0;
        cout<<' ';
    }
    cout<<'\n';
}
