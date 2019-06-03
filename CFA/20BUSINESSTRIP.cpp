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
    int k;
    cin >> k;
    int Months[12];
    for(int i=0;i<12;++i)
        cin >> Months[i];
    sort(Months,Months+12,[](int a,int b){
        return a >= b; 
    });
    int height = 0,i;
    for(i=0;height < k && i < 12;++i){
        height += Months[i];
    }
    if(height < k)
        cout<<-1;
    else
        cout<<i;
    cout<<'\n';
}
