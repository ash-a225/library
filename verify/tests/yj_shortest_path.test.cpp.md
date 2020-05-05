---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: tests/yj_shortest_path.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_shortest_path.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 17:58:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/shortest_path">https://judge.yosupo.jp/problem/shortest_path</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/dijkstra.cpp.html">Graph/dijkstra.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
  vector<vector<P> > G(n);
  rep(i,m) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    G[a].emplace_back(P(b,c));
  }
  vector<ll> dist = dijkstra(n, s, G);
  vector<int> path = get_path(t);
  if (dist[t] >= 1LL<<60) {
    cout << -1 << endl;
    return 0;
  }
  cout << dist[t] << " " << path.size()-1 << endl;
  for (int i = 0; i < (int)path.size()-1; ++i) {
    cout << path[i] << " " << path[i+1] << endl;
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_shortest_path.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Graph/dijkstra.cpp"



vector<int> preV;

template <typename T>
vector<T> dijkstra(int n, int s, const vector<vector<pair<int,T> > > &G) {
  priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > que;
  const T INF = numeric_limits<T>::max();
  vector<T> dist(n, INF);
  preV = vector<int>(n, -1);
  dist[s] = 0;
  que.push(pair<T,int>(0,s));
  while(!que.empty()) {
    pair<T,int> p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (auto e : G[v]) {
      int to = e.first;
      T cost = e.second;
      if (dist[to] > dist[v] + cost) {
        dist[to] = p.first + cost;
        preV[to] = v;
        que.push(pair<T,int>(dist[to], to));
      }
    }
  }
  return dist;
}

vector<int> get_path(int t) { //tへの経路復元
  vector<int> path;
  for(; t != -1; t = preV[t]){
    path.emplace_back(t);
  }
  reverse(path.begin(), path.end());
  return path;
}


#line 12 "tests/yj_shortest_path.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<P> > G(n);
  rep(i,m) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    G[a].emplace_back(P(b,c));
  }
  vector<ll> dist = dijkstra(n, s, G);
  vector<int> path = get_path(t);
  if (dist[t] >= 1LL<<60) {
    cout << -1 << endl;
    return 0;
  }
  cout << dist[t] << " " << path.size()-1 << endl;
  for (int i = 0; i < (int)path.size()-1; ++i) {
    cout << path[i] << " " << path[i+1] << endl;
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

