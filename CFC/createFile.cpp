#include <bits/stdc++.h>
using namespace std;
int main(int argc,char **args){
    fstream fin("fileCount.txt",ios::in);
    int count = 0;
    fin >> count;
    string fileName = to_string(count) + string(args[1]) + ".cpp";
    fin.close();
    fin.open("fileCount.txt",ios::out);
    count++;
    fin << count;
    fin.close();
    fin.open("template.txt",ios::in);
    fstream fout(fileName,ios::out);
    string scan;
    while(getline(fin,scan)){
        fout << scan + "\n";
    }
    fout.close();
    fileName = "code " + fileName;
    system(fileName.c_str());
}
