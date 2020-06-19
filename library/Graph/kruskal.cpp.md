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
    - Last commit date: 2020-06-19 17:45:01+09:00




## Depends on

* :heavy_check_mark: <a href="../DataStructure/unionfind.cpp.html">DataStructure/unionfind.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_GRL_2_A.test.cpp.html">tests/AOJ_GRL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "DataStructure/unionfind.cpp"

template<typename T>
struct Edge { 
  int u, v, id;
  T cost; 
  Edge():id(0){}
	Edge(int u,int v,T cost,int id=0):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

template<typename T>
struct Kruskal {
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

template<typename T>
struct Kruskal {
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

