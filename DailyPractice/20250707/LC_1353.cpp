#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) {
            multiset<int> rem_events;
            map<int,vector<int> > event_;
            int ans =0; 
    
            for(auto e:events){
                event_[e[0]].push_back(e[1]);
            }
    
            for(int i=1;i<=100000;i++){
                if(event_.find(i) != event_.end()){
                    for(auto it:event_[i]){
                        rem_events.insert(it);
                    }
                }
    
                while(rem_events.size()>0){
                    if( (*rem_events.begin()) < i){
                        rem_events.erase(rem_events.begin());
                    }else{
                        break;
                    }
                }
    
                if(rem_events.size()>0){
                    ans++;
                    rem_events.erase(rem_events.begin());
                }
    
            }
    
            return ans;
    
    
        }
    };