#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include "DataStructure/unionfind.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  UnionFind tree(n);
  rep(i,q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) tree.unite(u, v);
    else {
      if (tree.same(u,v)) cout << 1 << "\n";
      else cout << 0 << "\n";
    }
  }
  return 0;
}