/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vll vectorw<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int N,B;
        cin >> N >> B;
        int tabArea = 0;
        for(int i=0;i<N;i++){
            pii tab;
            int price;
            cin >> tab.first >> tab.second >> price;
            if(price <= B && tabArea < tab.first * tab.second){
                tabArea = tab.first * tab.second;
            }
        }
        if(tabArea == 0)
            cout<<"no tablet";
        else
            cout<<tabArea;
        cout<<'\n';
    }
}
