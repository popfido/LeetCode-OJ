class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        transform(s.begin(), s.end(),s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while(left<right){
            if (!::isalnum(*left)) left++;
            else if (!::isalnum(*right)) right--;
            else if (*left != *right) return false;
            else {left++; right--;}
        }
        return true;
    }
};
