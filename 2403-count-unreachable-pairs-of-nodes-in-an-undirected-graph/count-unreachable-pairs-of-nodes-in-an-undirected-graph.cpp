class Solution {
public:
vector<int>parent;
vector<int>rank;
int findParent(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x] = findParent(parent[x]);
}
void makeUnion(int u,int v){
    int pu = findParent(u);
    int pv = findParent(v);

    if(pu!=pv){
        //then it will combine
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu]> rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.assign(n,-1);
        rank.assign(n,0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        for(auto &it:edges){
            int u = it[0];
            int v = it[1];

            if(findParent(u)!=findParent(v)){
                //union
                makeUnion(u,v);
            }
        }

        unordered_map<int,long long>mpp;
        for(int i = 0;i<n;i++){
            int p = findParent(i);
            mpp[p]++;
        }

        long long ans = 0;
        for(auto it:mpp){
            long long ele = it.second;
            ans += ele*(n-ele);
            n = n-ele;
        }

        return ans;
    }
};