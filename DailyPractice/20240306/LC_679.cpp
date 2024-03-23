#include<bits/stdc++.h>
using namespace std;
/* Recursion over all permutations of numbers ,based solution combine all possible partitions like matrix chain dp style*/

class Solution {
public:
    vector<double> nums;
    char ops[4]={'+','-','*','/'};
    const double eps=1e-9;
    bool found=0;
    double calc(double x,double y,char op){
        if(op=='+')return x+y;
        if(op=='-')return x-y;
        if(op=='*')return x*y;
        return x/y;
    }

    vector<double> getEvaluation(int l,int r){

        if(found){
            return {};
        }

        if(l==r){
            return {nums[l]};
        }
        vector<double> ret;

        for(int i=l;i<r;i++){
            auto resL=getEvaluation(l,i);
            auto resR=getEvaluation(i+1,r);

            //get all possible values by puttig operatios between them

            for(auto x:resL){
                for(auto y:resR){
                    for(char op:ops){

                        if(op=='/' and y==0){
                            continue;
                        }

                        ret.push_back(calc(x,y,op));

                        if(l==0 and r==3){
                            //cout<<x<<" "<<y<<" "<<ret.back()<<endl;
                            if(abs(ret.back()-24.0)<eps){
                                found=1;
                                return {};
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    bool judgePoint24(vector<int>& cards) {

        for(auto x:cards){
            nums.push_back(x*1.00);
        }

        sort(nums.begin(),nums.end());

        do{
            found=0;

            getEvaluation(0,3);

            if(found){
                return 1;
            }

        }while(next_permutation(nums.begin(),nums.end()));
        
        return 0;
    }
};