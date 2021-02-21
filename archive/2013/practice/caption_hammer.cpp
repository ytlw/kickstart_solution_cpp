// 坑爹的地方：可能会有nan的值，这时候要输出45.0
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void solve() {
    int v, d;
    cin >> v >> d;
    double ans = asin(d * 9.8/v/v) / M_PI * 90.0;
    if (isnan(ans)) {
        ans = 45.0;
    }
    cout << fixed << setprecision(7) << ans << endl;
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
