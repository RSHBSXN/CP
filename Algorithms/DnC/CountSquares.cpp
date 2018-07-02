/*
 *  using divide and conquer find the number of terms whose squares are just less than number N
 *  make left bound as 0 and right bound as N we split the array into two
 *  find middle by adding indices leftbound and rightbound and dividing it by two.
 *  if square of middle is less than N and square of middle + 1 is greater then N then middle is the total number of terms whose squares are less than N
 *
 *  bounday case:
 *    when N is perfect square (square of an integer) then we check that whether middle * middle is equal to N if yes then we return middle -1
 */
#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull mid(ull left,ull right){
    return (left+right)/2;
}
ull Sq(ull N){
    ull Left = 0;
    ull Right = N;
    ull middle = mid(Left,Right);
    bool isRoot = false;
    while(!isRoot){
        ull midSq = middle * middle;
        ull prevSq = (middle-1) * (middle - 1);
        ull nextSq = (middle + 1) * (middle + 1);
        if(midSq == N){
            isRoot = true;
            middle--;
        }
        else if(midSq < N and nextSq > N){
            isRoot = true;
        }
        else if(midSq < N)
            Left = middle + 1;
        else if(midSq > N)
            Right = middle - 1;
        if(!isRoot)
            middle = mid(Left, Right);
    }
    return middle;
}
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        ull N;
        cin >> N;
        cout<<Sq(N)<<endl;     
    }

}
