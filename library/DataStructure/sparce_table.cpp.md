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


# :heavy_check_mark: DataStructure/sparce_table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/sparce_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 13:09:01+09:00




## Required by

* :heavy_check_mark: <a href="../String/sufix_array.cpp.html">String/sufix_array.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yh_suffix_array.test.cpp.html">tests/yh_suffix_array.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_static_rmq2.test.cpp.html">tests/yj_static_rmq2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef D_LCA_H
#define D_LCA_H

//https://ei1333.github.io/luzhiled/snippets/structure/sparse-table.html

template<typename T>
struct SparseTable {
  private:
    vector<vector<T> > st;
    vector<int> lookup;
  public:
    SparseTable(){}
    SparseTable(const vector<T> &v) {
      int b = 0;
      while((1<<b) <= (int)v.size()) ++b;
      st.assign(b, vector<T>(1<<b));
      for(int i = 0; i < (int)v.size(); i++) {
        st[0][i] = v[i];
      }
      for(int i = 1; i < b; i++) {
        for(int j = 0; j+(1<<i) <= (1<<b); j++) {
          st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
      }
      lookup.resize(v.size()+1);
      for(int i = 2; i < (int)lookup.size(); i++) {
        lookup[i] = lookup[i>>1] + 1;
      }
    }
    inline T query(int l, int r) { //[l,r)
      int b = lookup[r-l];
      return min(st[b][l], st[b][r-(1<<b)]);
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/sparce_table.cpp"



//https://ei1333.github.io/luzhiled/snippets/structure/sparse-table.html

template<typename T>
struct SparseTable {
  private:
    vector<vector<T> > st;
    vector<int> lookup;
  public:
    SparseTable(){}
    SparseTable(const vector<T> &v) {
      int b = 0;
      while((1<<b) <= (int)v.size()) ++b;
      st.assign(b, vector<T>(1<<b));
      for(int i = 0; i < (int)v.size(); i++) {
        st[0][i] = v[i];
      }
      for(int i = 1; i < b; i++) {
        for(int j = 0; j+(1<<i) <= (1<<b); j++) {
          st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
      }
      lookup.resize(v.size()+1);
      for(int i = 2; i < (int)lookup.size(); i++) {
        lookup[i] = lookup[i>>1] + 1;
      }
    }
    inline T query(int l, int r) { //[l,r)
      int b = lookup[r-l];
      return min(st[b][l], st[b][r-(1<<b)]);
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

