class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty()){
            auto [currWord, steps] = q.front();
            q.pop();
            if(currWord == targetWord) return steps;
            
            for(int i = 0;i<currWord.size();i++){
                string temp = currWord;
                for(char ch = 'a';ch<='z';ch++){
                    temp[i] = ch;
                    
                    if(st.find(temp)!=st.end()){
                        q.push({temp, steps+1});
                        st.erase(temp);
                    }
                }
            }
        }
        
        return 0;
        
    }
};