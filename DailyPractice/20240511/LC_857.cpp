#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double lo=1.00,hi=1e9,ans=hi;
        int n=quality.size();
        

        //sort by quality/wage ratio
        vector<vector<double> > q;
        for(int i=0;i<n;i++){
            q.push_back({(quality[i]*1.00)/(wage[i]*1.00),quality[i]*1.00});
        }
        sort(q.begin(),q.end());

        for(int i=0;i<50;i++){
            double mid=(lo+hi)/2.00;
            
            
            double tot_q=0;
            multiset<double>curr_q;
            int f=0;

            //get the sum of set with size k  of least quality 
            //this sum should be less the T<=q*mid/wage
            //q is quality , w is wage
            //it is because for the seleted set the max wage should nor exceed mid
            //mid is the binary search iterator
            //(q/T)*mid>=w
             
            for(int i=n-1;i>=0;i--){
                tot_q+=q[i][1];
                curr_q.insert(q[i][1]);

                if(curr_q.size()>k){
                    tot_q-=*(--curr_q.end());
                    curr_q.erase(--curr_q.end());
                }   
                if(curr_q.size()==k and tot_q <= q[i][0]*mid){
                    f=1;
                    break;
                }
                
            }


            if(f){
                ans=min(ans,mid);
                hi=mid;
            }else{
                lo=mid;
            }
        }

        return ans;
    }
};