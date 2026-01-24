#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_binary(int num){
        vector<int> ret;
        while(num>0){
            ret.push_back(num%2);
            num/=2;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }

    int get_val(vector<int> &b){
        int ret=0;
        for(auto e:b){
            ret=ret*2+e;
        }
        return ret;
    }
    
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> sol;
        for(auto e:nums){
            if(e==2){
                sol.push_back(-1);
            }else{
                vector<int> r=get_binary(e);
                int sz=r.size();
                for(int i=sz-1;i>=0;i--){
                    if(i==0 or r[i-1]==0){
                        r[i]=0;
                        for(int j=i+1;j<sz;j++){
                            r[j]=1;
                        }

                        break;
                    }
                }
                sol.push_back(get_val(r));
            }
        }

        return sol;
    }
};