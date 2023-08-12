#include <iostream>
using namespace std;
bool isValidNumber(int num) {
    int digit1 = num / 100;
    int digit2 = (num / 10) % 10;
    int digit3 = num % 10;

    if (digit1 == 0 || digit2 == 0 || digit3 == 0) {
        return false; 
    }

    if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
        return false; 
    }

    return 1; 
}
bool hasDuplicate(int a, int b, int c)
{
    int digits = 0;
    while (a > 0) {
        int digit = a % 10;
        if (digits & (1 << digit)) {
            return true;
        }
        digits |= (1 << digit);
        a /= 10;
    }
    while (b > 0) {
        int digit = b % 10;
        if (digits & (1 << digit)) {
            return true;
        }
        digits |= (1 << digit);
        b /= 10;
    }
    while (c > 0) {
        int digit = c % 10;
        if (digits & (1 << digit)) {
            return true;
        }
        digits |= (1 << digit);
        c /= 10;
    }
    return false;
}
bool hasall(int i, int j, int k) {
    int q = i, w = j, e = k;
    for (int a = 1; a <= 9; a++) {
        int i = q, j = w, k = e;
        int m = 0;
        while (i > 0) {
            int digit = i % 10;
            if (digit == a) {
                m = 1;
                break;
            };
            i /= 10;
        }
        if (m == 1) continue;
        while (j > 0) {
            int digit = j % 10;
            if (digit == a) {
                m = 1;
                break;
            };
            j /= 10;
        }if (m == 1) continue;
        while (k > 0) {
            int digit = k % 10;
            if (digit == a) {
                m = 1;
                break;
            };
            k /= 10;
        }
        if (m == 1) continue;
        return 0;
    }
    return 1;
}
void printCombinations() {
    int count = 0;
    for (int i = 123; i <= 651; i++) {
        if (!isValidNumber(i)) continue;
        for (int j = i+1; j < (1953 - i) / 2 && j<=987 ; j++) {
            if (!isValidNumber(j)) continue;
            int k = 1953 - i - j;
            if ( k>987||!isValidNumber(k) || !hasall(i,j,k)) continue;

            cout << i << " + " << j << " + " << k << " = 1953" << std::endl;
                count++;
        }
    }
    cout << count << "¸ö" << endl;
}

int main() {
    printCombinations();
    return 0;
}