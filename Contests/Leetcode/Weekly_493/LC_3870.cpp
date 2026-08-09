#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCommas(int n) {
        int ans=0,val=1000;
        while(n>0){
            int rem=(n%1000);
            int qu=(n/1000);
            if(qu>=1)ans=ans+(qu-1)*1000+1+rem;
            n/=1000;
        }
        return ans;
    }
};