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
    // FASTIO;
    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int>ARR(n);
        for(int i=0;i<n;i++)
            cin>>ARR[i];
        sort(ARR.begin(),ARR.end(),greater<int>());

        
        int maxim = -1;
            for(int j=ARR[0];j>=ARR[0]-d;j--){
                int gcd = j;
                
                for(int k=1;k<n;k++){
                    
                    for(int kj=ARR[k];kj>=ARR[k]-d;kj--){        
                        if(j%kj!=0){
                            continue;
                        }else{
                            gcd = __gcd(gcd,kj);
                            break;
                        }
                    }
                    
                }
                maxim = max(maxim,gcd);
                
            }
            cout<<maxim<<'\n';
        }
    return 0;
}
