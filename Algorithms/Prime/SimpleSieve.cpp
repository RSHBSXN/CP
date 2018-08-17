#include <iostream>
#include <vector>
#include <map>
#include <chrono>
using namespace std;
typedef unsigned  long long ull;
vector<ull> Primes;
void makeMultUneven(vector<bool> &Nums,int N,int number){
    for(ull i = number*2;i <= N; i += number)
        Nums[i] = false;
} 
vector<ull> sieve(int Left,int Right){
    vector<bool> Nums(Right+1,true); 
    makeMultUneven(Nums,Right,2);
    makeMultUneven(Nums,Right,3);
    bool left = false,right = false;
    if(Left <= 2)
        Primes.push_back(2);
    if(Left <= 3)
        Primes.push_back(3);
    for(ull i = 6;i<=Right || i-1 <= Right; i += 6){
        if(Nums[i - 1] != false){
            left = true;
            if(i >= Left)
                Primes.push_back(i-1);
        }
        if(i+1 <= Right && Nums[i + 1] != false){
            right = true;
            if(i >= Left)
                Primes.push_back(i+1);
        }
        if(left)
            makeMultUneven(Nums,Right,i-1);
        if(right)
            makeMultUneven(Nums,Right,i+1);
        left = false;
        right = false;
    }
    return Primes;
}
void display(vector<ull> ARR){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ull i : ARR)
        cout<<i<<'\n';
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        ull L,R;
        cin >> L >> R;
        vector<ull> Primes = sieve(L,R);
        display(Primes);
    }
}
