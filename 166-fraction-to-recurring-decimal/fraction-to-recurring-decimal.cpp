class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result;

        if((long long) numerator * (long long) denominator < 0)
        result += "-";

        long long absnumerator = labs(numerator);
        long long absdenominator = labs(denominator);

        long long intergerDiv = absnumerator/absdenominator;

        result += to_string(intergerDiv);

        long long remain = absnumerator % absdenominator;
        if(remain == 0) return result;

        result += ".";

        unordered_map<int,int> mp;
        while(remain != 0)
        {
            if(mp.find(remain) != mp.end())
            {
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }
            mp[remain] = result.size();
            remain *= 10;
            int digit = remain / absdenominator;
            result += to_string(digit);
            remain = remain % absdenominator;
        }
        return result;
    }
};