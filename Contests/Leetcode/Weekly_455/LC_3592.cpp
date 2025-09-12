#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size(); 
        vector<int> curr(n+1,0);
        vector<int> ret;

        curr[0]=1;
        for(int i=1;i<=n;i++){
            
            if(curr[i]+1==numWays[i-1]){
                ret.push_back(i);
                for(int j=i;j<=n;j++){
                    curr[j]+=curr[j-i];
                }
            }else if(curr[i]==numWays[i-1]){
                continue;
            }else{
                ret.clear();
                return ret;
            }
        }

        return ret;

    }
};