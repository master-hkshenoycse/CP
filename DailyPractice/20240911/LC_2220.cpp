#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=0;i<=30;i++){
            int a=(start & (1<<i));
            int b=(goal & (1<<i));
            if(a != b){
                ans++;
            }
        }
        return ans;
    }
};