#include <bits/stdc++.h>
using namespace std;

const int N = 8, K = 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
double dp[K + 1][N][N][N][N];

int main() {
    int k;
    cin >> k;
    memset(dp, -1, sizeof(dp));

    auto get_prob = [&](int k, int sx, int sy, int ex, int ey, auto&& get_prob_ref) -> double {
        if (k == 0) return (sx == ex && sy == ey) ? 1.0 : 0.0;
        double& res = dp[k][sx][sy][ex][ey];
        if (res >= 0) return res;
        res = 0.0;
        for (int d = 0; d < 4; ++d) {
            int nx = sx + dx[d], ny = sy + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int cnt = 0;
                for (int nd = 0; nd < 4; ++nd) {
                    int tx = sx + dx[nd], ty = sy + dy[nd];
                    if (tx >= 0 && tx < N && ty >= 0 && ty < N) ++cnt;
                }
                res += get_prob_ref(k - 1, nx, ny, ex, ey, get_prob_ref) / cnt;
            }
        }
        return res;
    };

    double ans = 0.0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            double p = 1.0;
            for (int sx = 0; sx < N; ++sx) {
                for (int sy = 0; sy < N; ++sy) {
                    p *= (1.0 - get_prob(k, sx, sy, x, y, get_prob));
                }
            }
            ans += p;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
