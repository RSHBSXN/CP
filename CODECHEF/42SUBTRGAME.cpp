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
int allPos(vi &ARR,int index,int gcd){
    if(index == ARR.size())
        return gcd == 1;
    else{
        int count = 0;
        if(gcd == -1)
        gcd = 
        count = 1 + allPos(ARR,index+1,__gcd(gcd,ARR[index]));
        count += allPos(ARR,index+1,gcd);
        return count;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i : arr)
            cin >> i;
        cout<<allPos(arr,1,arr[0]) + allPos(arr,1,-1)<<'\n';
    }
}
