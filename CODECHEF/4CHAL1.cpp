/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL unsigned long long
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
LL LCM(LL a , LL b){
    return (a * b)/__gcd(a,b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        LL N,A,B,K;
        LL total = 0;
        cin >> N >> A >> B >> K;
        if(__gcd(A,B) == min(A,B)){
            total += N / min(A,B);
            total -= N / LCM(A,B);
        }
        else{
            total += N / A;
            total += N / B;
            total -= N/LCM(A,B);
        }
        cout<<((total >= K)?"Win":"Lose")<<'\n';
    }
}
