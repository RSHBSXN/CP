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
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
struct photo{
    int id;
    int id2;
    char orient;
    bool exist;
    bool slided;
    unordered_set<string> tags;
    static int count;
    photo(){}
    photo(vector<photo> &ARR,vector<photo> &VERT,fstream &fin){
        slided = false;
        exist = true;
        id = count++;
        id2 = -1;
        fin >> orient;
        int M;
        fin >> M;
        for(int i=0;i<M;++i){
            string str;
            fin >> str;
            tags.insert(str);
        }
        if(orient == 'H')
            ARR.push_back(*this);
        else
            VERT.push_back(*this);
    }
};
int photo :: count;
int main(int argc,char **args){
    fstream fin(args[1],ios::in),fout(args[2],ios::out);
    int n;
    fin >> n;
    vector<photo> ARR,VERT;
    for(int i=0;i<n;i++){
        photo(ARR,VERT,fin);
    }
    // sort(ARR.begin(),ARR.end(),[](photo &a,photo &b){
    //     return a.tags.size() > b.tags.size();
    // // });
    // fstream fout(args[2],ios::out);
    // fout<<ARR.size()<<'\n';
    // for(int i=0;i<ARR.size();++i){
    //     if(!ARR[i].slided){
    //         int maxInt = 0,id2 = -1;
    //         fout<<ARR[i].id<<'\n';
    //         for(int j=i+1;j<ARR.size();++j){
    //             if(!ARR[j].slided){
    //                 int comm = 0,A = ARR[i].tags.size(),B = ARR[j].tags.size();
    //                 for(string x : ARR[j].tags){
    //                     if(ARR[i].tags.find(x) != ARR[i].tags.end()){
    //                         comm++;
    //                         A--;
    //                         B--;
    //                     }
    //                 }
    //                 if(MIN(A,B,comm) >= maxInt){
    //                     maxInt = MIN(A,B,comm);
    //                     id2 = j;
    //                 }
    //             }
    //         }
    //         fout<<ARR[id2].id<<'\n';    
    //         ARR[id2].slided = true;
    //     }
    // }
    fout<<ARR.size() + VERT.size()<<'\n';

    for(int i=0;i<ARR.size();++i){
        fout<<ARR[i].id<<'\n';
    }
    for(int i=0;i<VERT.size();i += 2){
        fout<<VERT[i].id <<' '<<VERT[i+1].id<<'\n';
    }
    fout.close();
    fin.close();
}