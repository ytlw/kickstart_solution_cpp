#include <iostream>

using namespace std;

void solve() {
    long long n, k, s;
    cin >> n >> k >> s;
    long long t1 = n + k;
    long long t2 = k - 1 + (k - s) + (n - s + 1);
    cout << min(t1, t2) << endl;
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
