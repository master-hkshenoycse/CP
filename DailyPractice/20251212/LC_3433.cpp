#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_num(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*10+(ch-'0');
        }
        return ret;
    }
    vector<int> get_ids(string &message_string){
        vector<int> ret;
        
        
      
        int i=0,curr=0,n=message_string.size();
        
        while(i<n){
            if(message_string[i]>='0' and message_string[i]<='9'){
                int j=i;
                while(j<n and message_string[j]>='0' and message_string[j]<='9'){
                    curr=curr*10+(message_string[j]-'0');
                    j++;
                }
                
                ret.push_back(curr);
                i=j;
            }else{
                curr=0;
                i++;
            }
        }
            
       
        
        return ret;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> sol(numberOfUsers,0);

        
        map<int,vector<string> > message_events;
        map<int,vector<int> > offline_events,online_events;
        set<int> uniq_events;
        
        for(auto e:events){
            
            int tm=get_num(e[1]);
            uniq_events.insert(tm);
            if(e[0]=="OFFLINE"){
                offline_events[tm].push_back(get_num(e[2]));
                online_events[tm+60].push_back(get_num(e[2]));
                uniq_events.insert(tm+60);
            }else{
                message_events[tm].push_back(e[2]);
            }
            
        }
        
        set<int> curr_online;
        
        for(int i=0;i<numberOfUsers;i++){
            curr_online.insert(i);
        }
        
        for(auto tm:uniq_events){
            
            if(online_events.find(tm) != online_events.end()){
                for(auto ind:online_events[tm]){
                    
                    curr_online.insert(ind);
                }
            }
            
            if(offline_events.find(tm) != offline_events.end()){
                for(auto ind:offline_events[tm]){
                    curr_online.erase(ind);
                }
            }
            
            if(message_events.find(tm) != message_events.end()){
                for(auto m:message_events[tm]){
                    if(m=="ALL"){
                        for(int i=0;i<numberOfUsers;i++){
                            sol[i]++;
                        }
                    }else if(m=="HERE"){
                        for(auto e:curr_online){
                            cout<<e<<" ";
                            sol[e]++;
                        }
                        cout<<endl;
                    }else{
                        vector<int> r=get_ids(m);
                        for(auto e:r){ 
                            cout<<e<<" ";
                            sol[e]++;
                        }
                        cout<<endl;
                    }
                }
            }
        }
        
        return sol;
        
    }
};