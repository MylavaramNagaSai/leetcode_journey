class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currTank = 0, startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            totalTank += diff;
            currTank += diff;

            if (currTank < 0) {
                // Can't start from current segment, reset start station
                startStation = i + 1;
                currTank = 0;
            }
        }

        return (totalTank >= 0) ? startStation : -1;
    }
};
