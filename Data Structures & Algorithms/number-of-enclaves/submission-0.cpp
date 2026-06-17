class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    void dfs(int i, int j, vector<vector<int>> &grid){

        for(auto d:directions){
            int nr = i + d[0];
            int nc = j + d[1];
            if(nc<0 || nr<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]==0)continue;
            
            grid[nr][nc] = 0;
            dfs(nr, nc, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++){
            if(grid[i][0]){
                grid[i][0] = 0;
                dfs(i, 0, grid);
            }
            if(grid[i][n-1]){
                grid[i][n-1] = 0;
                dfs(i, n-1, grid);
            }
        }

        for(int i=0; i<n; i++){
            if(grid[0][i]){
                grid[0][i] = 0;
                dfs(0, i, grid);
            }
            if(grid[m-1][i]){
                grid[m-1][i] = 0;
                dfs(m-1, i, grid);
            }
        }

        int cnt = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j])cnt++;
            }
        }

        return cnt;

    }
};