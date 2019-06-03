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
#define UMAP unordered_map
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
LL LCM(LL a,LL b){
    return (a * b)/__gcd(a,b);
}
class fraction{
    public:
        LL num,den;
        fraction(){
            num = 0,den = 1;
        }
        fraction(LL n,LL d){
            num = n,den = d;       
            if(n != 0)
                reduce();
            else
                den = 1;     
        }
        void reduce(){
            LL gcd = __gcd(num,den);
            num /= gcd;
            den /= gcd;
        }
        fraction operator +(const fraction f){
            LL lcm = LCM(den,f.den);
            LL newN = (lcm/den) * num;
            newN += (lcm/f.den) * f.num;
            return fraction(newN,lcm);
        }
        fraction operator *(const fraction f){
            return fraction(num * f.num,den * f.den);
        }
};
void extEucl(UMAP<LL,LL> &MAP,LL A,LL B){
    LL a = 1;
    LL b = -A/B;    
    if((A % B) == 1){
        MAP[A] = a;
        MAP[B] = b; 
    }
    else{
        extEucl(MAP,B,A%B);
        a *= MAP[A % B];
        b *= MAP[A % B];
        MAP.erase(A%B);
        MAP[A] = a;
        MAP[B] += b;
    }
}
LL powll(LL x,LL y){
    if(y == 0)
        return 1;
    else{
        LL m = pow(x,y/2);
        if(y & 1)
            return m * m * x;
        else
            return m * m;
    }
}
fraction getP(int N,int K,int M){
    if(M == 1)
        return fraction(1,N);
    else if(N > K)
        return getP(N - ((N/K)*K),K,M-1);
    else if((M & 1) == 0){
        fraction f = getP(N,K,M-1);
        M--;
        int pw = (M/2)+1;
        //                  a               d                       rn
        fraction num = fraction(1,N+K) * fraction(powll(N-1,pw),powll(N,pw));
        return f + num;
    }
    else{
        int pw = (N/2)+1;
        LL xn = powll(N-1,pw-1);
        LL yn = powll(N,pw-1);
        LL xn = xn * N;
        
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N,K,M;
        cin >> N >> K >> M;
        fraction a,r,res;
        if(M == 1){
            res = fraction(1,N);
        }
        else{
            res = getP(N,K,M);
        }
        cout<<res.num<<'/'<<res.den<<'\n';
        UMAP<LL,LL> MAP;
        extEucl(MAP,res.den,MOD);
        MAP.erase(MOD);
        if(MAP[res.den] < 0)
            MAP[res.den] += MOD;
        cout<<(res.num * MAP[res.den])%MOD<<'\n';

    }

}