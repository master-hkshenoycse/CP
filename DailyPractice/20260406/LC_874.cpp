#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int d=0,x=0,y=0,ans=0;
        set<pair<int,int> > obs;
        for(auto o:obstacles){
            obs.insert({o[0],o[1]});
        }
        for(auto c:commands){

            if(c==-1){
                d=(d+1)%4;
            }else if(c==-2){
                d=(d-1+4)%4;
            }else{
                int k=c;
                while(k--){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(obs.find({nx,ny})==obs.end()){
                        x=nx;
                        y=ny;
                        ans=max(ans,x*x+y*y);
                    }else{
                        break;
                    }
                }
            }
           
        }

        return ans;
    }
};