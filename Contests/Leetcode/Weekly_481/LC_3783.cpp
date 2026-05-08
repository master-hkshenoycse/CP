#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,start=n;
        while(start>0){
            rev=rev*10+(start%10);
            start/=10;
        }

        return abs(rev-n);
    }
};