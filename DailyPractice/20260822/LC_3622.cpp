#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSod(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int prod(int n){
        int ret=1;
        while(n>0){
            ret=(ret * (n%10));
            n/=10;
        }
        return ret;
    }
    bool checkDivisibility(int n) {
        int s=getSod(n);
        int p=prod(n);
        return n%(p+s)==0;
    }
};