#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DP/rerooting.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  using P = pair<ll,ll>;
  auto f = [&](P a, int v, int i){ 
    return P(a.first-a.second, 2+a.second);
  };
  auto combine = [](P a, P b){ 
    return P(min(a.first,b.first), a.second+b.second);
  };
  auto g = [&](P a, int v){ 
    return P(a.first+a.second-1, a.second);
  };
  ReRooting<P> RR(G, f, combine, P(1,0), g);
  RR.build();
  rep(i,n) {
    cout << RR[i].first << "\n";
  }
  return 0;
}