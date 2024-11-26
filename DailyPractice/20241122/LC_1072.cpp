#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        map<string,int> help;
        for(int i=0;i<n;i++){
            string tmp;
            for(int j=0;j<m;j++){
                tmp+=char('0'+matrix[i][j]);
            }
            help[tmp]++;
        }
        int ans=0;

        for(auto it:help){
            string tmp;
            int cnt=it.second;
            for(auto ch:it.first){
                if(ch=='1'){
                    tmp+='0';
                }else{
                    tmp+='1';
                }
            }

            if(help.find(tmp) != help.end()){
                cnt+=help[tmp];
            }

            ans=max(ans,cnt);
        }

        return ans;
    }
};