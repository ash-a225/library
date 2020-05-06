#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/doubling_lca.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int k;
    cin >> k;
    rep(_,k) {
      int c;
      cin >> c;
      G[i].emplace_back(c);
      G[c].emplace_back(i);
    }
  }
  LowestCommonAncestor LCA(G, 0); //0を根
  int q;
  cin >> q;
  rep(i,q) {
    int u,v;
    cin >> u >> v;
    cout << LCA.query(u,v) << "\n";
  }
  return 0;
}