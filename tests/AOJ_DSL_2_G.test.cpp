#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_lazy.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  SegmentTree<ll,ll> lazy(n, plus<ll>(),plus<ll>(),plus<ll>(), 0, 0, multiplies<ll>());
  rep(_,q) {
    int com;
    cin >> com;
    if (com == 0) {
      int l,r;
      cin >> l >> r;
      ll x;
      cin >> x;
      lazy.update(l-1, r, x);
    }
    else {
      int l,r;
      cin >> l >> r;
      ll res = lazy.query(l-1,r);
      cout << res << "\n";
    }
  }
  return 0;
}