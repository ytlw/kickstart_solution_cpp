#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    int i = n - 1;
    while (i >= 0) {
        int j = i - 1;
        for (; j >= 0 && s[j] < s[j + 1]; --j) {
        }
        ans[i] = i - j;
        for (int k = i - 1; k > j; --k) {
            ans[k] = ans[k + 1] - 1;
        }
        i = j;
    }
    for (i = 0; i < n; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
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
