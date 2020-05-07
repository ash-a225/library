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


# :heavy_check_mark: tests/AOJ_DPL_1_D.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DPL_1_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:38:53+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/segment_tree_basic.cpp.html">DataStructure/segment_tree_basic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
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
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(all(b));
  b.erase(unique(all(b)), b.end()); //zaatu
  rep(i,n) {
    a[i] = lower_bound(all(b), a[i]) - b.begin();
    assert(a[i] < n);
  }
  auto f = [](ll x, ll y){ return max(x,y);};
  SegmentTree<ll> dp(n, f, 0);
  int ans = 0;
  rep(i,n) {
    int maxlen = dp.query(0,a[i]);
    if (dp.query(a[i],a[i]+1) < maxlen+1) {
      dp.set_val(a[i], maxlen+1);
      chmax(ans, maxlen+1);
    }
  }
  cout << ans << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_DPL_1_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
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
  private:
    using F = function<T(T,T)>;
    const F f;
    const T DD; // e
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
      i += n-1;
      dat[i] = x;
      while (i > 0) {    
        i = (i-1)/2;  //child->parent
        dat[i] = f(dat[i*2+1], dat[i*2+2]);
      }   
    } 
    T query(int a, int b, int k, int l, int r) { 
      if (r<=a||b<=l) return DD;
      else if (a<=l&&r<=b) return dat[k];
      else {
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return f(vl, vr);
      }
    }
    T query(int a, int b) { //[a,b)
      assert(a < n);
      assert(b <= n);
      return query(a,b,0,0,n);
    }
    T operator[](const int &k){
      return query(k, k+1);
    }
};


#line 12 "tests/AOJ_DPL_1_D.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(all(b));
  b.erase(unique(all(b)), b.end()); //zaatu
  rep(i,n) {
    a[i] = lower_bound(all(b), a[i]) - b.begin();
    assert(a[i] < n);
  }
  auto f = [](ll x, ll y){ return max(x,y);};
  SegmentTree<ll> dp(n, f, 0);
  int ans = 0;
  rep(i,n) {
    int maxlen = dp.query(0,a[i]);
    if (dp.query(a[i],a[i]+1) < maxlen+1) {
      dp.set_val(a[i], maxlen+1);
      chmax(ans, maxlen+1);
    }
  }
  cout << ans << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
