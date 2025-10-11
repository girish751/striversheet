class Solution {
public:
    bool isSubsequence(const string& a, const string& b) {
        int i = 0;
        for (int j = 0, blen = b.size(); j < blen; ++j) {
            if (i < a.size() && a[i] == b[j]) ++i;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        for (int i = 0; i < strs.size(); ++i) {
            bool unique = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    unique = false;
                    break;
                }
            }
            if (unique) return strs[i].length();
        }
        return -1;
    }
};