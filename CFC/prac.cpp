#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    long long res = 0;   
    res = c*2;
    res += min(a,b) * 2;
    if(max(a,b) > min(a,b))
        res++;
    cout<<res<<'\n';
}