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


# :heavy_check_mark: Graph/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 03:13:03+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_GRL_2_A.test.cpp.html">tests/AOJ_GRL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef KRUSKAL_H
#define KRUSKAL_H

struct edge { 
  int u, v;
  ll cost; 
  edge(){}
	edge(int u, int v, ll cost):u(u), v(v), cost(cost){}
  bool operator<(const edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<edge> G;
    int n;
    UnionFind uf;
  public:
    Kruskal(int n_, const vector<edge> &G_):G(G_),n(n_),uf(n_){ init();}
    void init() {
      sort(G.begin(),G.end());
      sum = 0;
      for (auto e : G) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
        }
      }
    }
    ll get_sum(){ return sum;}
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/kruskal.cpp"



struct edge { 
  int u, v;
  ll cost; 
  edge(){}
	edge(int u, int v, ll cost):u(u), v(v), cost(cost){}
  bool operator<(const edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<edge> G;
    int n;
    UnionFind uf;
  public:
    Kruskal(int n_, const vector<edge> &G_):G(G_),n(n_),uf(n_){ init();}
    void init() {
      sort(G.begin(),G.end());
      sum = 0;
      for (auto e : G) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
        }
      }
    }
    ll get_sum(){ return sum;}
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

