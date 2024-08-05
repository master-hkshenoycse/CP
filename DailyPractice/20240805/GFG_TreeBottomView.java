import java.util.*;

class Node{
    int data;
    Node left,right;

    Node (int data){
        this.data=data;
        this.left=null;
        this.right=null;

    }
}

class BFSNode{
    int align;
    Node curr;
    
    BFSNode(int align,Node curr){
        this.align=align;
        this.curr=curr;
    }
    
};
public class GFG_TreeBottomView
{   
    
    
    
    //Function to return a list containing the bottom view of the given tree.
    public ArrayList <Integer> bottomView(Node root){
        // Code here
        Queue<BFSNode> q=new LinkedList<>();
        Map<Integer,Integer> viewMap=new TreeMap<Integer,Integer> ();
        
        q.add(new BFSNode(0,root));
        
        while(q.size() > 0){
            
            BFSNode tmp=q.remove();
            
            if(viewMap.containsKey(tmp.align)==false){
                viewMap.put(tmp.align,-1);
            }
            
            viewMap.put(tmp.align,tmp.curr.data);
            
            if(tmp.curr.left != null){
                q.add(new BFSNode(tmp.align-1,tmp.curr.left));
            }
            
            if(tmp.curr.right != null){
                q.add(new BFSNode(tmp.align+1,tmp.curr.right));
            }
        }
        
        ArrayList<Integer> sol=new ArrayList<>();
        
        for(Integer key:viewMap.keySet()){
            sol.add(viewMap.get(key));
        }
        
        return sol;
        
        
    }
} {
    
}
