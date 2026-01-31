class Solution {
  public:
  vector<int>parent;
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    // Function to detect cycle using DSU in an undirected graph.
    bool findUnion(int u, int v){
        int ultimate_parent_of_u = findParent(u);
        int ultimate_parent_of_v = findParent(v);
        
        if(ultimate_parent_of_u != ultimate_parent_of_v){
            parent[ultimate_parent_of_v] = ultimate_parent_of_u;
        }
        else{
            return true;
        }
        return false;
    }
    int detectCycle(int V, vector<int> adj[]) {
        parent.assign(V,0);
        
        //every node is consider as individual set
        //every node is parent itself
        for(int i = 0;i<V;i++){
            parent[i] = i;
        }
        
        for(int u = 0;u<V;u++){
            for(auto v:adj[u]){
                if(u<v){ // as graph is undirected 0-2 => 2-0
                   if(findUnion(u,v))return 1; //cycle detected 
                }
            }
        }
        return 0;
    }
};