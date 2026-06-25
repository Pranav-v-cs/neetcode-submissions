class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        int x, y;
        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            x = stones.back(); 
            stones.pop_back();

            pop_heap(stones.begin(), stones.end());
            y = stones.back();
            stones.pop_back();

            if (x == y) {
                continue;
            } else {
                stones.push_back(abs(x - y));
                push_heap(stones.begin(), stones.end());
            }
        }

        return stones.empty() ? 0 : stones.front();
    }
};
