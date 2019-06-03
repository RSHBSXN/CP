#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int L;
        string n;
        cin >> n >> L;
        vector<ll> arr(L);
        vector<ll> numbers;
        for(ll &i : arr)
            cin >> i;
        set<ll> Primes;
        for(int i=0;i<L-1;++i){
            for(int j=i+1;j<L;j++){
                int gcd = __gcd(arr[i],arr[j]);
                if(gcd != 1){
                    Primes.insert(gcd);
                    Primes.insert(arr[i]/gcd);
                    Primes.insert(arr[j]/gcd);
                }
                
            }
        }
        for(int i=0;i<L-1;++i){
            ll gcd = __gcd(arr[i],arr[i+1]);
            ll A = arr[i]/gcd;
            ll B = arr[i+1]/gcd;
            if(i == 0){
                numbers.push_back(A);
                numbers.push_back(gcd);
            }
            numbers.push_back(B);
        }
        unordered_map<ll,char> Chars;
        char c = 'A';
        for(auto x : Primes){
            Chars[x] = c++;
        }
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<numbers.size();++i){
            cout<<Chars[numbers[i]];
        }        
        cout<<'\n';
    }
}