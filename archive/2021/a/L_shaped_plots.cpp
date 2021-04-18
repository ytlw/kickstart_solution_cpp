#include <iostream>
#include <vector>

using namespace std;

inline int getDelta(int a, int b) {
    if (a * 2 <= b) {
        return a - 1;
    } else {
        auto delta = b / 2 - 1;
        if (delta > 0) {
            return delta;
        }
    }
    return 0;
}

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> cell(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> cell[i][j];
        }
    }
    // length[i][j][0] -- horizontal_length, left-->right
    // length[i][j][1] -- vertical length, top-->down
    vector<vector<vector<int>>> length(r, vector<vector<int>>(c, vector<int>(2)));

    // length2[i][j][0] -- horizontal_length, right-->left
    // length2[i][j][1] -- vertical length, down-->top
    vector<vector<vector<int>>> length2(r, vector<vector<int>>(c, vector<int>(2)));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (cell[i][j] == 1) {
                if (j == 0 || cell[i][j - 1] == 0) {
                    length[i][j][0] = 1;
                } else {
                    length[i][j][0] = length[i][j - 1][0] + 1;
                }

                if (i == 0 || cell[i - 1][j] == 0) {
                    length[i][j][1] = 1;
                } else {
                    length[i][j][1] = length[i - 1][j][1] + 1;
                }
            } else {
                length[i][j][0] = 0;
                length[i][j][1] = 0;
            }
        }
    }

    for (int i = r - 1; i >= 0; --i) {
        for (int j = c - 1; j >= 0; --j) {
            if (cell[i][j] == 1) {
                if (j == c - 1 || cell[i][j + 1] == 0) {
                    length2[i][j][0] = 1;
                } else {
                    length2[i][j][0] = length2[i][j + 1][0] + 1;
                }

                if (i == r - 1 || cell[i + 1][j] == 0) {
                    length2[i][j][1] = 1;
                } else {
                    length2[i][j][1] = length2[i + 1][j][1] + 1;
                }
            } else {
                length2[i][j][0] = 0;
                length2[i][j][1] = 0;
            }

        }
    }

    int cnt = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (cell[i][j] == 0) {
                continue;
            }
            /*
             *   +
             *   +
             *   +
             *  ++
             * */
            if (length[i][j][0] > 1 && length[i][j][1] > 3) {
                cnt += getDelta(length[i][j][0], length[i][j][1]);
            }

            /*    +
             * ++++
             * */
            if (length[i][j][0] > 3 && length[i][j][1] > 1) {
                cnt += getDelta(length[i][j][1], length[i][j][0]);
            }

            /*
             * +
             * +
             * +
             * ++
             * */
            if (length[i][j][1] > 3 && length2[i][j][0] > 1) {
                cnt += getDelta(length2[i][j][0], length[i][j][1]);
            }

            /* +
             * ++++
             * */
            if (length[i][j][1] > 1 && length2[i][j][0] > 3) {
                cnt += getDelta(length[i][j][1], length2[i][j][0]);
            }

            /* ++
             *  +
             *  +
             *  +
             * */
            if (length[i][j][0] > 1 && length2[i][j][1] > 3) {
                cnt += getDelta(length[i][j][0], length2[i][j][1]);
            }

            /*
             * ++++
             *    +
             * */
            if (length[i][j][0] > 3 && length2[i][j][1] > 1) {
                cnt += getDelta(length2[i][j][1], length[i][j][0]);
            }

            /*
             * ++
             * +
             * +
             * +
             * */
            if (length2[i][j][0] > 1 && length2[i][j][1] > 3) {
                cnt += getDelta(length2[i][j][0], length2[i][j][1]);
            }

            /*
             * ++++
             * +
             * */
            if (length2[i][j][0] > 3 && length2[i][j][1] > 1) {
                cnt += getDelta(length2[i][j][1], length2[i][j][0]);
            }
        }
    }
    cout << cnt << endl;
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
