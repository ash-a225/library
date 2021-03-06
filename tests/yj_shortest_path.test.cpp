#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/dijkstra.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  Dijkstra<ll> G(n);
  rep(i,m) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    G.add_edge(a, b, c);
  }
  G.build(s);
  vector<int> path = G.get_path(t);
  if (G[t] >= 1LL<<60) {
    cout << -1 << endl;
    return 0;
  }
  cout << G[t] << " " << path.size()-1 << endl;
  for (int i = 0; i < (int)path.size()-1; ++i) {
    cout << path[i] << " " << path[i+1] << endl;
  }
  return 0;
}