
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        
        
        map<string,int> help;
        string curr;
        int ma=0;
        for(int i=0;i<n;i++){
            if(i%k==0 and curr.size()>0){
            
                help[curr]++;
                ma=max(ma,help[curr]);
                curr.clear();
            }
            
            curr+=word[i];
            
        }
        
        if(curr.size()>0){
            help[curr]++;
            ma=max(ma,help[curr]);
        }
 
        return n/k-ma;
        
    }
};