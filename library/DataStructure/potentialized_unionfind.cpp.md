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


# :heavy_check_mark: DataStructure/potentialized_unionfind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/potentialized_unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 17:45:01+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DSL_1_B.test.cpp.html">tests/AOJ_DSL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename Abel> struct UnionFind {
private:
  vector<int> par, siz;
  vector<Abel> value; //NE: neutral of abelian group
  Abel potential(int x) {
    find(x);
    return value[x];
  }
  
public:
  UnionFind(int n, Abel NE = 0):par(n),siz(n,1),value(n,NE) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() { return par.size();};
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else {
      int r = find(par[x]);
      value[x] += value[par[x]];
      return par[x] = r;
    }
  }

  //where potential(y) - potential(x) = v
  void unite(int x, int y, Abel v) {
    assert(x < size());
    assert(y < size());
    v += potential(x); v -= potential(y);
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y), v = -v;
    siz[x] += siz[y];
    par[y] = x;
    value[y] = v;
  }

  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }

  Abel diff(int x, int y) {
    assert(x < size());
    assert(y < size());
    return potential(y) - potential(x);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/potentialized_unionfind.cpp"
template<typename Abel> struct UnionFind {
private:
  vector<int> par, siz;
  vector<Abel> value; //NE: neutral of abelian group
  Abel potential(int x) {
    find(x);
    return value[x];
  }
  
public:
  UnionFind(int n, Abel NE = 0):par(n),siz(n,1),value(n,NE) {
    for (int i = 0; i < n; ++i) par[i] = i;
  }
  int size() { return par.size();};
  int size(int x) {
    assert(x < size());
    return siz[find(x)];
  }

  int find(int x) { //return root
    assert(x < size());
    if (par[x] == x) return x;
    else {
      int r = find(par[x]);
      value[x] += value[par[x]];
      return par[x] = r;
    }
  }

  //where potential(y) - potential(x) = v
  void unite(int x, int y, Abel v) {
    assert(x < size());
    assert(y < size());
    v += potential(x); v -= potential(y);
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (siz[x] < siz[y]) std::swap(x, y), v = -v;
    siz[x] += siz[y];
    par[y] = x;
    value[y] = v;
  }

  bool same(int x, int y) { 
    assert(x < size());
    assert(y < size());
    return find(x) == find(y);
  }

  Abel diff(int x, int y) {
    assert(x < size());
    assert(y < size());
    return potential(y) - potential(x);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

