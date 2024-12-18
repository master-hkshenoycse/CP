#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_z(int start,vector<int> &nums){
        vector<int> a;

        for(int i=start;i<nums.size();i++){
            a.push_back(nums[i]);
        }

        int n=a.size();
        vector<int> z(n,0);
        int left=0,right=0;

        for(int i=1;i<n;i++){
            if(i>right){
                left=i;
                right=i;
                while(right<n and a[right]==a[right-left]){
                    right++;
                }
                z[i]=right-left;
                right--;
            }else{
                int j=i-left;
                if(z[j]<right-i+1){
                    z[i]=z[j];
                }else{
                    left=i;
                    while(right<n and a[right]==a[right-left]){
                        right++;
                    }
                    z[i]=right-left;
                    right--;
                }
            }
        }

        return z;

    }
    int beautifulSplits(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > z(n);

        for(int i=0;i<n;i++){
            z[i]=get_z(i,nums);
        }    

        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len_1=i;
                int len_2=j-i;
                if((z[0][i]>=len_1 and j-i>=len_1) || z[i][j-i]>=len_2){
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }

        return ans;

    }
};