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


# :heavy_check_mark: tests/AOJ_GRL_5_C.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_GRL_5_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 19:01:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/doubling_lca.cpp.html">Graph/doubling_lca.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Graph/doubling_lca.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int k;
    cin >> k;
    rep(_,k) {
      int c;
      cin >> c;
      G[i].emplace_back(c);
      G[c].emplace_back(i);
    }
  }
  LowestCommonAncestor LCA(G,0); //0を根
  int q;
  cin >> q;
  rep(i,q) {
    int u,v;
    cin >> u >> v;
    cout << LCA(u,v) << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_GRL_5_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Graph/doubling_lca.cpp"
/*
https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
https://algo-logic.info/lca/
http://satanic0258.hatenablog.com/entry/2017/02/23/222647
*/
//par[i][v]   vの2^i個上の頂点
struct LowestCommonAncestor {
  private:
    vector<vector<int> > par;
    vector<int> dist; //from root
    const vector<vector<int> > &G;
    const int root;
    void dfs_(int v, int p, int d) {
      par[0][v] = p;
      dist[v] = d;
      for (auto to : G[v]) {
        if (to != p) dfs_(to, v, d+1);
      }
    }
    int query(int u,int v) {
      assert(u < (int)dist.size());
      assert(v < (int)dist.size());
      if (dist[u] > dist[v]) swap(u,v);
      int k = par.size();
      for (int i=0; i<k; ++i) { //LCAまでの距離を揃える
        if (((dist[v]-dist[u])>>i) & 1) v = par[i][v];
      }
      if (u==v) return u;
      for (int i = k-1; i>=0; --i) {
        if (par[i][u] == par[i][v]) continue;
        u = par[i][u];
        v = par[i][v];
      }
      return par[0][u];
    }
  public:
    LowestCommonAncestor(const vector<vector<int> > &G,int root=0):
    G(G),root(root){
      int n=G.size(), k=1;
      while ((1<<k) < n) k++;
      par.assign(k, vector<int>(n,-1));
      dist.assign(n,-1);
      dfs_(root,-1,0);
      for (int i=0; i<k-1; ++i) {
        for (int v=0; v<n; ++v) {
          if (par[i][v] < 0) par[i+1][v] = -1;
          else par[i+1][v] = par[i][par[i][v]];
        }
      }
    };
    int operator()(int u,int v) { return query(u,v);}
    int get_dist(int u, int v){ return dist[u]+dist[v]-2*dist[query(u,v)];}
    bool is_on_path(int u, int v, int a){ return get_dist(u,a)+get_dist(a,v)==get_dist(u,v);}
};
#line 12 "tests/AOJ_GRL_5_C.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int> > G(n);
  rep(i,n) {
    int k;
    cin >> k;
    rep(_,k) {
      int c;
      cin >> c;
      G[i].emplace_back(c);
      G[c].emplace_back(i);
    }
  }
  LowestCommonAncestor LCA(G,0); //0を根
  int q;
  cin >> q;
  rep(i,q) {
    int u,v;
    cin >> u >> v;
    cout << LCA(u,v) << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

