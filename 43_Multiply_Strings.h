class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            result[i] += carry;
        }

        size_t start_pos = result.find_first_not_of('0');
        if (string::npos != start_pos) {
            return result.substr(start_pos);
        }
        return "0";
    }
};