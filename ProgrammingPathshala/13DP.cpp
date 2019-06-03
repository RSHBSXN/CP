#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define XLL __int128
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<pii>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<LL>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
int waysToReach(MATRIX &MEMO,int i,int j){
    if(i >= MEMO.size() || j >= MEMO[0].size()){
        return 0;
    }
    else if(MEMO[i][j] == -1){
        int &ref = MEMO[i][j];
        if(i == MEMO.size()-1 && j == MEMO[0].size()-1)
            ref = 1;
        else
            ref = waysToReach(MEMO,i+1,j) + waysToReach(MEMO,i,j+1);
        return ref;
    }
    else    
        return MEMO[i][j];
}
int getMinPath(MATRIX &MAT,MATRIX &MEMO,int i,int j){
    if(i >= MAT.size() || j >= MAT[0].size())
        return INT32_MAX;
    else if(MEMO[i][j] == -1){
        int &ref = MEMO[i][j];
        if(i == MEMO.size()-1 && j == MEMO[0].size())
            ref = MEMO[i][j];
        else{
            int Min = MIN(getMinPath(MAT,MEMO,i+1,j),getMinPath(MAT,MEMO,i,j+1),getMinPath(MAT,MEMO,i+1,j+1));
            if(Min != INT32_MAX)
                ref = MAT[i][j] + Min;
            else
                ref = Min;
        }
        return ref;
    }
    else
        return MEMO[i][j];
}
int getMinCost(vi &ARR,vi &MEMO,int X){
    if(X == 0)
        return 0;
    else if(MEMO[X] == -1){
        int &ref = MEMO[X];
        int Min = INT32_MAX;
        for(int i=0;i<ARR.size() && i+1 <= X;++i){
            Min = min(Min,ARR[i] + getMinCost(ARR,MEMO,X - (i+1)));
        }
        ref = Min;
        return ref;
    }
    else
        return MEMO[X];
}
bool canReachEnd(vi &ARR,vi &MEMO,int i){
    if(i >= ARR.size())
        return false;
    else if(MEMO[i] == -1){
        int x = ARR[i];
        int &ref = MEMO[i];
        if(i == ARR.size()-1)
            ref = true;
        else if(x == 0)
            ref = false;
        else{
            bool canReach = false;
            for(int j=i+1; (j<=(i + x)) && j < ARR.size() && !canReach;++j){
                canReach = canReachEnd(ARR,MEMO,j);
            }
            ref = canReach;
        }
        return ref;
    }
    else
        return MEMO[i];
}
int waysToEncrypt(string s,vi &MEMO,int index){
    if(index < 0)   
        return 1;
    else if(MEMO[index] == -1){
        int &ref = MEMO[index];
        if(index == 0)
            ref = s[index] == '0';
        else{
            if(s[index] == '0'){
                if(s[index-1] == '1' || s[index-1] == '2')
                    ref = waysToEncrypt(s,MEMO,index-2);
                else
                    ref = 0;
            }
            else{
                if(s[index-1] == '1' || (s[index-1] == '2' && s[index] <= '6')){
                    ref = waysToEncrypt(s,MEMO,index-2);
                }
                ref += waysToEncrypt(s,MEMO,index-1);
            }
        }
        return ref;
    }
    else
        return MEMO[index];
}
bool subsetSum(vi ARR,map<pii,bool> &MEMO,int index,int sum){
    if(index == ARR.size())
        return sum == 0;
    else{
        if(MEMO.find({sum,index}) == MEMO.end()){
            bool &ref = MEMO[{sum,index}];
            bool incl = false,nIncl = false;
            if(ARR[index] <= sum)
                incl = subsetSum(ARR,MEMO,index+1,sum - ARR[index]);    
            nIncl = subsetSum(ARR,MEMO,index+1,sum);
            ref = incl || nIncl;
            return ref;
        }
        else
            return MEMO[{sum,index}];
    }
}
int ZeroOneKnpSck(vii &ARR,int index,MATRIX &MEMO,int profit,int cap){
    if(index == ARR.size()){
        return profit;
    }
    else{
        if(MEMO[cap][index] == -1){
            int incl = 0,excl = 0;
            if(ARR[index].first <= cap)
                incl = ZeroOneKnpSck(ARR,index+1,profit + ARR[index].second,cap - ARR[index].first);
            excl = ZeroOneKnpSck(ARR,index+1,profit,cap);
            MEMO[cap][index] =  max(incl,excl);
            return MEMO[cap][index];
        }
        else
            return MEMO[cap][index];
    }
}
int main(){
    int N;
    cin >> N;
    vi ARR(N+1);
    for(int &i : ARR)
        cin >> i;
    for(int i=ARR.size()/2;i>=1;i--){
        heapify(ARR,i);
    }
}
