#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        int lim=(1<<n);
        vector<string> res;

        for(int i=0;i<lim;i++){
            string ret;
            int cost=0;
            for(int j=0;j<n;j++)
                if(i & (1<<j))
                    ret+='1',cost+=j;
                else 
                    ret+='0';
            
            if(cost>k)
                continue;
            
            for(int i=1;i<n;i++){
                if(ret[i] == '1' && ret[i-1]=='1'){
                    cost=k+1;
                    break;
                }
            }

            if(cost<=k)
                res.push_back(ret);
        }

        return res;
    }
};