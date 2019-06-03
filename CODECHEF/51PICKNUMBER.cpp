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

unordered_map<int,string> MAP = {{10,"10"},{11,"6 5"},{12,"7 5"},{13,"8 5"},{14,"9 5"}};
void result(int A){
    if(A >= 15){
        cout<<10<<' ';
        result(A-10);    
    }
    else{
        if(A >= 5 && A <= 9)
            cout<<A<<' ';
        else{
            cout<<MAP[A]<<' ';
        }
    }
}
int main(){
    FASTIO;
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        if(N < 5)
            cout<<-1;
        else
            result(N);
        cout<<'\n';
    }
}
