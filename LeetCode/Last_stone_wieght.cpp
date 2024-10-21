class Solution {
public:
    using Data = std::vector<int>;
    int lastStoneWeight(vector<int>& stones) {
        std::sort(stones.begin(), stones.end());

        while (stones.size() > 1) {
            int last = stones.size() - 1;
            int penultimate = last - 1;
            int smashResult = smash(stones[last], stones[penultimate]);

            stones.pop_back(); //pop last beggest ones
            stones.pop_back();

            if (0 != smashResult) {
                auto it = std::lower_bound(stones.begin(), stones.end(), smashResult);
                stones.insert(it, smashResult);
            }

        }      
        return (stones.size()) ? stones[0] : 0;
    }

    int smash(int first, int second) {
        if (first < second) {
            throw std::invalid_argument("first must be greater than second\n");
        }

        if (first == second) {
            return 0;
        }

        return first - second;
    }

};