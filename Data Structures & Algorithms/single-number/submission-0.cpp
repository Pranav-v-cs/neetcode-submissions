class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (const short a: nums) {
            x ^= a;
        }
        return x;
    }
};
