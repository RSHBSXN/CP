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
int main(){
    int N;
    cin >> N;
    int ARR[N][N];
    int left = 0,top = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin >> ARR[i][j];
            if(i > 0)
                ARR[i][j] += ARR[i-1][j];
            if(j > 0)
                ARR[i][j] += ARR[i][j-1];
            if(i > 0 && j > 0)
                ARR[i][j] -= ARR[i-1][j-1];
        }
    }
    int maxSum = INT32_MIN;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=i;k<N;++k){
                for(int l=j;l<N;++l){
                    int sum = ARR[k][l];
                    if(i > 0)
                        sum -= ARR[i-1][l];
                    if(j > 0)
                        sum -= ARR[k][j-1];
                    if(i > 0 && j > 0)
                        sum += ARR[i-1][j-1];
                    maxSum = max(maxSum,sum);
                }
            }
        }
    }
    cout<<maxSum<<'\n';
}
