#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n=blocks.size(),ans=k;
            
            for(int i=0;i+k-1<n;i++){
                int s=0;
                for(int j=0;j<k;j++){
                    s=s+(blocks[i+j]=='W');
                }
                ans=min(ans,s);
            }
            return ans;
        }
    };