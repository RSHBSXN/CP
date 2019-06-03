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
    int n;
    cin >> n;
    if(n <= 2)
        cout<<1<<"\n"<<1;
    else if(n == 3){
        cout<<2<<'\n';
        cout<<"1 3";
    }
    else if(n == 4){
        cout<<4<<'\n';
        cout<<"3 1 4 2";
    }
    else{
        cout<<n<<'\n';
        for(int i=1;i<=n;i+=2)
            cout<<i<<' ';
        for(int i=2;i<=n;i+=2)
            cout<<i<<' ';
    }
    cout<<'\n';
}
