#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int len = s.size();
    int mid = len / 2;
    int currentK = 0;
    for (int i = 1; i <= mid; ++i) {
        if (s[i - 1] != s[n - i]) {
            ++currentK;
        }
    }
    cout << abs(k - currentK) << endl;
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
