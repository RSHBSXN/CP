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

int main(){
    int n,X,Y;
    cin >> n >> X >> Y;
    vector<pii> A(n);
    for(pii &x : A)
        cin >> x.first;
    for(pii &x : A)
        cin >> x.second;
    sort(A.begin(),A.end(),[](pii &s,pii &t){
        return abs(s.first - s.second) >= abs(t.second - t.first);
    });
    int a = 0,b = 0;
    int profit = 0;
    for(int i=0;i<n;i++){
        if(A[i].first > A[i].second){
            if(a < X){
                profit += A[i].first;
                a++;
            }
            else{
                profit += A[i].second;
                b++;
            }
        }
        else if(A[i].first <= A[i].second){
            if(b < Y){
                profit += A[i].second;
                b++;
            }
            else{
                profit += A[i].first;
                a++;
            }
        }
    }
    cout<<profit<<'\n';
}