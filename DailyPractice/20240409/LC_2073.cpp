#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0,t=0,n=tickets.size();
        
        
        while(1){
            
        
            
        
            t+=(tickets[i]>0);
            tickets[i]--;
           //cout<<i<<" "<<tickets[i]<<endl;
            
            if(tickets[i]==0 and i==k){
                return t;
            }
            
            i=(i+1)%n;
            
        }
        return -1;
        
    }
};