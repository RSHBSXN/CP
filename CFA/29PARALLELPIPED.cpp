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
    double A,B,C;
    cin >> A >> B >> C;
    double alp = (A/B),beta = B/C,gamma = C/A;
    double side1 = sqrt((alp / beta) * B);
    double side2 = sqrt((beta/gamma)*C);
    double side3 = sqrt((gamma/alp)*A);
    cout<<(4 * (side1 + side2 + side3))<<'\n';
}
