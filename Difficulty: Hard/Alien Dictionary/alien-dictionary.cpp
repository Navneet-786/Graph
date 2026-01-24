class Solution {
  public:
    string findOrder(vector<string> &words) {
        //find the lenght of max word
        
        int n = 26;
       
        vector<bool> present(26, false);
        for (auto &w : words)
            for (char c : w){
                 present[c - 'a'] = true;
            }
                
        vector<int>adjList[n];
        //check for 2 consecutive words
        for(int i = 0;i<words.size()-1;i++){
            string str1 = words[i];
            string str2 = words[i+1];
            int len = min(str1.size(), str2.size());
            if (str1.size() > str2.size() && str1.substr(0, len) == str2){
                    return "";
            }

            for(int ptr = 0;ptr<len;ptr++){
                if(str1[ptr]!=str2[ptr]){
                    adjList[str1[ptr]-'a'].push_back(str2[ptr]-'a');
                    break;
                }
            }
        }
       
        
        //calculate indegree
        vector<int>indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it:adjList[i])indegree[it]++;
        }
        
        queue<int>q;
        string ans = "";
        
        //check for all indegree==0 element
        for(int i = 0 ;i<n;i++){
            if(present[i] && indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int ch = q.front();
            q.pop();
            
            ans += char(ch + 'a');
            
            for(auto it:adjList[ch]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
      int uniqueChars = 0;
        for (int i = 0; i < n; i++) if (present[i]) uniqueChars++;
        if (ans.size() != uniqueChars)
            return "";

        return ans;
        
    }
};