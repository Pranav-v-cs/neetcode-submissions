class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expSum = nums.size();
        expSum = (expSum * (expSum + 1)) / 2;
        int s = 0;
        for (const int n: nums) 
            s += n;

        return expSum - s;
    }
};
