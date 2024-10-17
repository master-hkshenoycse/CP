#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int> sol(n,-1);
        map<int,vector<pair<int,int> > > help;
        set<int> chairs;
        for(int i=0;i<n;i++){
            int st=times[i][0];
            int en=times[i][1];
            
            help[st].push_back({1,i});
            help[en].push_back({-1,i});
            chairs.insert(i);
        }
        
        map<int,vector<pair<int,int> > >::iterator it;
        
        for(it=help.begin();it != help.end();it++){
            sort(it->second.begin(),it->second.end());
            int sz=it->second.size();
            for(int i=0;i<sz;i++){
                
                if(it->second[i].first==-1){
                    chairs.insert(sol[it->second[i].second]);
                }else{
                    int c=*chairs.begin();
                    sol[it->second[i].second]=c;
                    chairs.erase(c);
                }
                
            }
        }
        
    
        return sol[targetFriend];
    }
};