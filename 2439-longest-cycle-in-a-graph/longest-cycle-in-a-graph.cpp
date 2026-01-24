class Solution {
public:
void dfs(int node, vector<bool>&visited, vector<int>&count, vector<bool>&path,vector<int>& edges,
 int &res){
   if(node!=-1){
    visited[node] = 1;
    path[node] = 1;

    //visite it neightbour
    int v = edges[node];
    if(v!=-1 && !visited[v]){
        count[v] = count[node] + 1 ;
        dfs(v,visited, count, path, edges, res);
    }
    else if(v!=-1 && path[v]){
        //loop detected
        res = max(res, count[node] - count[v] + 1);

    }

    path[node] = 0;
   }
}
    int longestCycle(vector<int>& edges) {
        int v = edges.size();
        vector<bool>visited(v,0);
        vector<int>count(v,1);
        vector<bool>path(v,0);

        int res = -1;

        for(int i = 0;i<v;i++){
            if(!visited[i]){
                dfs(i,visited,count, path, edges,res);
            }
        }
        return res;
    }
};