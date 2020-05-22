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
    - Last commit date: 2020-05-22 11:31:56+09:00


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



template <typename T>
struct Dijkstra {
  private:
    struct edge{
      int to;
      T cost;
      edge(int to,T cost):to(to),cost(cost){}
      bool operator<(const edge &e)const{return cost>e.cost;}
    };
    int n;
    vector<vector<edge> > G;
    vector<T> dist;
    vector<int> preV;
  public:
    Dijkstra(int n_):n(n_),G(n_){};
    void add_edge(int u, int v, T c) {
      assert(u < n);
      assert(v < n);
      G[u].emplace_back(v,c);
    }
    void build(int s) {
      dist.assign(n,numeric_limits<T>::max());
      preV.assign(n,-1);
      dist[s] = 0;
      priority_queue<edge> que;
      que.push(edge(s,0LL));
      while(!que.empty()) {
        auto p = que.top(); que.pop();
        int v = p.to;
        if (dist[v] < p.cost) continue;
        for (auto e:G[v]) {
          if (dist[e.to] > dist[v]+e.cost) {
            dist[e.to] = p.cost+e.cost;
            preV[e.to] = v;
            que.push(edge(e.to,dist[e.to]));
          }
        }
      }
    }
    vector<int> get_path(int to) { //経路復元
      vector<int> path;
      for(; to != -1; to = preV[to]){
        path.emplace_back(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
    T operator[](int k){
      assert(k < n);
      return dist[k];
    }
};


#line 12 "tests/yj_shortest_path.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

