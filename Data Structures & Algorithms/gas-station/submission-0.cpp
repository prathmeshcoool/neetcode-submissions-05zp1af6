class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, ans = -1;

        int i = 0;
        vector<bool> visited(n, false);

        while(i!=ans){
            if(i==ans)
                return ans;
            if(ans==-1){
                if(visited[i])
                    return -1;
                ans = i;
                visited[i]=true;
            }
            
            sum+=(gas[i]-cost[i]);

            if(sum < 0){
                sum = 0;
                ans = -1;
            }
            i++;
            i%=n;
        }

        return ans;


    }
};
