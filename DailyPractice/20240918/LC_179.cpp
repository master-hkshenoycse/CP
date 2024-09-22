
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp (string &a,string &b){
            return a+b>b+a;
        }
       
    string largestNumber(vector<int>& nums) {
        vector<string> grp;
        int n=nums.size();
        
        int f=0;
        
        for(int i=0;i<n;i++) {            
            string s=to_string(nums[i]);
            grp.push_back(s);
            f+=(nums[i]>0);
        }
        if(!f){
            string sol;
            sol="0";
            return sol;
        }
            

        sort(grp.begin(),grp.end(),comp);
        //reverse(grp.begin(),grp.end());
        string sol;
        for(int i=0;i<n;i++)sol+=grp[i];
       
        return sol;
    }
};