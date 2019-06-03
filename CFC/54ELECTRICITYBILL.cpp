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
array<int,4> Price = {2,3,5,7};
int mul[4] = {100,10000,1000000};
//10^2,10^4.10^6,...
ll calBill(ll units){
    ll bill = 0;
    ll p = 0,prev = 0;
    for(int i=0;i<Price.size()-1;++i){
        p = mul[i];
        if(units > p)
            bill += Price[i] * (p - prev);
        else{
            bill += Price[i] * (units - prev);
            return bill;
        }
        prev = p;
    }
    if(units > p){
        bill += Price[3] * (units - prev);
    }
    return bill;
}
ll bisection(int X,int Y){
    ll L = 1,R = 1000000000 - Y;
    while(R - L > 1){
        ll mid = (R + L) >> 1;
        ll calA = calBill(mid),calB = calBill(mid + Y);
        ll sum = calA + calB;
        cout<<sum<<'\n';
        if(sum >= X)
            R = mid;
        else
            L = mid;
    }
    if(calBill(L) + calBill(L + Y) == X)
        return L;
    else
        return R;
}
int main(){
    ll X,Y;
    // whi
    le(cin >> X >> Y && X != 0 && Y != 0){
    //     ll res = bisection(X,Y);
    //     cout<<calBill(res) + calBill(res+Y)<<'\n';
    //     cout<<res<<'\n';
    // }
    cin >> X >> Y;
    cout<<calBill(X) + calBill(Y)<<'\n';
    
}
