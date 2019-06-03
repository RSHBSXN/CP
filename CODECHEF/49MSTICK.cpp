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
struct stick{
    int l,w;
};
int binarySearch(vector<stick> &total,stick s){
    if(total.size() == 0){
        total.push_back(s);
        return 0;
    }
    else{
        int l = 0,r = total.size()-1;
        while(r - l > 1){
            int mid = (r + l) >> 1;
            if(total[mid].w <= s.w){
                r = mid;
            }
            else{
                l  = mid+1;
            }
        }
        if(total[l].l <= s.l && total[l].w <= s.w)
            return l;
        else if(total[r].l <= s.l && total[r].w <= s.w)
            return r;
        else
            return -1;
    }
}
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<stick> sticks(n);
        vector<stick> created;
        for(int i=0;i<n;++i)
            cin >> sticks[i].l >> sticks[i].w;
        sort(sticks.begin(),sticks.end(),[](stick a,stick b){
            return a.l < b.l || (a.l == b.l && a.w > b.w);
        });
        for(int i=0;i<n;++i){
            int ind = binarySearch(created,sticks[i]);
            if(ind != -1){
                created[ind] = sticks[i];
            }
            else{
                created.push_back(sticks[i]);
            }
        }
        cout<<created.size()<<'\n';
    }
}
