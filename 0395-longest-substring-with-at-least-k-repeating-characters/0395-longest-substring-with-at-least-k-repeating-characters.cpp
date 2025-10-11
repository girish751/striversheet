class Solution {
public:
    int k;

    int longestSubstring(string s, int k) {
        this->k = k;
        return helper(s, 0, s.size());
    }

    int helper(const string& s, int l, int r) {
        if (r - l < k) return 0;

        unordered_map<char, int> freq;
        for (int i = l; i < r; ++i) {
            freq[s[i]]++;
        }

        for (int mid = l; mid < r; ++mid) {
            if (freq[s[mid]] < k) {
                int next = mid + 1;
                // Skip all consecutive invalid chars
                while (next < r && freq[s[next]] < k) next++;
                return max(helper(s, l, mid), helper(s, next, r));
            }
        }

        return r - l; // whole string is valid
    }
};