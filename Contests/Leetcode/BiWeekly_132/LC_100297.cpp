#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<pair<int,int> > q;
        int ma=0;
        int n=skills.size();
        for(int i=0;i<n;i++){
            ma=max(ma,skills[i]);
            q.push_back({skills[i],i});
        }
        
        vector<int> cnt(n,0);
        
        while(q.size()>0){
            int first_player=q.front().second;
            q.pop_front();
            int second_player=q.front().second;
            q.pop_front();            

            if(skills[first_player]<skills[second_player]){
                swap(first_player,second_player);   
            }
            
            
            cnt[first_player]++;
            cnt[second_player]=0;
            
            if(cnt[first_player]==k){
                return first_player;
            }
            q.push_front({skills[first_player],first_player});
            q.push_back({skills[second_player],second_player});
            
            if(skills[first_player]==ma){
                return first_player;
            }
            
        }
        
        return -1;
    }
};