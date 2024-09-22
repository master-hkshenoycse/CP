
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_value(char ch,int op1,int op2){

        if(ch=='+'){
            return op1+op2;
        }

        if(ch=='*'){
            return op1*op2;
        }

        return op1-op2;
    }
    vector<int> evaluate(int st,int en,vector<int> &operands,vector<char> &operators){
        //cout<<st<<" "<<en<<endl;
        if(st==en){
            vector<int> curr;
            curr.push_back(operands[st]);
            
            return curr;
        }

        vector<int> curr;
        
        for(int i=st;i<=en-1;i++){
            
            vector<int> lhs=evaluate(st,i,operands,operators);
            vector<int> rhs=evaluate(i+1,en,operands,operators);

            char op=operators[i];

            for(auto op1:lhs){
                for(auto op2:rhs){
                    curr.push_back(get_value(op,op1,op2));
                }
            }

        }

        return curr;

    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> operands;
        vector<char> operators;
        int val=0;

        for(auto ch:expression){
            if(ch=='+' or ch=='-' or ch=='*'){
                operands.push_back(val);
                val=0;
                operators.push_back(ch);
            }else{
                val=val*10+(ch-'0');
            }
        }

        operands.push_back(val);

        int sz=operands.size();
        return evaluate(0,sz-1,operands,operators);


    }
};