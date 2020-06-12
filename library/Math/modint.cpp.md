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


# :heavy_check_mark: Math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 23:06:01+09:00




## Required by

* :heavy_check_mark: <a href="ntt.cpp.html">Math/ntt.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yj_convolution.test.cpp.html">tests/yj_convolution.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_convolution1000000007.test.cpp.html">tests/yj_convolution1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yj_determinant_of_matrix.test.cpp.html">tests/yj_determinant_of_matrix.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/tests/yukicoder_1073.test.cpp.html">tests/yukicoder_1073.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

