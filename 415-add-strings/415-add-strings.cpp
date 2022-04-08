class Solution {
public:
    string addStrings(string num1, string num2) {
         if (num1.size() > num2.size())
            return addStrings(num2, num1);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string sum;
        
        int carry = 0, i = 0;

        for (; i < num1.size(); i++) {
            int curDigit = (num1[i] - '0' + num2[i] - '0' + carry) % 10;
            carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
            sum += to_string(curDigit);
        }
        for (; i < num2.size(); i++) {
            int curDigit = (num2[i] - '0' + carry) % 10;
            carry = (num2[i] - '0' + carry) / 10;
            sum += to_string(curDigit);
        }
        if (carry == 1)
            sum += "1";
        reverse(sum.begin(), sum.end());
        return sum;
        }
};









