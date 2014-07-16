class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int t = digits.size() - 1;
        //bool up_digit = true;
        while(t + 1){
            if(digits[t] < 9){
                digits[t]++;
                return digits;
            }
            else{
                digits[t] = 0;
                t--;
            }
        }
        if(digits[t+1] == 0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
