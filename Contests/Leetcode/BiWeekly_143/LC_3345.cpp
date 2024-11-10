#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int is_div(int n,int t){
        int prod=1;
        while(n>0){
            prod=(prod * (n%10))%t;
            n/=10;
        }
        return prod==0;
    }
    int smallestNumber(int n, int t) {
        while(n){
            if(is_div(n,t)){
                return n;
            }
            n++;
        }
        return -1;
    }
};