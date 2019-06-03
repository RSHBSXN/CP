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
vector<double> prob;
double calculateAll(int mask){
    double res = 1;
    for(int j=0;j<prob.size();++j){
        if(mask & (1 << j))
            res *= prob[j];
        else
            res *= (1.0 - prob[j]); 
    }
    return res;
}
int main(){
    FASTIO;
    int n,r;
    int c = 1;
    while(cin >> n >> r && (n != 0 || r != 0)){
        prob = vector<double>(n);
        for(int i=0;i<n;++i)
            cin>>prob[i];
        vector<int> Masks;
        double d = 0;
        cout<<"Case "<<c++<<":\n";
        if(r > 0){
            for(int i=1;i<(1 << n);++i){
                int count = 0;
                for(int j=0;j<n;++j){
                    if(i & (1 << j))
                        count++;
                }
                if(count == r){
                    Masks.push_back(i);
                    d += calculateAll(i);
                }
            }
            for(int i=0;i<n;++i){
                double a = 0;
                for(int j=0;j<Masks.size();++j){
                    if(Masks[j] & (1 << i)){
                        a += calculateAll(Masks[j]);
                    }
                }
                cout<<fixed<<setprecision(6)<<a/d<<'\n';
            }
        }
        else
            for(int i=0;i<n;++i)
                cout<<fixed<<setprecision(6)<<0.0<<'\n';
    }
}
