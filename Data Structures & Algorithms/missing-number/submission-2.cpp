class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned short expSum = nums.size();
        expSum = (expSum * (expSum + 1)) / 2;

        unsigned short s = 0;
        for (const unsigned short n: nums) 
            s += n;

        return expSum - s;
    }
};
