#include<bits/stdc++.h>
using namespace std;
int is_prime[50001];
int is_done = 0;
void sieve(){
    if(is_done){
        return;
    }

    is_done = 1;
    is_prime[1]=1;
    for(int i=2;i<=50000;i++){
        if(is_prime[i]==0){
            for(int j=2*i;j<=50000;j+=i){
                is_prime[j]=1;
            }
        }
    }
}
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n=nums.size(),l=0,ans=0;
        multiset<int> st;
        int fl = -1,sl =-1;
        sieve();

        //fl = first last prime, sl = second last prime

        for(int i=0;i<n;i++){
            if(is_prime[nums[i]]==0){
                st.insert(nums[i]);
                sl=fl;
                fl=i;
            }

            while(st.size()>1 && (*st.rbegin())-(*st.begin()) > k){
                if(is_prime[nums[l]]==0){
                    st.erase(st.find(nums[l]));
                }
                l++;
            }

            if(st.size()>=2){
                ans=ans+(sl-l+1);
            }
        }
        return ans;
    }
};