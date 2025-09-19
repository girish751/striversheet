class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto boolComaparator = [](int& a, int& b) {
            string s1 = to_string(a);
            string s2 = to_string(b);

            if (s1 + s2 > s2 + s1) { // means if s1 = 10, s2 = 2 -> 102 > 210
                                     // then return false;
                return true;
            }
            return false;
        };

        // we have first sort the elements as per bggest val after concatination
        sort(nums.begin(), nums.end(), boolComaparator);
        // after sorting check
        if (nums[0] == 0) {
            return "0";
        }

        string res = "";
        for (auto& n : nums) {
            string s = to_string(n);
            res += s;
        }
        return res;
    }
};