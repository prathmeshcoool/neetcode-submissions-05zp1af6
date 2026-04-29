class Solution {
public:
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});

        int cnt=0;
        while(q.size()){
        
            int sz=q.size();
            cnt++;
            for(int i=0;i<sz;i++){
                pair<int,int> p=q.front(); q.pop();

                for(auto d:directions){
                    int nc=p.first+d[0];
                    int nr=p.second+d[1];

                    if(nc<0 || nr<0 || nc>=n || nr>=n || grid[nc][nr]==1)continue;
                    grid[nc][nr]=1;
                    if(nc==n-1 && nr==n-1){
                        cnt++;
                        return cnt;
                    }
                    q.push({nc,nr});
                }
            }
        }
        return -1;
    }
};