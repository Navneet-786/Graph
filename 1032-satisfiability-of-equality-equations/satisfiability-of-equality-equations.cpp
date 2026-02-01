class Solution {
public:
vector<int>parent;
vector<int>rank;
int findParent(int x){
    if(x==parent[x]){
        return x;
    }

    return parent[x] = findParent(parent[x]);
}
void makeUnion(char first, char second){
    int pu = findParent(first - 'a');
    int pv = findParent(second - 'a');

    if(pu != pv){
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]= pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
}
    bool equationsPossible(vector<string>& equations) {
        parent.assign(26,-1);
        rank.assign(26,0);
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }

        for(auto it:equations){
            char first = it[0];
            char second = it[3];
            char targetSymbol = it[1];

            if(findParent(first-'a')!=findParent(second - 'a')){
                //if both have different set
                //make them union if they are equal
                if(targetSymbol=='='){
                    makeUnion(first, second);
                }
            } 
            else{
                //we have to check if both element are in same set
                //check sign must not be !
                if(targetSymbol == '!'){
                    return false;
                }
            }
        }
        for(auto it:equations){
            char var = it[1];
            if(var == '!'){
                int u = findParent(it[0]-'a');
                int v = findParent(it[3]-'a');

                if(u == v)return false;

            }
        }

        return true;
    }
};