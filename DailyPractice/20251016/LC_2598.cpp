#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt[200005];
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        map<int,int> help;
        for(int i=0;i<n;i++){
            int y=nums[i]%value;
            if(y<0){
               y+=value; 
            }
            help[y]++;
        }
        
        for(int i=0;i<value;i++){
            for(int j=i;j<=200000;j+=value){
                if(help[i]==0){
                    break;
                }
                cnt[j]++;
                help[i]--;
            }
        }
        
        for(int i=0;i<=200000;i++){
            if(cnt[i]==0){
                return i;
            }
        }
        return -1;
    }
};