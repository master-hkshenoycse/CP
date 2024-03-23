#include<bits/stdc++.h>
using namespace std;
/*https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1*/

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int ans=0,n=price.size();
            vector<int> suff_profit(n,0);
            int max_price=0,min_price=INT_MAX;
            for(int i=n-1;i>=0;i--){
                
                suff_profit[i]=max(suff_profit[i],max_price-price[i]);
                if(i+1<n){
                    suff_profit[i]=max(suff_profit[i],suff_profit[i+1]);
                }
                
                max_price=max(max_price,price[i]);
                ans=max(ans,suff_profit[i]);
                //cout<<i<<" "<<suff_profit[i]<<endl;
            }
            
            for(int i=0;i<n;i++){
                if(i>0){
                    int p_curr=max(0,price[i]-min_price);
                    if(i+1<n){
                        p_curr+=suff_profit[i+1];
                    }
                    ans=max(ans,p_curr);
                }
                min_price=min(min_price,price[i]);
            }
            
            return ans;
            
            
            
        }
};