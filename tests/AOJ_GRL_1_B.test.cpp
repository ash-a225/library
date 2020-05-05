#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/bellman_ford.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n,m,s;
  cin >> n >> m >> s;
  using P = pair<int, ll>;
  vector<vector<P> > G(n);
  rep(i,m) {
    int u,v;
    ll d;
    cin >> u >> v >> d;
    G[u].emplace_back(P(v,d));
  }
  vector<ll> dist;
  bool nonneg = bellman_ford(n, s, dist, G); //負の経路があるとfalseが返る
  if (!nonneg) {
    cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  const ll INF = numeric_limits<ll>::max();
  rep(i,n) {
    if (dist[i] != INF) cout << dist[i] << "\n";
    else cout << "INF\n";
  }
  return 0;
}