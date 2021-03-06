#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include "Graph/kruskal.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<Edge<ll> > G(m);
  rep(i,m) {
    Edge<ll> e;
    cin >> e.u >> e.v >> e.cost;
    G[i] = e;
  }
  Kruskal<ll> krs(n, G);
  cout << krs.get_sum() << endl;
  return 0;
}