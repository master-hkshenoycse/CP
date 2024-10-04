#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> currStack,incStack;
    int ind=0;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        currStack.resize(maxSize+5,0);
        incStack.resize(maxSize+5,0);
        ind=0;
    }
    
    void push(int x) {

        if(ind==maxSize){
            return;
        }
        ind++;
        currStack[ind]=x;
        incStack[ind]=0;
    }
    
    int pop() {
        if(ind==0){
            return -1;
        }

        int val=currStack[ind];
        int inc=incStack[ind];
    

        if(ind-1>0){
            incStack[ind-1]+=inc;
        }

        incStack[ind]=0;
        ind--;

        return val+inc;
    }
    
    void increment(int k, int val) {
        int upd=min(k,ind);
        incStack[upd]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */