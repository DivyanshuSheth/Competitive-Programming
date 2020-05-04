class Solution {
public:
    string convert_to_binary (int num) {
        stack <int> s;
        int quotient = num, remainder;
        string bin_num = "";
        while (quotient != 0) {
            remainder = quotient % 2;
            quotient = quotient / 2;
            s.push(remainder);
        }
        while (!s.empty()) {
            bin_num = bin_num + to_string(s.top());
            s.pop();
        }
        return bin_num;
    }
    string conv_to_complement(string bin_num) {
        int i = 0;
        while (bin_num[i]) {
            bin_num[i] == '0' ? (bin_num[i] = '1') : (bin_num[i] = '0');
            i++;
        }
        return bin_num;
    }
    int bin_to_int(string bin_num) {
        stack <int> s;
        int result = 0, count = 0;
        for (char c : bin_num) {
            int ic = c - '0';
            s.push(ic);
        }
        while(!s.empty()) {
            result += s.top() * (pow(2, count));
            count++;
            s.pop();
        }
        return result;
    }
    int findComplement(int num) {
        int result;
        string bin_num = convert_to_binary(num);
        bin_num = conv_to_complement(bin_num);
        result = bin_to_int(bin_num);
        return result;
    }
};
