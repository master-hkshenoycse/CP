#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),ans=0,uniq=0,j=0;
        map<int,int> help;

        for(int i=0;i<n;i++){
            help[fruits[i]]++;
            if(help[fruits[i]]==1){
                uniq++;
            }

            while(uniq>2){
                help[fruits[j]]--;
                if(help[fruits[j]]==0){
                    uniq--;
                }
                j++;
            }
            

            ans=max(ans,i-j+1);
        }
        return ans;





        
    }
};