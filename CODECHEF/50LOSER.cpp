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
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        ll K,L,N;
        cin >> K >> L >> N;
        if(K >= L)
            cout<<"Nikhil";
        else{
            ll t1 = (2*N) - 1;
            ll t2 = K - L;
            ll val1 = -t1 + (sqrt((t1*t1) - (8 * t2)));
            val1 /= 2;
            
            if(val1 >= 0){
                cout<<(((val1) & 1)?"Sahil":"Nikhil");
            }
        }
        cout<<'\n';
    }
        
}
