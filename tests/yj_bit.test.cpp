#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/binary_indexed_tree.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  BIT<ll> bit(n);
  rep(i,n) {
    int a;
    cin >> a;
    bit.add(i,a);
  }
  rep(i,q) {
    int c;
    cin >> c;
    if (c == 0) {
      int p;
      ll x;
      cin >> p >> x;
      bit.add(p,x);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << bit.sum(l,r) << "\n";
    }
  }
  return 0;
}