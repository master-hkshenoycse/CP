class Solution {
public:
    
    int segtree[1000005];
    void upd(int ind,int l,int r,int p,int val){
        if(l>r){
            return;
        }
        
        if(l==r){
            segtree[ind]=val;
            return;
        }
        
        int mid=(l+r)/2;
        if(p<=mid){
            upd(ind*2,l,mid,p,val);
        }else{
            upd(ind*2+1,mid+1,r,p,val);
        }
        
        segtree[ind]=min(segtree[ind*2],segtree[ind*2+1]);
    }
    
    int query(int ind,int l,int r,int st,int en){
        if(l>r or r<st or l>en){
            return 1e9;
        }
        
        if(l>=st and r<=en){
            return segtree[ind];
        }
        
        int mid=(l+r)/2;
        return min(query(ind*2,l,mid,st,en),query(ind*2+1,mid+1,r,st,en));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> sol;
        
        int q_size=queries.size();
        int lim=min(50000,3*q_size);
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(lim);
        unordered_map<int,set<int> > avail;
        set<int>::iterator it;
        
        for(int i=1;i<=lim;i++){
        
            upd(1,1,lim,i,1e9);
            
            if(i==lim){
                avail[i].insert(0);
                upd(1,1,lim,i,0);
            }
        }
            
        
        
        
        for(auto q:queries){
            
            if(q[0]==1){
                int ob=q[1];
                it=obstacles.lower_bound(ob);
                int en=*it;
                it--;
                int st=*it;
                
                 
                
                obstacles.insert(ob);
                
                avail[en-st].erase(st);
                
                if(avail[en-st].size()==0){
                    upd(1,1,lim,en-st,1e9);
                }else{
                    upd(1,1,lim,en-st,*avail[en-st].begin());
                }
                
                
                avail[ob-st].insert(st);
                avail[en-ob].insert(ob);
                
                
                upd(1,1,lim,ob-st,*avail[ob-st].begin());
                upd(1,1,lim,en-ob,*avail[en-ob].begin());
                
            
                
            }else{
                
                int sz=q[2];
                int x=q[1];
            
                int avail=query(1,1,lim,sz,lim);
                if(avail+sz<=x){
                    sol.push_back(true);
                }else{
                    sol.push_back(false);
                }
            
            }
        }
        
        
        return sol;
    }
};