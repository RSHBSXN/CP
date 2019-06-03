/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vll vector<LL>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int getLstOcc(int A,int X){
    return A/X;
}
int getIndex(int i,int j){
    return i - j +1;
}
void doOper(int X,int &value,int &l,int &r){
    l = (X/value)+1;
    value = X/l;
    if(value > 0)
        r = X/value;
    
}
int getPosition(vi &ARR,int K){
    vll angry(ARR.size(),0),prfx(ARR.size(),0);
    for(int i=0;i<ARR.size();++i){
        int lastVal,j;
        for(j=1;j*j <= ARR[i];++j){
            int value = ARR[i]/j;
            //if position exist 
            int index = getIndex(i,j);
            
            if(index >= 0 && value >= 1){
                angry[index] += value;
                lastVal = value;
            }
            else{
                lastVal = -1;
                break;
            }
        }
        if(lastVal == -1)
            continue;
        int l,r;
        doOper(ARR[i],lastVal,l,r);
        while(lastVal > 0 && getIndex(i,l) >= 0 ){
            int right = getIndex(i,r);
            int left = getIndex(i,l);
            cout<<left<<' '<<right<<'\n';
            if(max(left,right) < ARR.size()){
                //prfx[right] += lastVal;
                doOper(ARR[i],lastVal,l,r);
            }
            else
                break;
        }
    }
    LL sum = 0;
    int position = ARR.size()+1;
    for(int i = ARR.size()-1;i>=0;i--){
        sum += prfx[i];
        angry[i] += sum;
        if(angry[i] <= K)
            position = i+1;
    }
    return position;
}
int main(){
    FASTIO;
    LL t;
    cin >> t;
    while(t--){
        int N,K;
        cin >> N >> K;
        vi ARR(N);
        for(int &i : ARR)
            cin >> i;
        int pos = getPosition(ARR,K);
        cout<<pos<<'\n';
    }
}
