/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define fun(a,b) a*b=10
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
string fraction(LL a,LL b){
    if(a > 0){
        LL gcd = __gcd(a,b);
        a /= gcd;
        b /= gcd;
        return to_string(a) + " / " + to_string(b);
    }
    else
        return "0 / 1";
}
int main(){
     // pow(a,b)= a^b(exponential)
 	cout<<-3%2;
}
