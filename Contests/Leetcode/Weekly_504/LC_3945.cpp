#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int digitFrequencyScore(int n) {
        int sod=0;
        while(n>0){
            sod+=(n%10);
            n/=10;
        }
        return sod;
    }
};