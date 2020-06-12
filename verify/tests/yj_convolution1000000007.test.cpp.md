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


# :heavy_check_mark: tests/yj_convolution1000000007.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_convolution1000000007.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 23:06:01+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod_1000000007">https://judge.yosupo.jp/problem/convolution_mod_1000000007</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Math/garner.cpp.html">Math/garner.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/modint.cpp.html">Math/modint.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/ntt.cpp.html">Math/ntt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/ntt.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  auto ans = ntt_convolve(a, b, 1000000007);
  rep(i,n+m-1) {
    cout << ans[i] << "\n";
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_convolution1000000007.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Math/modint.cpp"
template <ll Modulo> struct modint {
private:
  static constexpr ll mod = Modulo;
public:
  ll x;
  modint(ll x=0):x((x%mod+mod)%mod){}
  modint operator-() const { return modint(-x);}
  modint& operator+=(const modint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator-=(const modint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  modint& operator*=(const modint a) { (x *= a.x) %= mod; return *this;}
  modint operator+(const modint a) const { return modint(*this) += a;}
  modint operator-(const modint a) const { return modint(*this) -= a;}
  modint operator*(const modint a) const { return modint(*this) *= a;}
  modint pow(ll t) const {
    if (!t) return 1;
    modint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  modint inv() const { return pow(mod-2);}
  modint& operator/=(const modint a) { return *this *= a.inv();}
  modint operator/(const modint a) const { return modint(*this) /= a;}
  bool operator==(const modint rhs) const { return x == rhs.x; }
  bool operator!=(const modint rhs) const { return x != rhs.x; }
  bool operator<(const modint &a) const{ return x<a.x;};
  static ll get_mod() { return mod; }
};
#line 1 "Math/garner.cpp"
struct Garner {
private:
  vector<ll> r, m;
  ll extgcd(ll a, ll b, ll& x, ll& y) {
    for (ll u=y=1, v=x=0; a; ) {
      ll q = b / a;
      swap(x -= q*u, u);
      swap(y -= q*v, v);
      swap(b -= q*a, a);
    }
    return b;
  }
  inline ll mod_inv(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
  }

public:
  void push(ll v, ll mod) {
    r.emplace_back(v);
    m.emplace_back(mod);
  }
  ll get(ll mod) {
    r.emplace_back(0);
    m.emplace_back(mod);
    vector<ll> coffs(r.size(),1), constants(r.size(),0);
    for (int i = 0; i < (int)r.size()-1; ++i) {
      // solve "coffs[i] * v + constants[i] = r[i] (mod m[i])"
      ll v = (r[i] - constants[i]) * mod_inv(coffs[i], m[i]) % m[i];
      if (v < 0) v += m[i];
      for (int j = i+1; j < (int)r.size(); ++j) {
        (constants[j] += coffs[j] * v) %= m[j];
        (coffs[j] *= m[i]) %= m[j];
      }
    } 
    return constants.back();
  }
};
#line 3 "Math/ntt.cpp"

template<typename ModInt> struct NTT {
private:
  using mi = ModInt;

  static mi primitive_root() {
    ll p = mi{}.get_mod();
    if (p == 167772161) return 3;
    else if (p == 469762049) return 3;
    else if (p == 1224736769) return 3;
    else if (p == 998244353) return 3;
    return 0;
  }
  unsigned bitreverse32(unsigned x) {
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
  }

public:
  void ntt(vector<mi> &A, const int k, bool inverse = false) {
    if (k == 0) return;
    for (int i = 1; i < (1<<k); ++i) { 
      int ind = bitreverse32(i) >> (32-k);
      if (ind > i) {
        std::swap(A[i], A[ind]);
      }  
    }
    for (int i = 1; i <= k; ++i) { //N = (1<<i)
      mi w = primitive_root().pow((mi(-1)/(1<<i)).x);
      if (inverse) w = mi(1) / w;
      for (int j = 0; j < (1<<(k-i)); ++j) { 
        mi base = 1;
        for (int l = 0; l < (1<<(i-1)); ++l) { //l = 0,1...N/2-1
          mi s = A[(1<<i)*j + l];
          mi t = A[(1<<i)*j + l + (1<<(i-1))] * base;
          A[(1<<i)*j + l] = s + t;
          A[(1<<i)*j + l + (1<<(i-1))] = s - t;
          base *= w;
        }
      }
    }
    if (inverse) {
      for (int i = 0; i < (1<<k); ++i) A[i] /= (1<<k);
    }
  }

  vector<ll> convolve(const vector<ll>& A, const vector<ll>& B){
    int siz = A.size() + B.size() - 1;
    int k = 0;
    while (siz >= (1<<k)) k++;
    vector<mi> CA(1<<k,0), CB(1<<k,0);
    for (int i = 0; i < (int)A.size(); ++i) CA[i] = A[i];
    for (int i = 0; i < (int)B.size(); ++i) CB[i] = B[i];
    ntt(CA, k, false);
    ntt(CB, k, false);
    vector<mi> CC(1<<k);
    for (int i = 0; i < (1<<k); ++i) {
      CC[i] = CA[i] * CB[i];
    }
    ntt(CC, k, true);
    vector<ll> C(siz);
    for (int i = 0; i < siz; ++i) C[i] = CC[i].x;
    return C;
  }
};

vector<ll> ntt_convolve(const vector<ll> &A, const vector<ll> &B, const ll mod = 1224736769) {
  if (mod == 998244353) {
    NTT<modint<998244353> > ntt;
    return ntt.convolve(A,B);
  }
  NTT<modint<167772161> > ntt1;
  NTT<modint<469762049> > ntt2;
  NTT<modint<1224736769> > ntt3;
  vector<ll> C1 = ntt1.convolve(A,B);
  vector<ll> C2 = ntt2.convolve(A,B);
  vector<ll> C3 = ntt3.convolve(A,B);
  vector<ll> res(C1.size());
  for (int i = 0; i < (int)C1.size(); ++i) {
    Garner garner;
    garner.push(C1[i], 167772161);
    garner.push(C2[i], 469762049);
    garner.push(C3[i], 1224736769);
    res[i] = garner.get(mod);
  }
  return res;
}

//https://naoyat.hatenablog.jp/entry/DFT-and-NTT#f-8ef02af0
#line 12 "tests/yj_convolution1000000007.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  auto ans = ntt_convolve(a, b, 1000000007);
  rep(i,n+m-1) {
    cout << ans[i] << "\n";
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

