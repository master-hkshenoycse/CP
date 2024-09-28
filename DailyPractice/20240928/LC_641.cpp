#include<bits/stdc++.h>
using namespace std;
class MyCircularDeque {
public:
    vector<int> dequeStore;
    int st=-1,en=-1,k;
    MyCircularDeque(int k) {
        this->k=k;
        dequeStore.resize(k);
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return 0;
        }

        if(st==-1){
            st=0;
            en=0;
        }else{
            st=(st-1)%k;
            st=(st+k)%k;
        }

        dequeStore[st]=value;
        return 1;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return 0;
        }

        if(st==-1){
            st=0;
            en=0;
        }else{
            en=(en+1)%k;
        }

        dequeStore[en]=value;
        return 1;
    }
    
    bool deleteFront() {
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
    
    bool deleteLast() {
        if(isEmpty()){
            return 0;
        }

        en=(en-1+k)%k;

        if((en+1)%k==st){
            st=-1;
            en=-1;
        }

        return 1;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dequeStore[st];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dequeStore[en];
    }
    
    bool isEmpty() {
        return st==-1;
    }
    
    bool isFull() {
        return (en+1)%k==st;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */