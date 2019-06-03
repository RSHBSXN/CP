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
bool isLucky(int n){
    while(n > 0){
        int rem = n%10;
        if(rem != 4 && rem  != 7)
            return false;
        n /= 10;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    bool someLucky = false;
    for(int i=1;i<=n;++i){
        if(isLucky(i) && n % i == 0){
            someLucky = true;
            break;  
        }
    }
    cout<<((someLucky)?"YES":"NO")<<'\n';
}
