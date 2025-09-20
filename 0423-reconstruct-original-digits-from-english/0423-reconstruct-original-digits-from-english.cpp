static constexpr pair<char, int> digChars[10] = {{'z', 0}, {'w', 2}, {'x', 6}, {'s', 7}, {'g', 8}, {'h', 3}, {'v', 5}, {'f', 4}, {'o', 1}, {'e', 9}};

static string digWord[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

class Solution {
public:
    string originalDigits(string s) {
       
		int digits[10], tot = 0, alpha[123] = {};
   
        for (char c: s) alpha[c]++;
        for (auto d: digChars) {
           
            int n = alpha[d.first];
           
            digits[d.second] = n;
          
            tot += n;

            for (char c: digWord[d.second]) alpha[c] -= n;
        }
       
        string res(tot, '*');
        for (int i = 0, j = 0; i < 10; i++) {
            while(digits[i]--) {
                res[j++] = i + '0';
            }
        }
        return res;
    }
};