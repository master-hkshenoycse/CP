#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll cnt_zero=0,cnt_neg=0,min_pos=1e18,min_neg=1e18,sum=0,n=matrix.size(),m=matrix[0].size();
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                sum=sum+abs(matrix[i][j]);
                if(matrix[i][j]<=0){
                    cnt_neg++;
                    min_neg=min(min_neg,abs(matrix[i][j])*1ll);
                }else{
                    min_pos=min(min_pos,matrix[i][j]*1ll);
                }                
            }
        }

        if(cnt_neg%2){
            sum=sum-min(2*min_neg,2*min_pos);
        }

        return sum;
    }
};