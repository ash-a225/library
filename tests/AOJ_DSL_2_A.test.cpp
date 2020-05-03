#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
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
  auto f = [](ll x, ll y){ return min(x,y);};
  const ll INF = (1LL<<31)-1;
  SegmentTree<ll> rmq(n, f, INF);
  rep(_,q) {
    int com, x;
    cin >> com >> x;
    if (com == 0) {
      ll y; cin >> y;
      rmq.set_val(x, y);
    }
    else {
      int y; cin >> y;
      cout << rmq.query(x,y+1) << "\n";
    }
  }
  return 0;
}