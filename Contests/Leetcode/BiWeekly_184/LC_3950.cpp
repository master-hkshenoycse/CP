#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt=0;
        for(int i=31;i>=0;i--){
            if(n & (1ll<<i)){
                if(i-1>=0){
                    if(n&(1ll<<(i-1)))
                        cnt++;
                }
            }
        }

        return cnt==1;
    }
};