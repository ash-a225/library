#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/potentialized_unionfind.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  UnionFind<ll> uf(n, 0);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      int x, y, z;
      cin >> x >> y >> z;
      uf.unite(x, y, z);
    }
    else {
      int x, y;
      cin >> x >> y;
      if (uf.same(x, y)) cout << uf.diff(x, y) << "\n";
      else cout << "?\n";
    }
  }
  return 0;
}