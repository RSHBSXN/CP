/*
    Author: Rishabh Saxena
    All the best!!
    if first element then 
        if index is even go right
        else
            go left
    if second element then
        if index is odd go right
        else
            go right
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
int binarySearch(vi ARR){
    int left = 0,right = ARR.size()-1;
    /*   
        0   1   2   3   4   5   6   7   8
        L                                        R
                M                                   
        M   R
    */
    while(right - left > 1){
        bool changed = false;
        int mid = (left + right)/2;
        if(mid != 0 && ARR[mid-1] == ARR[mid]){
            //if mid points to the second occurence of an element
            mid--;
            changed = true;
        }

        //ensuring that mid always points to the first occurence of a number
        if((mid & 1) == 0){
            //when first occurence occur at even index then we have to move ahead considering that number as a result
            if(changed){
                //We know that this number occured twice so we dont need to consider this number in search space.
                left = mid+2;
            }
            else
                left = mid;

        }
        else
            //Since answer position cannot be at odd index
            right = mid -1;
    }
    //After this loop search space will be reduced to two, now check both of them which one is single occuring
    if((left != 0 || ARR[left] != ARR[left-1]) && (left != ARR.size()-1 || ARR[left] != ARR[left+1]))
        return left;
    else
        return right;
}
int main(){
    int n;
    cin >> n;
    vi ARR(n);
    for(int &i : ARR)
        cin >> i;
    cout<<ARR[binarySearch(ARR)]<<'\n';
}
