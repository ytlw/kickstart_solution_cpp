#include <iostream>
#include <vector>

using namespace std;

long long digits2num(vector<int> &digits, int n) {
    long long v = 0;
    for (int i = n - 1; i >= 0; --i) {
        v = v * 10 + digits[i];
    }
    return v;
}

// side = 9 means to set biggest, side = 1 means to set smallest
void fillDigits(vector<int> &digits, int start, int offset, int side) {
    for (int i = start; i >= 0; --i) {
        offset = side - offset;
        digits[i] = offset;
    }
}

int check(vector<int> &digits, int n, int &offset) {
    int pos = n - 1;
    offset = 1;
    for (; pos >= 0; --pos) {
        if (digits[pos] % 2  != offset) {
            break;
        }
        offset = 1 - offset;
    }
    return pos;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    if (l > r) {
        cout << 0 << endl;
        return;
    }
    vector<int> digitsL, digitsR;
    digitsL.reserve(20), digitsR.reserve(20);
    vector<long long> all(20);
    long long t = l;
    do {
        digitsL.push_back(t % 10);
        t /= 10;
    } while (t > 0);
    t = r;
    do {
        digitsR.push_back(t % 10);
        t /= 10;
    } while (t > 0);
    int lenL = digitsL.size();
    int lenR = digitsR.size();

    all[0] = 1;
    // base 5
    // all[1]: 0~9, all[2]: 10~99, all[3]: 100~999
    for (int i = 1; i <= lenR; ++i) {
        all[i] = all[i - 1] * 5;
    }
    // find smallest number start >= l, which satisfies condition
    long long start, end;
    int offset; // offset = 1 means odd, offset = 0 means even
    int pos = check(digitsL, lenL, offset);
    if (pos < 0) {
        start = l;
    } else {
        if (digitsL[pos] != 9) {
            ++digitsL[pos];
            fillDigits(digitsL, pos - 1, offset, 1);
        } else {
            digitsL[pos] = 0;
            int tmpPos = pos + 1;
            while (tmpPos < lenL) {
                digitsL[tmpPos] += 2;
                if (digitsL[tmpPos] > 9) {
                    digitsL[tmpPos] %= 10;
                    ++tmpPos;
                } else {
                    break;
                }
            }
            if (tmpPos == lenL) {
                digitsL.push_back(1);
                ++lenL;
            }
            fillDigits(digitsL, pos - 1, offset, 1);
        }
        start = digits2num(digitsL, lenL);
    }
    if (start > r) {
        cout << 0 << endl;
        return;
    }
    // find biggest number end <= r, which satisfies condition
    pos = check(digitsR, lenR, offset);
    if (pos < 0) {
        end = r;
    } else {
        if (digitsR[pos] != 0) {
            --digitsR[pos];
            fillDigits(digitsR, pos - 1, offset, 9);
        } else {
            digitsR[pos] = 9;
            int tmpPos = pos + 1;
            while (tmpPos < lenR) {
                digitsR[tmpPos] -= 2;
                if (digitsR[tmpPos] < 0) {
                    digitsR[tmpPos] += 10;
                    ++tmpPos;
                } else {
                    break;
                }
            }
            if (tmpPos == lenR) {
                --lenR;
            }
            fillDigits(digitsR, pos - 1, offset, 9);
        }
        end = digits2num(digitsR, lenR);
    }
    if (start > end) {
        cout << 0 << endl;
        return;
    }
    long long startBase5 = 0;
    long long endBase5 = 0;
    for (int i = 0; i < lenL; ++i) {
        startBase5 += all[i] * (digitsL[i] / 2 + 1);
    }
    for (int i = 0; i < lenR; ++i) {
        endBase5 += all[i] * (digitsR[i] / 2 + 1);
    }
    cout << endBase5 - startBase5 + 1 << endl;
}

int main() {
#ifdef INPUT_FILE
    FILE *fre = freopen(INPUT_FILE, "r", stdin);
    if (fre == nullptr) {
        cout << "invalid input file" << endl;
        return 0;
    }
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifdef INPUT_FILE
    fclose(fre);
#endif
    return 0;
}
