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
#define PREC 1e-9

int main(){
    FASTIO;
    int unseen = 0;
    int n,q;
    cin >> n >> q;
    map<int,int> APP;
    set<int> NOT[n+1];
    int Sno = 1;
    int total = 0;
    int Unread[n+1] = {0};
    int first = 1;
    while(q--){
        int type,num;
        cin >> type >> num;
        switch(type){
            case 1:
                Unread[num]++;
                total++;
                APP[Sno] = num;
                NOT[num].insert(Sno++);
                break;
            case 2:
                total -= Unread[num];
                Unread[num] = 0;
                NOT[num].clear();
                break;
            case 3:
                for(;first <= num;first++){
                    if(NOT[APP[first]].find(first) != NOT[APP[first]].end()){
                        Unread[APP[first]]--;
                        total--;
                        NOT[APP[first]].erase(first);
                    }
                }
                break;
        }
        cout<<total<<'\n';
    }
}
