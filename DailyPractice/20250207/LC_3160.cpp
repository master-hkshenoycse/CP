#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> help;
        map<int,int> cnt_color;
        
        int ans=0;
        vector<int> sol;
        for(auto q:queries){
            int x=q[0];
            int y=q[1];
            
            if(help.find(x) == help.end()){
                help[x]=y;
                cnt_color[y]++;
            }else{
                cnt_color[help[x]]--;
                if(cnt_color[help[x]]==0){
                    cnt_color.erase(help[x]);
                }
                
                help[x]=y;
                cnt_color[y]++;
                
            }
            sol.push_back(cnt_color.size());
        }
        
        return sol;
    }
};