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
void getSub(vi &arr,int ind,int sum){
    if(ind == arr.size()){
        cout<<sum<<' ';
    }
    else{
        getSub(arr,ind+1,sum + arr[ind]);
        getSub(arr,ind+1,sum);
    }

}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int size = pow(2,n);
        vi sum(size);
        for(int i=0;i<size;++i){
            cin >> sum[i];
        }
        sort(sum.begin(),sum.end());
        for(int i=0;i<size;++i)
            cout<<sum[i]<<' ';
        cout<<'\n';
        int i = 1;
        while(i < size && sum[i] == 0){
            i++;
        }
        vi arr(n,0);
        if(i != size){
            int zeroSub = i;
            int zeroes = log2(zeroSub);
            for(int j = zeroes;j<n;++j){
                arr[j] = sum[i];
                i += zeroSub;
            }
        }
        for(int i : arr)
            cout<<i<<' ';
        cout<<'\n';
    }
    
}
