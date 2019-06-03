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
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    int t;
    cin >> t;
    while(t--){
        int N,n;
        cin >> N;
        int sumTwo = 0,sum;
        for(int i=0;i<N;++i){
            int num;
            cin >> num;
            if(num != 0){
                sum += num;
                sumTwo += num-1;
                n++;
            }
        }
        if(sum < 100 || sumTwo > 100){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
    }
}