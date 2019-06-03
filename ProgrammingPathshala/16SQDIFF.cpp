/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
bool isPrime(ll num){
    bool prime = true;
    for(ll i = 2;i*i<=num && prime;++i){
        if(num % i == 0)
            prime = false;
    }
    return prime;
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        ll A,B;
        cin >> A >> B;
        ll one = A+B;
        ll two = A-B;
        if(two != 1){
            cout<<"NO";
        }
        else{
            cout<<((isPrime(one))?"YES":"NO");
        }
        cout<<'\n';
    }
}
