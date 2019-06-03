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
    vi pedal(n);
    for(int &i : pedal)
        cin >> i;
    int m;
    cin >> m;
    vi rear(m);
    for(int &i : rear)
        cin >> i;
    int maxNum = 0;
    int count = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(rear[j] >= pedal[i] && !(rear[j] % pedal[i])){
                if(maxNum < rear[j]/pedal[i]){
                    count = 1;
                    maxNum = rear[j]/pedal[i];
                }
                else if(maxNum == rear[j]/pedal[i])
                    count++;
            }
        }
    }
    cout<<count<<'\n';
}
