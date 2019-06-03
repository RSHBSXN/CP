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
    int n;
    cin >> n;
    vi boys(n);
    for(int &i : boys)
        cin >> i;
    cin >> n;
    vi girls(n);
    for(int &i : girls)
        cin >> i;
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    int pairs = 0;
    for(int i=0,j=0;i<boys.size() && j < girls.size();){
        if(abs(boys[i] - girls[j]) <= 1){
            pairs++;
            i++;j++;
        }
        else if(boys[i] < girls[j])
            i++;
        else
            j++;
    }
    cout<<pairs<<'\n';
    
}
