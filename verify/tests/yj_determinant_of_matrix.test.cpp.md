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


# :heavy_check_mark: tests/yj_determinant_of_matrix.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_determinant_of_matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 23:06:01+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Math/matrix.cpp.html">Math/matrix.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/modint.cpp.html">Math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/modint.cpp"
#include "Math/matrix.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  using mint = modint<998244353>;
  Matrix<mint> A(n,n);
  rep(i,n) rep(j,n) {
    cin >> A[i][j].x;
  }
  mint det = A.determinant();
  cout << det.x << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_determinant_of_matrix.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
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
#line 1 "Math/matrix.cpp"
/*
https://ei1333.github.io/library/library/math/matrix/matrix.cpp.html
*/
template<typename E>
struct Matrix {
  vector<vector<E> > A;
  Matrix() {}
  Matrix(int n, int m):A(n,vector<E>(m,0)) {}
  Matrix(int n):A(n,vector<E>(n,0)) {}
  int height() const { return A.size();}
  int width() const { return A[0].size();}
  vector<E>& operator[](int k){ return A.at(k);}
  const vector<E>& operator[](int k) const { return A.at(k);}
  Matrix I(int n) {
    Matrix mat(n);
    for (int i = 0; i < n; ++i) mat[i][i] = 1;
    return mat;
  }
  Matrix T() {
    int n = height(), m = width();
    vector<vector<E> > B = A;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) swap(B[i][j],B[j][i]);
    return B;
  }
  Matrix& operator+=(const Matrix B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) A[i][j] += B[i][j];
    return *this;
  }
  Matrix& operator-=(const Matrix B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) A[i][j] -= B[i][j];
    return *this;
  }
  Matrix& operator*=(const Matrix B) { 
    int n = height(), r = width(), m = B.width();
    assert(r == B.height());
    vector<vector<E> > res(n,vector<E>(m,0));
    for(int i = 0; i < n; ++i){
      for(int k = 0; k < r; ++k){
        for(int j = 0; j < m; ++j){
          res[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    swap(A,res);
    return *this;
  }
  Matrix operator+(const Matrix B) const { return Matrix(*this) += B;}
  Matrix operator-(const Matrix B) const { return Matrix(*this) -= B;}
  Matrix operator*(const Matrix B) const { return Matrix(*this) *= B;}
  Matrix pow(ll t) const {
    if (!t) return 1;
    Matrix a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  E determinant() {
    assert(width() == height());
    Matrix B(*this);
    E res = 1;
    int n = height();
    for(int i = 0; i < n; ++i) {
      int idx = -1;
      for(int j = i; j < n; ++j) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return 0;
      if(i != idx) {
        swap(B[i], B[idx]);
        res *= -1;
      }
      res *= B[i][i];
      E vv = B[i][i];
      for(int j = 0; j < n; ++j) {
        B[i][j] /= vv;
      }
      for(int j = i+1; j < n; ++j) {
        E a = B[j][i];
        for(int k = 0; k < n; k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return res;
  }
  bool operator==(const Matrix rhs) const { return A == rhs.A; }
  bool operator!=(const Matrix rhs) const { return A != rhs.A; }
};
#line 13 "tests/yj_determinant_of_matrix.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  using mint = modint<998244353>;
  Matrix<mint> A(n,n);
  rep(i,n) rep(j,n) {
    cin >> A[i][j].x;
  }
  mint det = A.determinant();
  cout << det.x << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

