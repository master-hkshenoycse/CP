#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int> &A,int s){
        int i=0,j=0,count=0,sum=0;
        int n=A.size();

        if(s<0){
            return 0;
        }

        while(j<n){
            sum+=A[j];
            while(sum>s){
                sum-=A[i];
                i++;
            }

            count=count+(j-i+1);
            j++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};