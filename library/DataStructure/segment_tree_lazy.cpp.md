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


# :question: DataStructure/segment_tree_lazy.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/segment_tree_lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:17:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/AOJ_DSL_2_G.test.cpp.html">tests/AOJ_DSL_2_G.test.cpp</a>
* :x: <a href="../../verify/tests/yj_range_affine_range_sum.test.cpp.html">tests/yj_range_affine_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SEG_BASIC_H
#define SEG_BASIC_H

template<typename T,typename E> 
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    using P = function<E(E,int)>;
    const F f;
    const G g;
    const H h;
    const P p;
    const T DD; // e
    const E DE;
    int n;
    vector<T> dat;
    vector<E> laz;
  public:
    SegmentTree(int n_,F f,G g,H h,T dd,E de,P p=[](E a,int b){return a;}):
    f(f),g(g),h(h),p(p),DD(dd),DE(de){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
      laz.clear();
      laz.resize(2*n-1, DE);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    inline void eval(int len,int k){
      if(laz[k]==DE) return;
      if(k*2+1<n*2-1){
        laz[k*2+1]=h(laz[k*2+1],laz[k]);
        laz[k*2+2]=h(laz[k*2+2],laz[k]);
      }
      dat[k]=g(dat[k],p(laz[k],len));
      laz[k]=DE;
    }
    void update(int a,int b,E x,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return;
      if(a<=l&&r<=b){
        laz[k]=h(laz[k],x);
        eval(r-l,k);
        return;
      }
      update(a,b,x,k*2+1,l,(l+r)/2);
      update(a,b,x,k*2+2,(l+r)/2,r);
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
    void update(int a,int b,E x){
      assert(a < n);
      assert(b <= n);
      update(a,b,x,0,0,n);
    }
    T query(int a,int b,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return DD;
      if(a<=l&&r<=b) return dat[k];
      T vl=query(a,b,k*2+1,l,(l+r)/2);
      T vr=query(a,b,k*2+2,(l+r)/2,r);
      return f(vl,vr);
    }
    T query(int a,int b){
      assert(a < n);
      assert(b <= n);
      return query(a,b,0,0,n);
    }
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/segment_tree_lazy.cpp"



template<typename T,typename E> 
struct SegmentTree {
  private:
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    using P = function<E(E,int)>;
    const F f;
    const G g;
    const H h;
    const P p;
    const T DD; // e
    const E DE;
    int n;
    vector<T> dat;
    vector<E> laz;
  public:
    SegmentTree(int n_,F f,G g,H h,T dd,E de,P p=[](E a,int b){return a;}):
    f(f),g(g),h(h),p(p),DD(dd),DE(de){ init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, DD);
      laz.clear();
      laz.resize(2*n-1, DE);
    }
    void build(int n_, vector<T> v) {
      assert(n_ <= n);
      for(int i=0;i<n_;++i) dat[i+n-1] = v[i];
      for(int i=n-2;i>=0;--i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
    }
    inline void eval(int len,int k){
      if(laz[k]==DE) return;
      if(k*2+1<n*2-1){
        laz[k*2+1]=h(laz[k*2+1],laz[k]);
        laz[k*2+2]=h(laz[k*2+2],laz[k]);
      }
      dat[k]=g(dat[k],p(laz[k],len));
      laz[k]=DE;
    }
    void update(int a,int b,E x,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return;
      if(a<=l&&r<=b){
        laz[k]=h(laz[k],x);
        eval(r-l,k);
        return;
      }
      update(a,b,x,k*2+1,l,(l+r)/2);
      update(a,b,x,k*2+2,(l+r)/2,r);
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
    void update(int a,int b,E x){
      assert(a < n);
      assert(b <= n);
      update(a,b,x,0,0,n);
    }
    T query(int a,int b,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return DD;
      if(a<=l&&r<=b) return dat[k];
      T vl=query(a,b,k*2+1,l,(l+r)/2);
      T vr=query(a,b,k*2+2,(l+r)/2,r);
      return f(vl,vr);
    }
    T query(int a,int b){
      assert(a < n);
      assert(b <= n);
      return query(a,b,0,0,n);
    }
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

