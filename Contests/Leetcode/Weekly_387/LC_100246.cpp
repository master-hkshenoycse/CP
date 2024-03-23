#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    
    void upd(int ind,int val,vector<int> &b,int n){
        while(ind<=n){
            b[ind]+=val;
            ind+=(ind & (-ind));
        }
    }
    
    int query(int ind,vector<int> &b){
        int res=0;
        while(ind>0){
            res=res+b[ind];
            ind-=(ind & (-ind));
        }
        return res;
    }
    vector<int> resultArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> b1(n*2+5,0),b2(n*2+5,0);
        
        map<int,int> help;
        map<int,int> :: iterator it;
        for(int i=0;i<n;i++){
            help[nums[i]]++;
        }
        
        int c=0;
        for(it=help.begin();it!=help.end();it++){
            c++;
            it->second=c;
        }
        
        vector<int> a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        
        upd(help[nums[0]],1,b1,2*n);
        upd(help[nums[1]],1,b2,2*n);
        
        int i=2;
        
        
        while(i<n){
            int val=help[nums[i]];
            
            int c_gt_1=(a1.size()*1)-query(val,b1);
            int c_gt_2=(a2.size()*1)-query(val,b2);
            
            if(c_gt_1>c_gt_2){
                a1.push_back(nums[i]);
                upd(val,1,b1,n);
            }else if(c_gt_1<c_gt_2){
                a2.push_back(nums[i]);
                upd(val,1,b2,n);
            }else if(a1.size()<=a2.size()){
                a1.push_back(nums[i]);
                upd(val,1,b1,n);
            }else{
                a2.push_back(nums[i]);
                upd(val,1,b2,n);
            }
            
            i++;
            
        }
        
        for(auto e:a2){
            a1.push_back(e);
        }
        
        return a1;
        
        
    }
};