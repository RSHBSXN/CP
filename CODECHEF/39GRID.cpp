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
void Fill(MATRIXC &MAT,MATRIX &DP,int i,int j,int n){
    if(MAT[i][j] != '.')
        DP[i][j] = -3;
    else{
        //Check for right dir
        if(j < n-1 && DP[i][j+1] <= -2)
            DP[i][j] = -2;
        if(i < n-1 && (DP[i+1][j] == -1 || DP[i+1][j] == -3))
            DP[i][j] += -1;
    }
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        MATRIXC MAT(N,vector<char>(N));
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)
                cin >> MAT[i][j];
        }
        MATRIX DP(N,vi(N,0));
        for(int i=N-1;i>=0;--i){
            Fill(MAT,DP,N-1,i,N);
            Fill(MAT,DP,i,N-1,N);
        }
        for(int i=N-2;i>=0;i--){
            for(int j=N-2;j>=0;j--){
                Fill(MAT,DP,i,j,N);
            }
        }
        int count = 0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(!DP[i][j])
                    count++;
            }
        }
        /*   0: no obstruction
            -1: obstruction from beneath
            -2: obstruction from right
            -3: obstruction from both sides
        */
       cout<<count<<'\n';
    }
}
