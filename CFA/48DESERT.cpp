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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define EPS 1e-9
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct type{
    int id;
    int fuel;
    int dist;
    type(){}
    type(int d,int i,int f = -1){
        id = i;
        fuel = f;
        dist = d;
    }
};
vector<type> Events;
double petrol(int curr,double prev,int fuelCon,int leak){
    return (((curr - prev)/100)* fuelCon) + ((curr-prev)*leak);
}
//id = 0 (fuel), 1(Leak), 2(Gas), 3(Mechanic), 4(Goal)
bool canStartWith(double strt){
    double org = strt;
    double currDist = 0;
    int fuelCon = 0;
    int leak = 0;
    for(int i=0;i<Events.size();++i){
        double req = petrol(Events[i].dist,currDist,fuelCon,leak);
        if(req > strt)
            return false;
        strt -= req;
        currDist = Events[i].dist;
        switch(Events[i].id){
            case 0:
                fuelCon = Events[i].fuel;
                break;
            case 1:
                leak++;
                break;
            case 2:
                strt = org;
                break;
            case 3:
                leak = 0;
                break;
        }
    }
    return true;
}
double binarySearch(){
    double L = 0,R = 10000.0;
    while(R - L >= EPS){
        double mid = (L + R)/2;
        if(canStartWith(mid))
            R = mid;
        else
            L = mid;
    }
    return L;
}
type input(){
    int d,f;
    string s;
    cin >> d >> s;
    if(s == "Fuel"){
        cin >> s;
        cin >> f;
        return type(d,0,f);
    }
    else if(s == "Gas"){
        cin >> s;
        return type(d,2);
    }
    else if(s == "Leak")
        return type(d,1);
    else if(s == "Mechanic")
        return type(d,3);
    else
        return type(d,4);
}
int main(){
    FASTIO;
    int dist;
    bool ended = false;
    while(!ended){
        type t;
        while(true){
            t = input();
            if(t.id == 0 && t.fuel == 0){
                ended = true;
                break;
            }
            Events.push_back(t);
            if(t.id == 4)
                break;
        }
        if(!ended)
            cout<<fixed<<setprecision(3)<<binarySearch()<<'\n';
        Events.clear();
    }
}
