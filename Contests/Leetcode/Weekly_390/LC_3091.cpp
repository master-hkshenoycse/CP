#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minOperations(int k) {
        int ans=k-1;
        for(int i=0;i<=k;i++){
            
            int value=1+i;   
            int extra=(k-value+value-1)/(value);
            ans=min(ans,i+extra);

        }
        return ans;
    }
};