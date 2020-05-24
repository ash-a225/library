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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Graph/doubling/doubling.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0cbea2cc80c9b4f2b5eca7444eaf8a7f">Graph/doubling</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/doubling/doubling.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 18:53:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//to[i][v] vの2^i個上の頂点
template<typename T>
struct Doubling {
  private:
    const vector<vector<int> > &G;
    vector<vector<int> > to;
    vector<vector<T> > sum_w, min_w;
  public:
    Doubling(const vector<pair<int,T> > &G):G(G){};
    void build(ll max_k) {
      int k = 1;
      while ((1LL<<k) <= max_k) k++;
      int n = G.size();
      to.assign(k, vector<int>(n,-1));
      sum_w.assign(k, vector<T>(n,0));
      min_w.assign(k, vector<T>(n,numeric_limits<T>::max()));
      for(int i=0; i<k-1; ++i) {
        for(int v=0: v<n; ++v) {
          if (to[i][v] < 0) to[i+1][v] = -1;
          else {
            to[i+1][v] = to[i][to[i][v]];
            sum_w[i+1][v] = sum_w[i][v] + sum_w[i][to[i][v]];
            min_w[i+1][v] = min(min_w[i][v], min_w[i][to[i][v]]);
          }
        }
      }
    }
    int get_i(int i, ll k) { //iのk個先
      assert(i < (int)G.size());
      int ind = i;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) ind = to[j][ind];
      }
      return ind;
    }
    T get_sum_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll sum = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          sum += sum_w[j][ind];
          ind = to[j][ind];
        }
      }
      return sum;
    }
    T get_min_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll mini = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          chmin(mini, min_w[j][ind]);
          ind = to[j][ind];
        }
      }
      return mini;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/doubling/doubling.cpp"
//to[i][v] vの2^i個上の頂点
template<typename T>
struct Doubling {
  private:
    const vector<vector<int> > &G;
    vector<vector<int> > to;
    vector<vector<T> > sum_w, min_w;
  public:
    Doubling(const vector<pair<int,T> > &G):G(G){};
    void build(ll max_k) {
      int k = 1;
      while ((1LL<<k) <= max_k) k++;
      int n = G.size();
      to.assign(k, vector<int>(n,-1));
      sum_w.assign(k, vector<T>(n,0));
      min_w.assign(k, vector<T>(n,numeric_limits<T>::max()));
      for(int i=0; i<k-1; ++i) {
        for(int v=0: v<n; ++v) {
          if (to[i][v] < 0) to[i+1][v] = -1;
          else {
            to[i+1][v] = to[i][to[i][v]];
            sum_w[i+1][v] = sum_w[i][v] + sum_w[i][to[i][v]];
            min_w[i+1][v] = min(min_w[i][v], min_w[i][to[i][v]]);
          }
        }
      }
    }
    int get_i(int i, ll k) { //iのk個先
      assert(i < (int)G.size());
      int ind = i;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) ind = to[j][ind];
      }
      return ind;
    }
    T get_sum_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll sum = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          sum += sum_w[j][ind];
          ind = to[j][ind];
        }
      }
      return sum;
    }
    T get_min_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll mini = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          chmin(mini, min_w[j][ind]);
          ind = to[j][ind];
        }
      }
      return mini;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

