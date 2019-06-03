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
vector<vector<pii>> Components;
unordered_map<string,int> Has;

int solve(int r,int bud){
    int l = 0;
    while(r - l > 1){
        int mid = (r + l)/2;

    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll bud;
        cin >> n >> bud;
        int index = 0;
        for(int i=1;i<=n;++i){
            string type,name;
            cin >> type;
            if(Has.find(type) == Has.end()){
                Components.push_back(vector<pii>(0));
                Has[type] = index++;
            }
            pii pAndQ;
            cin >> name >> pAndQ.first >> pAndQ.second;
            Components[Has[type]].push_back(pAndQ); 
        }
        int MaxQ = INT32_MAX;
        for(int i=0;i<Components.size();++i){
            sort(Components[i].begin(),Components[i].end(),[](pii a,pii b){
                return a.second > b.second;
            });
            MaxQ = min(MaxQ,Components[i][0].second);
        }
        cout<<MaxQ<<'\n';
    }
}
