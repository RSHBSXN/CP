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
struct dimen{
    int w,h;
};
int binarySearch(vector<dimen> &Nested,dimen i){
    if(Nested.size() == 0){
        Nested.push_back(i);
        return 0;
    }
    else{ 
        int l = 0,r = Nested.size()-1;
        while(r - l > 1){
            int mid = (r + l) >> 1;
            if(Nested[mid].h > i.h){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        if(Nested[l].w > i.w && Nested[l].h > i.h)
            return l;
        else if(Nested[r].w > i.w && Nested[r].h > i.h)
            return r;
        return -1;
    } 
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<dimen>Dolls(n);
        vector<dimen> Nested;
        for(int i=0;i<n;++i){
            cin >> Dolls[i].w >> Dolls[i].h;
        }
        sort(Dolls.begin(),Dolls.end(),[](dimen a,dimen b){
            return a.w > b.w || ((a.w == b.w) && a.h < b.h);
        });
        for(int i=0;i<n;++i){
            int ind = binarySearch(Nested,Dolls[i]);
            if(ind != -1){
                Nested[ind] = Dolls[i];
            }
            else{
                Nested.push_back(Dolls[i]);
            }
        }
        cout<<Nested.size()<<'\n';
    }
}