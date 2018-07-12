/*  
    void nQueen(Grid(2D),string positions,stringArray,level,position);
    vector<vector<char>> placeQueen(Grid,level,position)
    bool isSafe(Grid,level,position)

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isSafe(vector<vector<char>> Grid,int level,int pos){
    int N = Grid.size();
    return (level >= 0 && level < N) && (pos >= 0 && pos < N);
}
vector<vector<char>> placeQueen(vector<vector<char>> Grid,int level,int pos){
    for(int row = level+1,col = 1;row<Grid.size();row++){
        Grid[row][pos] = '0';
        if(isSafe(Grid,row,pos+col))
            Grid[row][pos + col] = '0';
        if(isSafe(Grid,row,pos-col))
            Grid[row][pos - col] = '0';
        col ++;
    }
    return Grid;
}
void nQueen(vector<vector<char>> Grid,string queen,vector<string> &QueenPos,int level,int pos){
    if(level == Grid.size()){
        QueenPos.push_back("[" + queen + "]");
    }
    else{
        for(int i=0;i<Grid.size();i++){
            if(Grid[level][i] == '1'){
                nQueen(placeQueen(Grid,level,i),queen + to_string(i+1)+" ",QueenPos,level+1,i);
            }
        }
    }
}
void display(vector<string> Strings){
    for(string x : Strings){
        cout<<x<<' ';
    }
}
