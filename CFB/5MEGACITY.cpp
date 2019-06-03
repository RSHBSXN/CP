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
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct coord{
    int x,y,p;
    double dist;
    void setEuclDist(){
        dist = sqrt((x * x) + (y * y));
    }
    coord(){
        x = 0,y = 0,p = 0;
    }
};
double getMinRadius(vector<coord> &array,LL Population){
    const LL Million = 1000000;
    sort(array.begin(),array.end(),[](coord &a,coord &b){
        return a.dist < b.dist || a.dist == b.dist && a.p > b.p;
    });
    LL sum = 0,i;
    for(i=0;i<array.size() && (sum + Population) < Million;++i){
        sum += array[i].p;
    }
    if(sum + Population < Million)
        return -1;
    else
        return array[i-1].dist;
}
int main(){
    FASTIO;
    int n,pop;
    cin >> n >> pop;
    vector<coord> array(n);
    for(coord &c : array){
        cin >> c.x >> c.y >> c.p;
        c.setEuclDist();
    }
    double res = getMinRadius(array,pop);
    if(res == -1)
        cout<<-1;
    else
        cout<<fixed<<setprecision(7)<<res;
    cout<<'\n';
}
