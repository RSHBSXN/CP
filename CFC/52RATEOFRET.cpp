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
#define PREC 1e-9
vi CF;
vi power;
double solve(double x){
    double res = 0.00;
    for(int i = CF.size()-1;i>=0;i--){
        res += CF[i] * pow(1 + x,power[i]);
    }
    return res;
}
double bisection(){
    double l = -0.9999999999,r = 100;
    while(r - l > PREC){
        double mid = (r + l)/2;
        double res = solve(mid);
        if(res < 0)
            r = mid;
        else
            l = mid;
    }
    return l;
}
int main(){
    int t;
    while(cin >> t && t != 0){
        CF = vi(t+1);
        power = vi(t+1);
        for(int i=0;i<=t;++i){
            cin >> CF[i];
            power[i] = t-i;
        }
        double res = bisection();
        cout<<fixed<<setprecision(2)<<res<<'\n';
    }
}
