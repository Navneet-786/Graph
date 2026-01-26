// User function Template for C++

class Solution {
  public:
  int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        if(start  == end)return 0;
        
        vector<int>steps(mod, 1e9);
        //{steps, node}
        queue<pair<int,int>>q;
        q.push({0,start});
        steps[start] = 0;
        
        while(!q.empty()){
            auto [currSteps, currNode] = q.front();
            q.pop();
            
            if(steps[currNode] < currSteps)continue;
            
            for(auto it:arr){
                int num = (currNode * it)% mod;
                
                if(steps[currNode] + 1 < steps[num]){
                    steps[num] = currSteps + 1;
                    if(end ==  num){
                        return currSteps + 1;
                    }
                    q.push({steps[num], num});
                }
            }
        }
        return -1;
    }
    
};
