class Solution {
  public:
 
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        vector<int>visited(adj.size(),0);
        
        stack<int>st;
        st.push(0);
        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            
            
            if(visited[ele])continue;
            
            visited[ele] = 1;
            
            ans.push_back(ele);
            
            for(int  i =adj[ele].size()-1;i>=0;i--){
                if(!visited[adj[ele][i]]){
                    st.push(adj[ele][i]);
                }
            }
        }
        
        return ans;
        
    }
};