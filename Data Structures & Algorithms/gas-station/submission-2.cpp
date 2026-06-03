class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0, totalCost = 0;

        int startId = 0, sum = 0;

        for(int i=0; i<n; i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            sum+=(gas[i]-cost[i]);

            if(sum<0){
                sum = 0;
                startId = i + 1;
            }
        }

        return (totalGas>=totalCost)?startId:-1;
    }
};
