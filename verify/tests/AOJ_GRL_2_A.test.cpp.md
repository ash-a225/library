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


# :heavy_check_mark: tests/AOJ_GRL_2_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_GRL_2_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-25 12:38:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/unionfind.cpp.html">DataStructure/unionfind.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/kruskal.cpp.html">Graph/kruskal.cpp</a>


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
private:
  vector<int> par, siz;

public:
  UnionFind(int n):par(n),siz(n,1) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() {return par.size(); };
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    assert(x < size());
    assert(y < size());
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
  }
  
  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }
};
#line 2 "Graph/kruskal.cpp"

template<typename T>
struct Edge { 
  int u, v, id;
  T cost; 
  Edge():id(0){}
	Edge(int u,int v,T cost,int id=0):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

template<typename T> struct Kruskal {
private:
  T sum;
  vector<Edge<T> > edges;
  UnionFind uf;
  vector<bool> used;
  
public:
  Kruskal(int n, const vector<Edge<T> > &edges_):edges(edges_),uf(n){
    sum = 0;
    used.assign((int)edges.size(),false);
    sort(edges.begin(),edges.end());
    for (auto &e : edges) {
      if (!uf.same(e.u,e.v)) { //circleなし
        uf.unite(e.u,e.v);
        sum += e.cost;
        used[e.id] = true;
      }
    }
  }
  T get_sum(){ return sum;}
  bool is_used(int id){ 
    assert(id < (int)edges.size());
    return used[id];
  }
};
#line 10 "tests/AOJ_GRL_2_A.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

