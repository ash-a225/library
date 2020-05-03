#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_basic.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  auto f = [](ll x, ll y){ return min(x,y);};
  const ll INF = 1LL<<30; //60とかにするとバグる????
  SegmentTree<ll> rmq(n, f, INF);
  rmq.build(n, a);
  rep(_,q) {
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l,r) << "\n";
  }
  return 0;
}