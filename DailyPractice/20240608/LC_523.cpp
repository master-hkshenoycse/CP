#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cs=0,n=nums.size();
        map<int,int> help;
        help[0]=0;
        
        for(int i=1;i<=n;i++){
            cs=cs+nums[i-1]%k;
            cs%=k;
            
            //cout<<i<<" "<<cs<<endl;
            
            if(help.find(cs) == help.end()){
                help[cs]=i;
            }else{
                if(i-help[cs]>1){
                    return 1;
                }
            }
        }
        
        return 0;
    }
};