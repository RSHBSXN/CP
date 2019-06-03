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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct date{
    int day[3];
    bool leap;
    date(string s){
        stringstream sin(s);
        string sc;
        for(int i=0;i<3;++i){
            getline(sin,sc,':');
            day[3 - i-1] = stoi(sc); 
        }
        leap = ((day[2] % 400 == 0) || (day[2] % 4 == 0 && (day[2] % 100)));
    }
    bool operator > (date d){
        return (day[2] > d.day[2] || ((day[2] == d.day[2]) && (day[1] > d.day[1] || ((day[1] == d.day[1]) && day[0] > d.day[0])))); 
    }
};
int getLeapYears(int year){
        return (year/400) + ((year/4) - (year/100));
}
int Month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int prfxMon[13] = {0};
int main(){
    int sum = 0;
    for(int i=0;i<13;++i){
        sum += Month[i];
        prfxMon[i] = sum;
    }
    string a,b;
    cin >> a >> b;
    date d1(a),d2(b);
    int days = 0;
    if(d1 > d2)
        swap(d1,d2);
    int leapYr = 0;
    leapYr = getLeapYears(d2.day[2]-1);
    leapYr -= getLeapYears(d1.day[2] - 1);
    days = (leapYr * 366) + ((d2.day[2] - d1.day[2] - leapYr) * 365);
    
    days = days - prfxMon[d1.day[1]-1] - d1.day[0]                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;
    
    if(d1.leap && d1.day[1] > 2)
        days--;
    
    days = days + prfxMon[d2.day[1] - 1] + d2.day[0];
    if(d2.leap && d2.day[1] > 2)
        days++;
    cout<<days<<'\n';

}
