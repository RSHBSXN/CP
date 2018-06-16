#include <bitset> //bitset class helps to convert any number to bits, which will help to find subsets of a given collection.
#include <vector> // vector class is used to create dyanamic arrays
#include <string> // C++ string
#include <cmath>  // to use pow function which is used to find maximum subsets of given collection
/*
    PowerSet("abc") will return "a b ab c ac bc abc"
*/

string PowerSet(string str){
    bitset<16>toBits;
    int size = pow(2,str.size());
    vector<string>Strs(size-1);
    for(int i=1;i<size;i++){
        toBits = i;
        Strs[i-1] = "";
        for(int ind = 0;ind < str.size();ind++){
            if(toBits[ind] == 1){
                Strs[i-1] += str[ind];
            }
        }
    }
    string result;
    for(int i=0;i<Strs.size();i++){
        result += Strs[i];
        if(i != Strs.size()-1)
            result += " ";
    }
    return result;
}
