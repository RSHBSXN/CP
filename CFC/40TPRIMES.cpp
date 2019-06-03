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
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
bool isNotPrime[1000001] = {false};
void build(){
    for(int i=2;i*i<=1000000;++i){
        if(!isNotPrime[i]){
            for(int j=i*i;j<=1000000;j+=i){
                isNotPrime[j] = true;
            }
        }
    }
}
int main(){
    FASTIO;
    build();
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        ll num;
        cin >> num;
        ll sqrtt = sqrtl(num);
        if(sqrtt * sqrtt == num && num != 1 && !isNotPrime[sqrtt])
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }

}
