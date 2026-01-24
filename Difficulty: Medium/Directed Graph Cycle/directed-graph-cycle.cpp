class Solution {
  public:
//   bool solve(vector<int>adjList[], vector<bool>&path ,
//   vector<bool>&visited, int node){
//       visited[node] = 1;
//       path[node] = 1;
       
//       for(auto it:adjList[node]){
//           if(!visited[it]){
//               if(solve(adjList, path, visited,it)){
//                   return true;
//               }
//           }
//          else if (path[it]) {
//             return true;
//             }
//       }
//       path[node] = 0;
       
//       return false;
//   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
           
        }
        
        
        // ---------------------TOPOLOGICAL SORT-----------------------
        
        vector<int>indegree(V,0);
        for(int i = 0;i<V;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        
        //queue store all elemenet whose indegree is 0
        queue<int>q;
        for(int i =0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //decrease indegree of all adjacent element
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        
        for(auto it:indegree){
            if(it!=0)return true;
        }
        return false;
        //-------------------------------------------------------------
        // vector<bool>path(V,0);
        // vector<bool>visited(V,0);
        
        // for(int i = 0;i<V;i++){
        //     if(!visited[i]){
        //       if( solve(adjList,path,visited, i))return true;
        //     }
        // }
        
        // return false;
    }
};