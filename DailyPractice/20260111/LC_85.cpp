#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_max_area(vector<int> &h){
        int n=h.size();
        vector<int> next_smaller(n,n),prev_smaller(n,-1);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 and h[st.top()]>=h[i]){
                st.pop();
            }

            if(st.size()>0){
                prev_smaller[i]=st.top();
            }

            st.push(i);
        }

        while(st.size()>0){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 and h[st.top()]>=h[i]){
                st.pop();
            }

            if(st.size()>0){
                next_smaller[i]=st.top();
            }

            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(next_smaller[i]-prev_smaller[i]-1)*h[i]);
        }

        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0){
            return 0;
        }    

        int m=matrix[0].size();
        if(m==0){
            return 0;
        }


        vector<vector<int> > h(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    h[i][j]=0;
                }else{
                    h[i][j]=1;
                    if(i-1>=0){
                        h[i][j]+=h[i-1][j];
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,get_max_area(h[i]));
        }
        return ans;


    }
};