#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include "Graph/bfs/bfs.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int u,k;
    cin >> u >> k;
    u--;
    rep(j,k) {
      int v;
      cin >> v;
      v--;
      G[u].emplace_back(v);
    }
  }

  auto index = [](int v){ return v;};
  auto delta = [&](int v, auto update) {
    for (auto&& to : G[v]) {
      update(to);
    }
  };
  auto res = bfs(n, 0, delta, index);
  rep(i,n) {
    cout << i+1 << " " << res[i] << "\n";
  }
  return 0;
}