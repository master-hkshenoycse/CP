#include<bits/stdc++.h>
#define ll long
using namespace std;

#define ll long long
class Solution {
public:
    ll mod=1e9+7;

    void clear_stack(stack<ll> &st){
        while(st.size()>0){
            st.pop();
        }
    }
    int totalStrength(vector<int>& strength) {
        ll n=strength.size();

        vector<ll> c_csum(n+2,0),csum(n+2,0),nx_gt(n+1,-1),prev_gt(n+1,-1);
        /*handle duplicates*/

        /*https://leetcode.com/problems/sum-of-total-strength-of-wizards/solutions/2062017/c-prefix-monotonic-stack-o-n-solution-with-thought-process*/
        for(ll i=0;i<n;i++){
            csum[i+1]=(csum[i]+strength[i]*1ll)%mod;
        }

        for(ll i=0;i<=n;i++){
            c_csum[i+1]=(c_csum[i]+csum[i])%mod;

            nx_gt[i]=n+1;
            prev_gt[i]=0;
        }

        stack<ll> st;
        for(ll i=1;i<=n;i++){
            while(st.size()>0 and strength[st.top()-1]>strength[i-1]){
                st.pop();
            }

            if(st.size()>0){
                prev_gt[i]=st.top();
            }
            
            st.push(i);
        }

        clear_stack(st);

        for(ll i=n;i>=1;i--){

            while(st.size()>0 and strength[st.top()-1] >= strength[i-1]){
                st.pop();
            }

            if(st.size()>0){
                nx_gt[i]=st.top();   
            }

            st.push(i);

        }

        ll ans=0;

        for(ll i=1;i<=n;i++){
            //formula where index i is the smallest
            //(p,q) where p<=i and q>=i ,(csum[q]-csum[p-1])*strngth[i]
            //check contribution of each index
            //that is how many subarray and what sums will this index be minimum

            
            ll cnt_index_prev=i-prev_gt[i];
            ll cnt_index_next=nx_gt[i]-i;

            cout<<cnt_index_prev<<" "<<cnt_index_next<<endl;

            //sum of starting indexes
            //csum(prev_gt[i])+csum(prev_gt[i]+1)+csum(prev_gt[i]+2),i-1

            ll sum_prev=c_csum[i];
            sum_prev-=c_csum[prev_gt[i]];
            sum_prev=(sum_prev+mod)%mod;

            //multiplying by cnt_index_next as for each index in prev there are cnt_index_next indexes on next
            sum_prev=(sum_prev*cnt_index_next)%mod;

            //sum of ending indexes
            //csum(i)+csum(i+1)+csum(nx_gt[i]-1);
            ll sum_nx=c_csum[nx_gt[i]];
            sum_nx-=c_csum[i];

            sum_nx=(sum_nx+mod)%mod;

            //multiplying by cnt_index_prev as for each index in next there are cnt_index_prev indexes on prev
            sum_nx=(sum_nx * cnt_index_prev)%mod;

            ll val=(sum_nx-sum_prev+mod)%mod;
            val=(val * strength[i-1])%mod;

            ans=(ans+ val)%mod;

        }

        return ans;
        
    }
};