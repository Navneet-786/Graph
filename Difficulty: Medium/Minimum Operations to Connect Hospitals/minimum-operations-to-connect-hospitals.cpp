class Solution {
  public:
//   DSU->union->find
    vector<int>parent;
    vector<int>rank;
    //find 
    int findParent(int node){
        if(node ==  parent[node]){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    //union
    void MakeUnion(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu!=pv){
            //if rank of pu is smaller then pv
            // then make parent of pu is pv
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }
            else{
                //if both have equal rank
                parent[pu] = pv; //anything
                rank[pv]++;
            }
        }
        
    }
    int minConnect(int V, vector<vector<int>>& edges) {
      int expectedEdges = V-1;
      int presentEdges = edges.size();
      if(presentEdges < expectedEdges)return -1;//never possible to connect all element
      
      parent.assign(V,0);
      rank.assign(V,0);
      
      //initially every body is of their own parent
      for(int i = 0;i<V;i++){
          parent[i] = i;
      }
      int component = V; //when no body is connected
    //   lets connect them
      for(auto it:edges){
          int u =  it[0];
          int v = it[1];
          
          if(findParent(u)!=findParent(v)){
              //if both have different parent
              //make union
              MakeUnion(u,v);
              component--;
          }
          
      }
      return component-1;
    }
};
