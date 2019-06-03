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
    FASTIO;
    int n;
    cin >> n;
    vi MAT(n);
    int total = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int num;
            cin >> num;
            if(i == j){
                MAT[i] = num;
                if(MAT[i] == 1)
                    total++;
            }
        }
    }
    string res;
    int q;
    cin >> q;
    while(q--){
        int type,ind;
        cin >> type;
        switch(type){
            case 1:
            case 2:
                cin >> ind;
                ind--;
                if(MAT[ind] == 1){
                    MAT[ind] = 0;
                    total--;
                }
                else{
                    MAT[ind] = 1;
                    total++;
                }
                break;
            case 3:
                printf("%d",total%2);
                break;
        }
    }
}
