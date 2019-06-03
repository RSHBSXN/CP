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
bool isO(char MAT[][100],int i,int j,int n){
    return i >= 0 && j >= 0 && i < n && j < n && MAT[i][j] == 'o';
}
int main(){
    int n;
    cin >> n;
    char MAT[100][100];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cin >> MAT[i][j];
    }
    int rdir[] = {1,-1,0,0};
    bool result = true;
    int cdir[] = {0,0,1,-1};
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int countO = 0;
            for(int d=0;d<4;++d){
                if(isO(MAT,i+rdir[d],j+cdir[d],n))
                    countO++;
            }
            if(countO & 1){
                result = false;
                break;
            }            
        }
        if(!result)
            break;
    }
    cout<<((result)?"YES":"NO")<<'\n';
}
