#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/modint.cpp"
#include "DataStructure/queue_aggression.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int q;
  cin >> q;
  using mint = modint<998244353>;
  using P = pair<mint, mint>;
  auto f = [](P a, P b) {
    return P(a.first*b.first, b.first*a.second + b.second); //合成
  };
  queue_aggression<P, decltype(f)> que(f);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      P p; cin >> p.first.x >> p.second.x;
      que.push(p);
    }
    else if (com == 1) {
      que.pop();
    }
    else {
      mint x; cin >> x.x;
      if (!que.empty()) {
        P p = que.fold_all();
        mint res = p.first*x + p.second;
        cout << res.x << "\n";
      }
      else cout << x.x << "\n";
    }
  }  
  return 0;
}