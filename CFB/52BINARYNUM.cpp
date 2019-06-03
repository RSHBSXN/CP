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
int main(){
    FASTIO;
    string x;
    cin >> x;
    int countlen = 0;
    int i = x.length()-1;
    int ones = 0;
    for(char i : x){
        if(i == '1')
            ones++;
    }
    int ind = x.length()-1;
    int moves = 0;
    while(x[ind] == '0'){
        moves++;
        ind--;
    }
    while(ones > 1){
        int one = 0;
        while(ind >= 0 && x[ind] == '1'){
            one++;
            ind--;
        }
        moves += one + 1;
        ones -= one - 1;
        if(ind >= 0){
            x[ind] = '1';
        }
    }
    cout<<moves<<'\n';
}
