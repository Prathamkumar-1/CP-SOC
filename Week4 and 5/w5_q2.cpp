#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 2e5 + 5;

int n, q;
ll p[MAXN];

struct SegmentTree {
    vector<ll> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(4 * n, INF);
    }

    void update(int idx, ll val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql)
            return INF;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return min(query(ql, qr, 2 * node, l, mid),
                   query(ql, qr, 2 * node + 1, mid + 1, r));
    }

    void update(int idx, ll val) {
        update(idx, val, 1, 1, size);
    }

    ll query(int l, int r) {
        return query(l, r, 1, 1, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    SegmentTree segLeft, segRight;
    segLeft.init(n);
    segRight.init(n);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        segLeft.update(i, p[i] - i);
        segRight.update(i, p[i] + i);
    }

    while (q--) {
        int type, k;
        cin >> type >> k;
    if (type == 1){
            ll x;
            cin >> x;
            p[k] = x;
            segLeft.update(k, p[k] - k);
            segRight.update(k, p[k] + k);
    } else {
            ll leftMin = segLeft.query(1, k) + k;
            ll rightMin = segRight.query(k, n) - k;
            cout << min(leftMin, rightMin) << '\n';
    }
    }
    return 0;
}
