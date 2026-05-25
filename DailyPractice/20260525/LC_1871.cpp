#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return 0;
        
        vector<int> z;
        z.push_back(0);
        vector<int>::iterator it1,it2;
        for(int i=1;i<n;i++){
            
           if(s[i]=='1')continue;
           int lo=i-maxJump;
           int hi=i-minJump;
            
        //   cout<<i<<" "<<lo<<" "<<hi<<endl;
        
            
           it1=lower_bound(z.begin(),z.end(),lo);
           
           if(it1==z.end())continue;
            
           it2=upper_bound(z.begin(),z.end(),hi);
           
           if(it2==z.begin())continue;
            
           it2--;
            
           if(it2-it1>=0){
               z.push_back(i);
           }
            
        }
        
        
        return z.back()==n-1;
        
        
        
    }
};