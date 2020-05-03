#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_basic.cpp"
#include "Math/modint2.cpp"

using P = pair<mint,mint>;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<P> v(n);
  rep(i,n) cin >> v[i].first >> v[i].second;
  auto f = [](P a, P b){ //1次関数の合成
    return P(a.first*b.first, b.first*a.second + b.second);
  };
  SegmentTree<P> seg(n, f, P(1,0));
  seg.build(n, v);
  rep(_,q) {
    int com; cin >> com;
    if (com == 0) {
      int i;
      P p;
      cin >> i >> p.first >> p.second;
      seg.set_val(i, p);
    }
    else {
      int l,r;
      mint x;
      cin >> l >> r >> x;
      P p = seg.query(l,r);
      mint res = p.first*x + p.second;
      cout << res << "\n";
    }
  }
  return 0;
}