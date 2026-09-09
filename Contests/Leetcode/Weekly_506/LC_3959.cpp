#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkGoodInteger(int n) {
        int dsum=0,sq_dsum=0;

        while(n>0){
            int d=(n%10);
            dsum+=d;
            sq_dsum+=d*d;
            n/=10;
        }   

        return sq_dsum-dsum>=50;
    }
};