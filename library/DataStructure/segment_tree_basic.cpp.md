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


# :heavy_check_mark: DataStructure/segment_tree_basic.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/segment_tree_basic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 00:59:00+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DSL_2_A.test.cpp.html">tests/AOJ_DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_point_set_range_ccomposite.test.cpp.html">tests/yj_point_set_range_ccomposite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_static_rmq.test.cpp.html">tests/yj_static_rmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SEG_BASIC_H
#define SEG_BASIC_H

//https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
//https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver
//http://tsutaj.hatenablog.com/entry/2017/03/29/204841

template<typename T> 
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    const F f;
    const T DD; //mininum etc.
    int n;
    vector<T> dat;
  public:
    SegmentTree(int n_, const F func, T dd):f(func),DD(dd){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    void set_val(int i, T x){
      assert(i < n);
      i += n - 1;
      dat[i] = x;
      while (i > 0) {    
        i = (i-1)/2;  //child->parent
        dat[i] = f(dat[i*2+1], dat[i*2+2]);
      }   
    } 
    T query(int a, int b) { //[a,b) 改善のよちあり
      assert(a < n);
      assert(b <= n);
      return query_sub(a, b, 0, 0, n);
    }
    T query_sub(int a, int b, int k, int l, int r) { 
      if (r <= a || b <= l) return DD;
      else if (a <= l && r <= b) return dat[k];
      else {
        T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
        T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
      }
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/segment_tree_basic.cpp"



//https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
//https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver
//http://tsutaj.hatenablog.com/entry/2017/03/29/204841

template<typename T> 
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    const F f;
    const T DD; //mininum etc.
    int n;
    vector<T> dat;
  public:
    SegmentTree(int n_, const F func, T dd):f(func),DD(dd){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    void set_val(int i, T x){
      assert(i < n);
      i += n - 1;
      dat[i] = x;
      while (i > 0) {    
        i = (i-1)/2;  //child->parent
        dat[i] = f(dat[i*2+1], dat[i*2+2]);
      }   
    } 
    T query(int a, int b) { //[a,b) 改善のよちあり
      assert(a < n);
      assert(b <= n);
      return query_sub(a, b, 0, 0, n);
    }
    T query_sub(int a, int b, int k, int l, int r) { 
      if (r <= a || b <= l) return DD;
      else if (a <= l && r <= b) return dat[k];
      else {
        T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
        T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
      }
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

