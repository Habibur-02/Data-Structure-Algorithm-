#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void makeEqualLength(string &str1, string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    if (len1 < len2) {
        str1 = string(len2 - len1, '0') + str1;
    } else if (len1 > len2) {
        str2 = string(len1 - len2, '0') + str2;
    }
}

string addStrings(string str1, string str2) {
    makeEqualLength(str1, str2);
    int n = str1.size();
    string result = "";
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }

    if (carry) {
        result = to_string(carry) + result;
    }

    return result;
}

string subtractStrings(string str1, string str2) {
    makeEqualLength(str1, str2);
    int n = str1.size();
    string result = "";
    int borrow = 0;

    for (int i = n - 1; i >= 0; i--) {
        int digit1 = str1[i] - '0' - borrow;
        int digit2 = str2[i] - '0';

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = to_string(digit1 - digit2) + result;
    }

    // leading zeros remove
    while (result.size() > 1 && result[0] == '0') {
        result = result.substr(1);
    }

    return result;
}

string karatsubaMultiply(string x, string y) {
    if (x.size() <= 2 || y.size() <= 2) {
        long long result = stoll(x) * stoll(y);
        return to_string(result);
    }

    makeEqualLength(x, y);
    int n = x.size();
    int m = n / 2;

    string high1 = x.substr(0, n - m);
    string low1 = x.substr(n - m);

    string high2 = y.substr(0, n - m);
    string low2 = y.substr(n - m);



    string z0 = karatsubaMultiply(low1, low2);
    string z2 = karatsubaMultiply(high1, high2);
    string z1 = karatsubaMultiply(addStrings(high1, low1), addStrings(high2, low2));



    // z1 - z2 - z0
    string z1_minus = subtractStrings(subtractStrings(z1, z2), z0);

    string part1 = z2 + string(2 * m, '0');        // z2 × 10^(2m)
    string part2 = z1_minus + string(m, '0');      // z1_minus × 10^m

    string result = addStrings(addStrings(part1, part2), z0);



    return result;
}

int main() {

    string num1, num2;

    cin >> num1;
    cin >> num2;

    cout << "========================================" << endl;

    string result = karatsubaMultiply(num1, num2);

    long long expected = stoll(num1) * stoll(num2);

    cout<<result;

    return 0;
}


