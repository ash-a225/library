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


# :heavy_check_mark: tests/AOJ_GRL_1_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_GRL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 17:58:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/bellman_ford.cpp.html">Graph/bellman_ford.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_GRL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Graph/bellman_ford.cpp"



template <typename T>
bool bellman_ford(int n, int s, vector<T> &dist, const vector<vector<pair<int,T> > > &G) {
  const T INF = numeric_limits<T>::max();
  dist.resize(n, INF);
  dist[s] = 0;
  rep(cnt,n) {
    rep(v,n) {
      for (auto e : G[v]) {
        int to = e.first;
        T cost = e.second;
        if (dist[v] != INF && dist[to] > dist[v]+cost) {
          dist[to] = dist[v] + cost;
          if (cnt == n-1) return false; //NEGATIVE CYCLE
        }
      }
    }
  }
  return true;
}


#line 11 "tests/AOJ_GRL_1_B.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

