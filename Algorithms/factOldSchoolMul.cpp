#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string add(string A,string B){
    string res(A);
    int off = A.length() - B.length();
    int i = B.size()-1;
    int carr = 0;
    int sum = 0;
    while(i + off >= 0){
        int secondOpr = 0;
        if(i >= 0){
            secondOpr = B[i] - '0';
        }
        sum = A[i + off] - '0' + secondOpr + carr;
        carr = sum /10;
        res[i+off] = (sum % 10) + '0';
        i--;
    }
    if(carr != 0)
        res = to_string(carr) + res;
    return res;
}
string sub(string A,string B){
    string res(A);
    int off = A.length() - B.length();
    int i = B.size()-1;
    while(i + off >= 0){
        int numOne = A[i + off] - '0';
        int numTwo = 0;
        if(i >= 0){
            numTwo  = B[i] - '0';
        }
        if(numOne < numTwo){
            int j = i - 1;
            while(A[j + off] == '0'){
                A[j + off] = '9';
                j--;
            }
            A[j + off]--;
            numOne += 10;
        }
        res[i + off] = (numOne - numTwo) + '0';
        i--;
    }
    int startIndex = 0;
    while(res[startIndex] == '0' && startIndex < res.size()-1)
        startIndex++;
    return res.substr(startIndex);
}
string mul(string A,char B){
    string res;
    res = A;
    int second = B - '0';
    int carr = 0;
    int multi = 0;
    for(int i=res.length()-1;i >= 0 ;i--){
        int first = A[i] - '0';
        
        multi = first * second + carr;
        carr = multi / 10;
        res[i] = multi % 10 + '0';
    }
    
    if(carr != 0)
        res = to_string(carr) + res;
    return res;
}
string mul(string A,string B,vector<string>Strings){
    for(int i=B.size()-1;i>=0;i--)
        Strings.push_back(mul(A,B[i]));
    string zeroes;
    string res = Strings[0];
    for(int i=1;i<Strings.size();i++){
        zeroes += "0";  
        res = add(Strings[i] + zeroes,res);
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    string res = "1";
    for(int i=1;i<=n;i++){
        vector<string>M;
        res = mul(res,to_string(i),M); 
    }
    cout<<res;
}
