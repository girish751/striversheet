class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        const int primes[26] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        const int mod = 1000000007;
        
        auto normal = [&](const string& s) {
            long long res = 1;
            for (char c : s)
                res = (res * primes[c - 97]) % mod;
            return (int)res;
        };
        
        vector<string> res;
        res.push_back(words[0]);
        int prev = normal(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            int key = normal(words[i]);
            if (key != prev) {
                res.push_back(words[i]);
                prev = key;
            }
        }
        
        return res;
    }
};