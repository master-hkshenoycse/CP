#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int j=0;
        vector<int> cons;
        for(int i=1;i<n;i++){
            cons.push_back(i);
        }
    
        int ans=0;
        while(j<strs[0].size()){
            
            if(cons.size()==0){
                break;
            }

            int f=0;
            for(int i=0;i<cons.size();i++){
                if(strs[cons[i]][j]<strs[cons[i]-1][j]){
                    f=1;
                    break;
                }
            }


            if(f){
                ans++;
            }else{
                vector<int> next_cons;
                for(int i=0;i<cons.size();i++){
                    if(strs[cons[i]][j]==strs[cons[i]-1][j]){
                        next_cons.push_back(cons[i]);
                    }
                }

                cons=next_cons;
            }

            j++;
        }

        return ans;
    }
};