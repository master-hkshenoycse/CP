#include<bits/stdc++.h>
using namespace std;
class TaskManager {
public:
    map<int,int> task_helper,task_user;
    set<pair<int,int> > task_order;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t:tasks){
            task_user[t[1]]=t[0];
            task_helper[t[1]]=t[2];
            task_order.insert({t[2],t[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_user[taskId]=userId;
        task_helper[taskId]=priority;
        task_order.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        task_order.erase({task_helper[taskId],taskId});
        task_helper[taskId]=newPriority;
        task_order.insert({task_helper[taskId],taskId});
    }
    
    void rmv(int taskId) {
        task_order.erase({task_helper[taskId],taskId});
        task_helper.erase(taskId);
        task_user.erase(taskId);
    }
    
    int execTop() {
        if(task_order.size()==0){
            return -1;
        }
        int taskId=(*(--task_order.end())).second;
        int ret=task_user[taskId];
        rmv(taskId);
        return ret;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */