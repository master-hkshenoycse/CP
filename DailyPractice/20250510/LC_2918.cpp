#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1=0,s2=0,c1=0,c2=0;
        for(auto e:nums1){
            s1+=e;
            c1+=(e==0);
        }
        
        for(auto e:nums2){
            s2+=e;
            c2+=(e==0);
        }
        
        if(c1==0){
            if(c2>0){
                if(s1<s2+c2){
                    return -1;
                }
                return s1;
            }else{
                if(s1!=s2){
                    return -1;
                }else{
                    return s1;
                }
            }
        }
        
        if(c2==0){
            
            if(c1>0){
                if(s2<s1+c1){
                    return -1;
                }
                return s2;
            }else{
                return -1;
            }
        }
        
        if(s1>s2){
            swap(s1,s2);
            swap(c1,c2);
        }
        
        return max(s1+c1,s2+c2);
        

    }
};