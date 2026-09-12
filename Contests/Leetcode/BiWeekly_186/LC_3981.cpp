#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[102][102][102][4];
    int mod=1e9+7;
    
    int solve(int x,int y,int z, int mask,string &w1,string &w2,string &t){
          if (z == t.size())
            return mask == 3;

        int &ret = dp[x][y][z][mask];

        if (ret != -1)
            return ret;

        ret = 0;

        for (int i = x; i < w1.size(); i++) {
            if (w1[i] == t[z]) {
                ret = (ret + solve(
                    i + 1, y, z + 1, mask | 1,
                    w1, w2, t
                )) % mod;
            }
        }

        for (int j = y; j < w2.size(); j++) {
            if (w2[j] == t[z]) {
                ret = (ret + solve(
                    x, j + 1, z + 1, mask | 2,
                    w1, w2, t
                )) % mod;
            }
        }

        return ret;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0,word1,word2,target);
    }
};