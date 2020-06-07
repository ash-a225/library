#define PROBLEM "https://yukicoder.me/problems/no/898"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/doubling_lca_weight.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  using P = pair<int,ll>;
  vector<vector<P> > G(n);
  rep(i,n-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    G[u].emplace_back(P(v,w));
    G[v].emplace_back(P(u,w));
  }
  LowestCommonAncestor<ll> LCA(G, 0);
  int q;
  cin >> q;
  rep(i_,q) {
    int x,y,z;
    cin >> x >> y >> z;
    ll res = LCA.get_weight(x,y) + LCA.get_weight(y,z) + LCA.get_weight(z,x);
    res /= 2;
    cout << res << "\n";
  }
  return 0;
}