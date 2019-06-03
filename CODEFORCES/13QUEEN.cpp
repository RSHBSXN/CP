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
    FASTIO;
    int n;
    cin >> n;
    vector<bool> hate(n+1);
    vector<int> parent(n+1);
    MATRIX ADJLST(n+1);
    for(int i=1;i<=n;++i){
        int num,ht;
        cin >> num;
        if(num != -1){
            ADJLST[num].push_back(i);
            parent[i] = num;
        }
        cin >> ht;
        hate[i] = ht;
    }
    bool printed = false;
    for(int i=1;i<hate.size();++i){
        if(hate[i]){
            //Check all children
            int node = i;
            bool allHate = true;
            for(int j=0;j<ADJLST[node].size();j++){
                int adjc = ADJLST[node][j];
                if(!hate[adjc]){
                    allHate = false;
                    break;
                }
            }
            if(allHate){
                printed = true;
                cout<<node<<' ';
                int par = parent[node];
                vector<int> :: iterator itr;
                for(itr = ADJLST[par].begin(); itr != ADJLST[par].end();itr++){
                    if(*itr == node){
                        break;
                    }
                }
                ADJLST[par].erase(itr);
            }
        }
    }
    if(!printed)
        cout<<-1;
    
    cout<<'\n';
}
