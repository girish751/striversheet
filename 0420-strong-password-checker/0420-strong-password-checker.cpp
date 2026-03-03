class Solution {
public:
    int strongPasswordChecker(string password) {
        // Get the length of the password
        int n = password.length();
        
        // Flags to check for character types
        bool hasLower = false, hasUpper = false, hasDigit = false;
        
        // First pass: check for missing character types
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }
        
        // Calculate the number of missing character types
        int missing = !hasLower + !hasUpper + !hasDigit;
        
        // 'change' counts replacements needed for repeating chars.
        // 'one' and 'two' count groups of repeating chars that can be fixed
        // most efficiently with 1 or 2 deletions, respectively.
        int change = 0, one = 0, two = 0;
        
        // Second pass: find repeating sequences
        for (int i = 2; i < n; ++i) {
            if (password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                int j = i;
                // Find the end of this repeating sequence
                while (j < n && password[j] == password[i - 2]) {
                    j++;
                }
                int len = j - (i - 2);
                change += len / 3; // Each 'aaa' sequence needs one replacement
                if (len % 3 == 0) one++;      // e.g., 'aaa', 'aaaaaa'
                else if (len % 3 == 1) two++; // e.g., 'aaaa', 'aaaaaaa'
                i = j - 1; // Move index to the end of the processed sequence
            }
        }
        
        // Case 1: Password is too short
        if (n < 6) {
            // Need at least 6-n insertions. These insertions can also fix missing types.
            // So, the answer is the maximum of these two requirements.
            return max(missing, 6 - n);
        } 
        // Case 2: Password length is in the ideal range
        else if (n <= 20) {
            // Length is okay. We just need to fix missing types and repeats.
            // A replacement can solve both at once.
            return max(missing, change);
        } 
        // Case 3: Password is too long
        else {
            int del = n - 20; // Number of characters we must delete
            
            // Greedily use deletions to reduce the number of replacements ('change') needed.
            // Priority 1: Use 1 deletion to fix a 'len % 3 == 0' sequence. Most efficient.
            change -= min(del, one);  // instead of changing the char, we can just del where I need to del 1 chars
            
            // Priority 2: Use 2 deletions to fix a 'len % 3 == 1' sequence.
            change -= min(max(0, del - one), two * 2) / 2;
            
            // Priority 3: Use remaining deletions. Any 3 deletions can fix one repeat.
            change -= max(0, del - one - two * 2) / 3;
            
            // Final result: mandatory deletions + remaining fixes.
            return del + max(missing, change);
        }
    }
};