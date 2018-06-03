#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long ulong;
int main(){
    fstream fin;
    fin.open("input.txt",ios::in);
    ulong n;
    fin >> n;
    fin.close();
    vector<ulong>MinFact(n+1);
    for(ulong p = 2;p<=n;p++){
        if(MinFact[p] == 0){
            MinFact[p] = p;
            for(ulong i = p * p;i<=n;i+=p){
                if(MinFact[i] == 0)
                    MinFact[i] = p;
            }
        }
    }ulong Min;
    ulong MaxFacts = 0;
    for(ulong p = 2;p<=n;p++){
        ulong divisors = 1;
        ulong value = p;
        while(value > 1){
            ulong currPrime = MinFact[value];
            ulong power = 0;
            while(MinFact[value] == currPrime){
                ++power;
                value /= currPrime;
            }
            divisors = divisors * (power + 1);
        }
        if(divisors > MaxFacts){
            MaxFacts = divisors;
            Min = p;    
        }
    }
    fin.open("output.txt",ios::out);
    fin<<n - Min+1;
}
