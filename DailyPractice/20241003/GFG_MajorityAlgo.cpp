#include<bits/stdc++.h>
using namespace std;
vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int count1=0,candidate1=-1,count2=0,candidate2=-1;
        
        for(auto e:nums){
            if(e==candidate1){
                count1++;
            }else if(e==candidate2){
                count2++;
            }else if(count1==0){
                candidate1=e;
                count1=1;
            }else if(count2==0){
                candidate2=e;
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        
        count1=0,count2=0;
        for(auto e:nums){
            if(e==candidate1){
                count1++;
            }
            
            if(e==candidate2){
                count2++;
            }
        }
        
        vector<int> sol;
        if(count1>n/3){
            sol.push_back(candidate1);
        }
        
        if(count2>n/3){
            sol.push_back(candidate2);
        }
        if(sol.size()==0){
            sol.push_back(-1);
        }
        
        return sol;
    }