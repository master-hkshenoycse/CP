#include<bits/stdc++.h>
using namespace std;
int cnt_of_div[100005], sum_of_div[100005];
int pre_done=0;
void fill_sum_ofd(){
    if(pre_done){
        return;
    }

    pre_done=1;
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            cnt_of_div[j]++;
            sum_of_div[j]+=i;
        }
    }
}
class Solution {
public:
    
    int sumFourDivisors(vector<int>& nums) {
        fill_sum_ofd();
        int ret=0;   
        for(auto e:nums){
            if(cnt_of_div[e]==4){
                ret=ret+sum_of_div[e];
            }
        }
        return ret;
    }
};