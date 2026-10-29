#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_set(int n){
        if(n==0)
            return 0;
        return 1+get_set(n & (n-1));
    }
    int calculateScore(int a, int b) {
        int s1=get_set(a);
        int s2=get_set(b);
        if(s1>=s2)
            return s1*s2;
        return s2/s1;
    }
};