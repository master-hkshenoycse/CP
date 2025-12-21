#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size(),ans=0;
        
        for(int j=0;j<m;j++){
            int f=1;
            for(int i=1;i<n;i++){
                if(strs[i][j] < strs[i-1][j]){
                    f=0;
                    break;
                }
            }
            if(f==0){
                ans++;
            }
        }

        return ans;
    }
};