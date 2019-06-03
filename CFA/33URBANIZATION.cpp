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
    FASTIO; 
    double n,n1,n2;
    cin >> n >> n1 >> n2;
    if(n1 > n2)
        swap(n1,n2);
    vi arr(n);
    for(int i=0;i<n;++i)
        cin >> arr[i];
    sort(arr.begin(),arr.end(),[](int a,int b){
        return a >= b;
    });
    int i=0,j=0;
    unsigned long long sum1 = 0,sum2=0;
    for(int k=0;k<n;++k){
        if(i < n1)
            sum1 += arr[k],i++;
        else if(j < n2)
            sum2 += arr[k],j++;
        else
            break;
    }
    cout<<fixed<<setprecision(8)<<(sum1/n1) + (sum2/n2)<<'\n'; 
}
