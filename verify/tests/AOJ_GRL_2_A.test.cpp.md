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


# :x: tests/AOJ_GRL_2_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_GRL_2_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-08 01:58:46+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :question: <a href="../../library/DataStructure/unionfind.cpp.html">DataStructure/unionfind.cpp</a>
* :x: <a href="../../library/Graph/kruskal.cpp.html">Graph/kruskal.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#include "DataStructure/unionfind.cpp"
#include "Graph/kruskal.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<edge> G(m);
  rep(i,m) {
    edge e;
    cin >> e.u >> e.v >> e.cost;
    G[i] = e;
  }
  Kruskal kr(n, G);
  cout << kr.get_sum() << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_GRL_2_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

#line 1 "DataStructure/unionfind.cpp"



struct UnionFind {
  vector<ll> par, siz;
  UnionFind(ll n):par(n),siz(n,1) {
    for (ll i = 0; i < n; ++i) par[i] = i;
  }
  ll size() { return par.size(); };
  ll root(ll x) {
    assert(x < size());
    if (par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(ll x, ll y) {
    assert(x < size());
    assert(y < size());
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry) return;
    if (siz[rx] < siz[y]) std::swap(rx, ry);
    par[rx] = ry;
    siz[ry] += siz[rx];
  }
  bool same(ll x, ll y) { 
    assert(x < size());
    assert(y < size());
    return root(x) == root(y);
  }
  ll size(ll x) {
    assert(x < size());
    return siz[root(x)];
  }
};


#line 1 "Graph/kruskal.cpp"



struct Edge { 
  int u, v, id;
  ll cost; 
  Edge(){}
	Edge(int u,int v,ll cost,int id):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<Edge> edges;
    int n;
    UnionFind uf;
    vector<bool> used;
  public:
    Kruskal(int n_, const vector<Edge> &edges_):
    edges(edges_),n(n_),uf(n_){ init();}
    void init() {
      sum = 0;
      used.assign((int)edges.size(),false);
    }
    void build() {
      sort(edges.begin(),edges.end());
      for (auto e : edges) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
          used[e.id] = true;
        }
      }
    }
    ll get_sum(){ return sum;}
    bool is_used(int id){ 
      assert(id < n);
      return used[id];
    }
};


#line 11 "tests/AOJ_GRL_2_A.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<edge> G(m);
  rep(i,m) {
    edge e;
    cin >> e.u >> e.v >> e.cost;
    G[i] = e;
  }
  Kruskal kr(n, G);
  cout << kr.get_sum() << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

