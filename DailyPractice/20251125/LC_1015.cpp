#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n;
        int l=1;
        int cd=1;
        
       // if(K%2==0) return -1;
        map<int,int> help;
        while(1){
            
            if(cd%k==0){
                return l;
            }
            help[cd]=1;
            cd=(cd*10+1)%k;
            l++;
            
            if(help[cd]){
                return -1;
            }
        }
        
        
        return -1;
    }
};