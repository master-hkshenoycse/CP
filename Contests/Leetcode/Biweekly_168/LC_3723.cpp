#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ret;
        while(num>0){

            if(sum>=9){
                ret+='9';
                sum-=9;
            }else{
                ret+=char('0'+sum);
                sum=0;
            }         

            num--;

        }

        if(sum>0){
            ret.clear();
        }

        return ret;
    }
};