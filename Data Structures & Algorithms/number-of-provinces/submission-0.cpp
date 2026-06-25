class Solution {
public:
    vector<int> par, rank;
    
    void DSU(int n){
        par.resize(n);
        rank.resize(n,0);

        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int i){
        if(par[i]==i)
            return i;

        return par[i] = find(par[i]);
    }

    void Union(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i == root_j)
            return;

        if(rank[root_i]>rank[root_j]){
            par[root_j] = root_i;
            rank[root_i]++;
        }
        else if(rank[root_j]>rank[root_i]){
            par[root_i] = root_j;
            rank[root_j]++;
        }
        else{
            par[root_i] = root_j;
            rank[root_j]++;
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DSU(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    Union(i,j);
                }
            }
        }

        unordered_set<int> s;
        for(int i=0; i<n; i++){
            int parent = find(i);
            s.insert(parent);
        }

        return s.size();
    }
};