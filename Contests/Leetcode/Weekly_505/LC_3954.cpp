#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        
        int ans=0;
        for(int i=-k;i<=k;i++){
            if(n+i>0 && (n&(n+i))==0)
                ans=ans+n+i;
        }   
        return ans;
    }
};