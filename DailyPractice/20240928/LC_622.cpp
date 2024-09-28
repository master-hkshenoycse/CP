#include<bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    vector<int> queueStore;
    int k,st=-1,en=-1;
    MyCircularQueue(int k) {
        queueStore.resize(k);
        this->k=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return 0;
        }

        if(st==-1 and en==-1){
            st=0;
            en=0;
        }else{
            en=(en+1)%k;
        }

        queueStore[en]=value;
        return 1;
    
    }
    
    bool deQueue() {
        if(isEmpty()){
            return 0;
        }

        st=(st+1)%k;
        

        if((en+1)%k==st){
            st=-1;
            en=-1;
        }

        return 1;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }

        return queueStore[st];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }

        return queueStore[en];
    }
    
    bool isEmpty() {
        return st == -1;
    }
    
    bool isFull() {
        return (en+1)%k==st;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */