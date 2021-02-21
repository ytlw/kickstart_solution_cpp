#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string largest;
    cin.ignore(1); // ignore one char
    getline(cin, largest);
    int cost = 0;
    for (int j = 1; j < n; j++) {
        string s;
        getline(cin, s);
        if (s < largest) {
            ++cost;
        } else {
            largest = s;
        }
    }
    cout << cost << endl;
}

int main() {
#ifdef INPUT_FROM_FILE
    FILE *fre = freopen(INPUT_FILE, "r", stdin);
    if (fre == nullptr) {
        cout << "invalid input file" << endl;
        return 0;
    }
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
#ifdef INPUT_FROM_FILE
    fclose(fre);
#endif
    return 0;
}
