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


# :heavy_check_mark: tests/yukicoder_898.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yukicoder_898.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-07 18:01:27+09:00


* see: <a href="https://yukicoder.me/problems/no/898">https://yukicoder.me/problems/no/898</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/doubling_lca_weight.cpp.html">Graph/doubling_lca_weight.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/898"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/doubling_lca_weight.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  using P = pair<int,ll>;
  vector<vector<P> > G(n);
  rep(i,n-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    G[u].emplace_back(P(v,w));
    G[v].emplace_back(P(u,w));
  }
  LowestCommonAncestor<ll> LCA(G, 0);
  int q;
  cin >> q;
  rep(i_,q) {
    int x,y,z;
    cin >> x >> y >> z;
    ll res = LCA.get_weight(x,y) + LCA.get_weight(y,z) + LCA.get_weight(z,x);
    res /= 2;
    cout << res << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yukicoder_898.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/898"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Graph/doubling_lca_weight.cpp"
/*
https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
https://algo-logic.info/lca/
http://satanic0258.hatenablog.com/entry/2017/02/23/222647
*/

//par[i][v]   vの2^i個上の頂点
//max_w[i][v] vの2^i個上の頂点までの重みの最大値
//get_weight(u,v) u-v間の重みの総和を返す
//get_max_w(u,v) u-v間の重みの最大値を返す
template<typename T>
struct LowestCommonAncestor {
  private:
    vector<vector<int> > par;
    vector<int> dist; //from root
    vector<T> weight; //from root
    vector<vector<T> > max_w;
    const vector<vector<pair<int,T> > > &G;

    void dfs_(int v, int p, int d, T w) {
      par[0][v] = p;
      dist[v] = d;
      weight[v] = w;
      for (auto to : G[v]) {
        if (to.first == p) continue; 
        dfs_(to.first, v, d+1, w+to.second);
        max_w[0][to.first] = to.second;
      }
    }
    int query(int u,int v) {
      assert(u < (int)dist.size());
      assert(v < (int)dist.size());
      if (dist[u] > dist[v]) swap(u,v);
      int k = par.size();
      for (int i = 0; i < k; ++i) { //LCAまでの距離を揃える
        if (((dist[v]-dist[u])>>i) & 1) v = par[i][v];
      }
      if (u == v) return u;
      for (int i = k-1; i >= 0; --i) {
        if (par[i][u] == par[i][v]) continue;
        u = par[i][u];
        v = par[i][v];
      }
      return par[0][u];
    }
  public:
    LowestCommonAncestor(const vector<vector<pair<int,T> > > &G, int root = 0):G(G){
      int n = G.size(), k = 1;
      while ((1<<k) < n) k++;
      par.assign(k, vector<int>(n,-1));
      dist.assign(n,-1);
      weight.assign(n,-1);
      max_w.assign(k, vector<T>(n,-1));
      dfs_(root, -1, 0, 0);
      for (int i = 0; i < k-1; ++i) {
        for (int v = 0; v < n; ++v) {
          if (par[i][v] < 0) par[i+1][v] = -1;
          else {
            par[i+1][v] = par[i][par[i][v]];
            max_w[i+1][v] = max(max_w[i][v], max_w[i][par[i][v]]);
          }
        }
      }
    }
    T get_max_w(int u, int v) {
      int x = query(u,v), k = par.size();
      T res = 0;
      for (int i = 0; i < k; ++i) { //LCAまで移動
        if (((dist[x]-dist[u])>>i) & 1) {
          chmax(res, max_w[i][u]);
          u = par[i][u];
        }
      }
      for (int i = 0; i < k; ++i) {
        if (((dist[x]-dist[v])>>i) & 1) {
          chmax(res, max_w[i][v]);
          v = par[i][v];
        }
      }
      return res;
    }
    int operator()(int u,int v){ return query(u,v);}
    int get_dist(int u, int v){ return dist[u] + dist[v] - 2*dist[query(u,v)];}
    T get_weight(int u, int v){ return weight[u] + weight[v] - 2*weight[query(u,v)];}
    bool is_on_path(int u, int v, int a){ return get_dist(u,a)+get_dist(a,v)==get_dist(u,v);}
};
#line 11 "tests/yukicoder_898.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  using P = pair<int,ll>;
  vector<vector<P> > G(n);
  rep(i,n-1) {
    int u,v;
    ll w;
    cin >> u >> v >> w;
    G[u].emplace_back(P(v,w));
    G[v].emplace_back(P(u,w));
  }
  LowestCommonAncestor<ll> LCA(G, 0);
  int q;
  cin >> q;
  rep(i_,q) {
    int x,y,z;
    cin >> x >> y >> z;
    ll res = LCA.get_weight(x,y) + LCA.get_weight(y,z) + LCA.get_weight(z,x);
    res /= 2;
    cout << res << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

