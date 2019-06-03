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
struct coord{
    int ind;
    int dist;
    int right;
    bool calculated = false;
};
int getMax(unordered_map<int,coord> &UMAP,vector<coord> &arr,int k,int index){
    if(index+1 < arr.size()){
        if(arr[index+1].dist - arr[index].dist <= k)
            UMAP[arr[index].ind].right = getMax(UMAP,arr,k,index+1);
        else
            UMAP[arr[index].ind].right = arr[index].dist + k;
    
        UMAP[arr[index].ind].calculated =  true;
        return UMAP[arr[index].ind].right;
    }
    else
        return (UMAP[arr[index].ind].right = arr[index].dist + k);
}
int main(){
    FASTIO;
    int n,k,p;
    cin >> n >> k >> p;
    vector<coord> arr(n);
    for(int i=0;i<arr.size();++i){
        cin >> arr[i].dist;
        arr[i].ind = i+1;
    }
    sort(arr.begin(),arr.end(),[](coord &a ,coord &b){
        return a.dist < b.dist;
    });
    unordered_map<int,coord> UMAP;
    for(int i=0;i<arr.size();++i)
        UMAP[arr[i].ind] = arr[i];
    for(int i=0;i<arr.size();++i){
        if(!UMAP[arr[i].ind].calculated)
            getMax(UMAP,arr,k,i);
    }
    
    for(int i=0;i<p;++i){
        int a,b;
        cin >> a >> b;
        if(UMAP[a].dist > UMAP[b].dist)
            swap(a,b);
        if(UMAP[a].right >= UMAP[b].dist || UMAP[b].right <= UMAP[a].dist)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<'\n';
    }
    /*
        0   3   8   5   12
        1   2   3   4   5

        0   3   5   8   12
        1   2   4   3   5
        
    */
}
