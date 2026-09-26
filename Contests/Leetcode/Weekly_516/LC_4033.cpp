#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int bl_size=sqrt(n);
        int cnt_blocks=(n+bl_size-1)/bl_size;
        int q=queries.size();

        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);

        sort(queries.begin(),queries.end(),[&](vector<int> &a,vector<int> &b){
            return make_pair(a[0]/bl_size,a[1])<make_pair(b[0]/bl_size,b[1]);
        });

        vector<int> help(1e5+5,0);
        int uniq=0,odd_freq=0;
        int j=0,l=0,r=-1;
        vector<bool> ret(q);


        for(int i=0;i<cnt_blocks;i++){
            int en=min(n-1,(i+1)*bl_size-1);
            
            while(j<q && queries[j][0]<=en){
                
                int l_req=queries[j][0];
                int r_req=queries[j][1];
                int q_ind=queries[j][2];

                while(r>r_req){
                    int val=nums[r];
                    if(help[val]%2)
                        odd_freq--;
                    else
                        odd_freq++;
                    help[val]--;
                    if(help[val]==0)
                        uniq--;
                    r--;
                }

                while(r<r_req){
                    r++;
                    int val=nums[r];
                    help[val]++;
                    if(help[val]==1)
                        uniq++;
                    if(help[val]%2==0)
                        odd_freq--;
                    else
                        odd_freq++;
                    
                }

                while(l>l_req){
                    l--;
                    int val=nums[l];
                    if(help[val]%2)
                        odd_freq--;
                    else 
                        odd_freq++;
                    help[val]++;
                    if(help[val]==1)
                        uniq++;
                }

                while(l<l_req){
                    int val=nums[l];
                    if(help[val]%2)
                        odd_freq--;
                    else
                        odd_freq++;
                    help[val]--;
                    if(help[val]==0)
                        uniq--;
                    l++;
                }

                ret[q_ind]=(uniq==k) && (odd_freq==0);
                j++;
            }
        }

        return ret;


    }
};