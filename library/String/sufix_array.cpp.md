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


# :heavy_check_mark: String/sufix_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/sufix_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 13:09:01+09:00




## Depends on

* :heavy_check_mark: <a href="../DataStructure/sparce_table.cpp.html">DataStructure/sparce_table.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yh_suffix_array.test.cpp.html">tests/yh_suffix_array.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SA_H
#define SA_H

//https://drken1215.hatenablog.com/entry/2019/09/16/014600
// Suffix Array ( Manber&Myers: O(n (logn)^2) )

#include "DataStructure/sparce_table.cpp"

struct suffix_array {
  private:
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    vector<int> rank_sa, tmp_rank_sa;
    vector<int> rsa;
    SparseTable<int> st;
    struct CompareSA {
      int n,k;
      const vector<int> &rank;
      CompareSA(int n, int k, const vector<int> &rank_sa):n(n),k(k),rank(rank_sa){}
      bool operator()(int i, int j) {
        if (rank[i] != rank[j]) return (rank[i] < rank[j]);
        else {
          int rank_ik = (i + k <= n ? rank[i + k] : -1);
          int rank_jk = (j + k <= n ? rank[j + k] : -1);
          return (rank_ik < rank_jk);
        }
      }
    };  
    void build() {
      int n = (int)str.size();
      sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
      for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
      sa[n] = n, rank_sa[n] = -1;
      for (int k = 1; k <= n; k *= 2) {
        CompareSA csa(n, k, rank_sa);
        sort(sa.begin(), sa.end(), csa);
        tmp_rank_sa[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
          tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
          if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
        }
        for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
      }
    }
  public:
    suffix_array(const string& str_) : str(str_) { build(); calcLCP(); }
    void init(const string& str_) { str = str_; build(); calcLCP(); }

    void calcLCP() {
      int n = (int)str.size();
      rsa.resize(n+1);
      for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
      lcp.assign(n+1,0);
      int cur = 0;
      for (int i = 0; i < n; ++i) {
        int pi = sa[rsa[i] - 1];
        if (cur > 0) --cur;
        for (; pi + cur < n && i + cur < n; ++cur) {
            if (str[pi + cur] != str[i + cur]) break;
        }
        lcp[rsa[i] - 1] = cur;
      }
      st = SparseTable<int>(lcp);
    }
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
      assert(a < (int)rsa.size());
      assert(b < (int)rsa.size());
      return st.query(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
    inline int& operator [] (int i) {
      assert(i < (int)sa.size());
      return sa[i];
    }
    void output() { //a_0 a_1 ... a_{N-2} a_{N-1}
      for (int i = 1; i < (int)sa.size(); ++i) {
        cout << sa[i] << " ";
      }
      cout << "\n";
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/sufix_array.cpp"



//https://drken1215.hatenablog.com/entry/2019/09/16/014600
// Suffix Array ( Manber&Myers: O(n (logn)^2) )

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


#line 8 "String/sufix_array.cpp"

struct suffix_array {
  private:
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    vector<int> rank_sa, tmp_rank_sa;
    vector<int> rsa;
    SparseTable<int> st;
    struct CompareSA {
      int n,k;
      const vector<int> &rank;
      CompareSA(int n, int k, const vector<int> &rank_sa):n(n),k(k),rank(rank_sa){}
      bool operator()(int i, int j) {
        if (rank[i] != rank[j]) return (rank[i] < rank[j]);
        else {
          int rank_ik = (i + k <= n ? rank[i + k] : -1);
          int rank_jk = (j + k <= n ? rank[j + k] : -1);
          return (rank_ik < rank_jk);
        }
      }
    };  
    void build() {
      int n = (int)str.size();
      sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
      for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
      sa[n] = n, rank_sa[n] = -1;
      for (int k = 1; k <= n; k *= 2) {
        CompareSA csa(n, k, rank_sa);
        sort(sa.begin(), sa.end(), csa);
        tmp_rank_sa[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
          tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
          if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
        }
        for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
      }
    }
  public:
    suffix_array(const string& str_) : str(str_) { build(); calcLCP(); }
    void init(const string& str_) { str = str_; build(); calcLCP(); }

    void calcLCP() {
      int n = (int)str.size();
      rsa.resize(n+1);
      for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
      lcp.assign(n+1,0);
      int cur = 0;
      for (int i = 0; i < n; ++i) {
        int pi = sa[rsa[i] - 1];
        if (cur > 0) --cur;
        for (; pi + cur < n && i + cur < n; ++cur) {
            if (str[pi + cur] != str[i + cur]) break;
        }
        lcp[rsa[i] - 1] = cur;
      }
      st = SparseTable<int>(lcp);
    }
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
      assert(a < (int)rsa.size());
      assert(b < (int)rsa.size());
      return st.query(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
    inline int& operator [] (int i) {
      assert(i < (int)sa.size());
      return sa[i];
    }
    void output() { //a_0 a_1 ... a_{N-2} a_{N-1}
      for (int i = 1; i < (int)sa.size(); ++i) {
        cout << sa[i] << " ";
      }
      cout << "\n";
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

