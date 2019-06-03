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
ll lcm(ll a, ll b){
    return (a * b)/__gcd(a,b);
}
int main(){
    int n,t;
    while(cin >> n >> t && n != 0 && t != 0){
        vi arr(n);
        for(int &i : arr)
            cin >> i;
        for(int i=0;i<t;i++){
            int table;
            cin >> table;
            ll maxVal = 0,minVal = INT32_MAX;
            for(int i1 = 0;i1<n;++i1){
                for(int i2=i1+1;i2<n;i2++){
                    for(int i3=i2+1;i3<n;i3++){
                        for(int i4=i3+1;i4<n;i4++){
                            ll lc = lcm(arr[i1],arr[i2]);
                            lc = lcm(lc,lcm(arr[i3],arr[i4]));
                            int rem = table / lc;
                            maxVal = max(maxVal,rem * lc);
                            if(table % lc == 0)
                                minVal = min(minVal,rem * lc);
                            else
                                minVal = min(minVal,(rem + 1)*lc);
                        }
                    }
                }
            }
            cout<<maxVal<<' '<<minVal<<'\n';
        }
    }
}
