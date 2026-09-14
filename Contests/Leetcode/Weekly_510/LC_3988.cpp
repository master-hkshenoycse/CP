#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string>ans(m,string(n,'.'));
        if(n==1||m==1){
            if(k==1)return ans;
            else return {};
        }
        if(k==1){
            for(int i=1;i<m;i++){
                for(int j=0;j<n-1;j++){
                    ans[i][j]='#';
                }
            }
        }else if(k==2){
            for(int i=1;i<m;i++){
                for(int j=0;j<n-1;j++){
                    if(i==1&&j==n-2)continue;
                    ans[i][j]='#';
                }
            }
        }else if(k==3){
            if(n>=3){
                for(int i=1;i<m;i++){
                    for(int j=0;j<n-1;j++){
                        if(i==1&&j==n-2)continue;
                        if(i==1&&j==n-3)continue;
                        ans[i][j]='#';
                    }
                }
            }else if(m>=3){
                for(int i=3;i<m;i++){
                    for(int j=0;j<n-1;j++){
                        ans[i][j]='#';
                    }
                }
            }else return{};
        }else {
            if(m<3&&n<3)return {};
            if(m==3&&n==3){
                ans[0][2]='#';
                ans[2][0]='#';
                return ans;
            }
            if(n>=4){
                for(int i=1;i<m;i++){
                    for(int j=0;j<n-1;j++){
                        if(i==1&&j==n-2)continue;
                        if(i==1&&j==n-3)continue;
                        if(i==1&&j==n-4)continue;
                        ans[i][j]='#';
                    }
                }
            }else if(m>=4){
                for(int i=1;i<m;i++){
                    for(int j=0;j<n-1;j++){
                        if(i==1&&j==n-2)continue;
                        if(i==2&&j==n-2)continue;
                        if(i==3&&j==n-2)continue;
                        ans[i][j]='#';
                    }
                }
            }else return{};
        }return ans;
    }
};