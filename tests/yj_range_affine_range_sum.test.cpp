#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_lazy.cpp"
#include "Math/modint2.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<mint> v(n);
  rep(i,n) cin >> v[i];
  auto f = [](mint a, mint b) {return a+b;};
  using P = pair<mint, mint>;
  auto g = [](mint a, P p) {return p.first*a + p.second;}; //要素への作用
  auto h = [](P a, P b){ //合成
    return P(a.first*b.first, b.first*a.second + b.second);
  };
  SegmentTree<mint,P> lazy(n, f, g, h, mint(0), P(mint(1),mint(0)));
  lazy.build(n, v);
  rep(_,q) {
    int com;
    cin >> com;
    if (com == 0) {
      int l,r;
      cin >> l >> r;
      P p;
      cin >> p.first >> p.second;
      lazy.update(l, r, p);
    }
    else {
      int l,r;
      cin >> l >> r;
      mint res = lazy.query(l,r);
      cout << res << "\n";
    }
  }
  return 0;
}