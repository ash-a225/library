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


# :x: tests/yj_range_affine_range_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 18:04:16+09:00




## Depends on

* :question: <a href="../../library/DataStructure/segment_tree_lazy.cpp.html">DataStructure/segment_tree_lazy.cpp</a>
* :question: <a href="../../library/Math/modint2.cpp.html">Math/modint2.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/segment_tree_lazy.cpp"
#include "Math/modint2.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<mint> v(n);
  rep(i,n) cin >> v[i];
  auto f = [](mint a, mint b) {return a+b;};
  using P = pair<mint, mint>;
  auto g = [](mint a, P p) {return p.first*a + p.second;}; //要素への作用
  auto h = [](P a, P b){ //合成
    return P(a.first*b.first, b.first*a.second + b.second);
  };
  SegmentTree<mint,P> lazy(n, f, g, h, mint(0), P(mint(1),mint(0)));
  lazy.build(n, v);
  rep(_,q) {
    int com;
    cin >> com;
    if (com == 0) {
      int l,r;
      cin >> l >> r;
      P p;
      cin >> p.first >> p.second;
      lazy.update(l, r, p);
    }
    else {
      int l,r;
      cin >> l >> r;
      mint res = lazy.query(l,r);
      cout << res << "\n";
    }
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_range_affine_range_sum.test.cpp"
#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

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
    T update(int a,int b,E x,int k,int l,int r){
      eval(r-l,k);
      if(r<=a||b<=l) return dat[k];
      if(a<=l&&r<=b){
        laz[k]=h(laz[k],x);
        return g(dat[k],p(laz[k],r-l));
      }
      return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),update(a,b,x,k*2+2,(l+r)/2,r));
    }
    T update(int a,int b,E x){
      assert(a < n);
      assert(b <= n);
      return update(a,b,x,0,0,n);
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


#line 1 "Math/modint2.cpp"



// const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
  bool operator==(const mint rhs) const { return x == rhs.x; }
  bool operator!=(const mint rhs) const { return x != rhs.x; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


#line 13 "tests/yj_range_affine_range_sum.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, q;
  cin >> n >> q;
  vector<mint> v(n);
  rep(i,n) cin >> v[i];
  auto f = [](mint a, mint b) {return a+b;};
  using P = pair<mint, mint>;
  auto g = [](mint a, P p) {return p.first*a + p.second;}; //要素への作用
  auto h = [](P a, P b){ //合成
    return P(a.first*b.first, b.first*a.second + b.second);
  };
  SegmentTree<mint,P> lazy(n, f, g, h, mint(0), P(mint(1),mint(0)));
  lazy.build(n, v);
  rep(_,q) {
    int com;
    cin >> com;
    if (com == 0) {
      int l,r;
      cin >> l >> r;
      P p;
      cin >> p.first >> p.second;
      lazy.update(l, r, p);
    }
    else {
      int l,r;
      cin >> l >> r;
      mint res = lazy.query(l,r);
      cout << res << "\n";
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

