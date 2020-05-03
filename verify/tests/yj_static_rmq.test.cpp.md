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


# :heavy_check_mark: tests/yj_static_rmq.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_static_rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 18:08:18+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/segment_tree_basic.cpp.html">DataStructure/segment_tree_basic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_basic.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  auto f = [](ll x, ll y){ return min(x,y);};
  const ll INF = 1LL<<30; //60とかにするとバグる????
  SegmentTree<ll> rmq(n, f, INF);
  rmq.build(n, a);
  rep(_,q) {
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l,r) << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_static_rmq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "DataStructure/segment_tree_basic.cpp"



//https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
//https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver
//http://tsutaj.hatenablog.com/entry/2017/03/29/204841

template<typename T> 
struct SegmentTree {
  using F = function<T(T,T)>;
  private:
    int n;
    vector<T> dat;
    const T dd; //mininum etc.
    const F f;
  public:
    SegmentTree(int n_, const F f, const T dd):f(f),dd(dd) { init(n_);}
    void init(int n_) {
      n = 1; while(n < n_) n *= 2;
      dat.clear();
      dat.resize(2*n-1, dd);
    }
    void build(int n_, vector<T> v) {
      for(int i=0; i<n_; ++i) dat[i+n-1] = v[i];
      for(int i=n-2; i>=0; --i) dat[i] = f(dat[2*i+1], dat[2*i+2]);
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
      if (r <= a || b <= l) return dd;
      else if (a <= l && r <= b) return dat[k];
      else {
        int vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
      }
    }
};


#line 12 "tests/yj_static_rmq.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  auto f = [](ll x, ll y){ return min(x,y);};
  const ll INF = 1LL<<30; //60とかにするとバグる????
  SegmentTree<ll> rmq(n, f, INF);
  rmq.build(n, a);
  rep(_,q) {
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l,r) << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

