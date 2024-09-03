#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long s=0;
        int n=chalk.size();
        
        for(int i=0;i<n;i++)s+=chalk[i];
        
        if(k%s==0){
            return 0;
        }
        
        k%=s;
        
        for(int i=0;i<n;i++){
            if(k<chalk[i]){
                return i;
            }
            k-=chalk[i];
        }
        
        return -1;
    }
};