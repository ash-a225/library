#define IGNORE
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

//参考 :https://niuez.github.io/2020/04/impl_abstract_dijkstra/

#include "Graph/bfs/bfs.cpp"
#include "Graph/bfs/grid_delta.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w;
  cin >> h >> w;
  P st, go;
  cin >> st.first >> st.second >> go.first >> go.second;
  st.first--; st.second--; go.first--; go.second--;

  vector<string> s(h);
  rep(i,h) cin >> s[i];
  auto index = grid_index(h,w);
  auto caller = [&](P v, P t, auto update) {
    if (s[t.first][t.second] == '.') update(t);
  };
  auto delta = make_grid_delta(h, w, caller);

  auto res = bfs(h*w, st, delta, index);
  //caller : updateを呼び出すラムダ式
  //index : グリッド上の座標を1次元で表す
  return 0;
}