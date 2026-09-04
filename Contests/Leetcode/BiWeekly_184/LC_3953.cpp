#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > prime_facs;
    int precum_done=0;
    void pre_cum(){
        if(precum_done)
            return ;
        precum_done=1;
        prime_facs.resize(100001,vector<int> ());
        precum_done=1;
        vector<int> isp(100001,0);
        for(int i=2;i<=100000;i++){
            if(isp[i]==0){
                for(int j=i;j<=100000;j+=i)
                    isp[j]=1,prime_facs[j].push_back(i);
            }
        }
    }
class Solution {
public:
    
    int maxScore(vector<int>& nums, int maxVal) {
        int n=nums.size();
        pre_cum();
        
        map<int,int> freq;
        int av=0;
        for(auto e:nums)
            av=max(av,e),freq[e]++;
        av=max(av,maxVal);
        
        map<int,int> red_prime_fact;
        for(auto it:freq){
            int val=it.first;
            int sz=prime_facs[val].size();
            int lim=(1<<sz);
            int tot_cnt=0;
            for(int j=1;j<lim;j++){
                int red_fact=1;
                for(int p=0;p<sz;p++){
                    if(j & (1<<p))
                        red_fact=(red_fact * prime_facs[val][p]);
                }
                red_prime_fact[red_fact]+=it.second;
            }
        }

        int ans=INT_MIN;

        if(freq[1]>0)
            ans=1;
        for(int i=2;i<=av;i++){
            int sz=prime_facs[i].size();
            int lim=(1<<sz);
            int tot_cnt=0;

            if(freq[i]==0 && i>maxVal)
                continue;
 
            for(int j=1;j<lim;j++){
                int red_cnt=0,red_fact=1;
                for(int p=0;p<sz;p++){
                    if(j & (1<<p))
                        red_cnt++,red_fact=(red_fact * prime_facs[i][p]);
                }
                if(red_cnt%2){
                    tot_cnt+=red_prime_fact[red_fact];
                }else{
                    tot_cnt-=red_prime_fact[red_fact];
                }
            }

            
            tot_cnt-=(freq[i]>0);
            int mod_cost=tot_cnt;

            if(freq[i]==0 && mod_cost==0)
                mod_cost++;
            



            ans=max(ans,i-mod_cost);
        }

        return ans;

    }
};