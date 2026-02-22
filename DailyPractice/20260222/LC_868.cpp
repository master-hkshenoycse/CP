#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int prev=-1,ans=0,curr=0;

        while(n>0){
            curr++;
            if(n%2){
                if(prev!=-1){
                    ans=max(ans,curr-prev);
                }
                prev=curr;
            }
            n/=2;
        }
        return ans;
    }
};