class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      if(stones.size()==1)return stones[0];

      priority_queue<int>q;

      for(auto &it:stones){
        q.push(it);
      }

      while(q.size()>1){
        int firstStone = q.top();
        q.pop();
        int secondStone = q.top();
        q.pop();

        int res = abs(firstStone-secondStone);
        if(res!=0){
            q.push(res);
        }
      }

      return q.size()==0 ?0:q.top();
    }
};