
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define XLL __int128
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORILL(i,a,b) for(ll i=a;i<b;i++)
#define FORDLL(i,a,b) for(ll i=a;i>=b;i--)
#define ci pair<char,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define MATRIX vector<vector<int>>
typedef long long ll;
typedef unsigned long long ull;

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        int answer;
        if(min(m,n) == 1)
            answer = max(m,n);
        else if(min(m,n) == 2){
            int r = max(m,n);
            answer = (r/4) * 4;
            if(r % 4 == 1)
                answer += 2;
            else if(r % 4 != 0)
                answer += 4;
        }
        else{
            answer = n * m;
            if(answer & 1){
                answer = (answer/2) + 1;
            }
            else{
                answer /=2;
            }
        }
        cout<<answer<<'\n';
    }
}