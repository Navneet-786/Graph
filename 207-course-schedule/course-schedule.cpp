class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>adjList[numCourses];
        
        //create adjList
        for(auto it: pre){
            int v = it[0];
            int u = it[1];
            adjList[u].push_back(v);
        }
        
        
        // create inorder array
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        
        //bfs ->khans algo
        queue<int>q;
        //store all the element whose indegree is 0
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        //use BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            count++;
            
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count != numCourses)return false;
        return true;
    }
};