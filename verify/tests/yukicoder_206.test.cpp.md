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


# :heavy_check_mark: tests/yukicoder_206.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yukicoder_206.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 23:06:01+09:00


* see: <a href="https://yukicoder.me/problems/no/206">https://yukicoder.me/problems/no/206</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Math/fft.cpp.html">Math/fft.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/206"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/fft.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int l,m,n;
  cin >> l >> m >> n;
  vector<ll> a(n,0), b(n,0);
  rep(i,l) {
    int x;
    cin >> x; x--;
    a[x] = 1;
  }
  rep(i,m) {
    int x;
    cin >> x;
    b[n-x] = 1;
  }
  int q;
  cin >> q;
  auto c = FFT::convolve(a, b);
  rep(i, q) {
    cout << c[n-1+i] << endl;
  }
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yukicoder_206.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/206"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Math/fft.cpp"
namespace FFT {
  const double PI = acos(double(-1));
  using cmplx = complex<double>;

  unsigned bitreverse32(unsigned x) {
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
  }
  void fft(vector<cmplx> &A, const int k, bool inverse = false){
    if (k == 0) return;
    for (int i = 1; i < (1<<k); ++i) { 
      int ind = bitreverse32(i) >> (32-k);
      if (ind > i) {
        std::swap(A[i], A[ind]);
      }  
    }
    for (int i = 1; i <= k; ++i) { //N = (1<<i)
      cmplx w = polar(1.0, (inverse ? -1 : 1)*2.0*PI/(1<<i));
      for (int j = 0; j < (1<<(k-i)); ++j) { 
        cmplx base = 1;
        for (int l = 0; l < (1<<(i-1)); ++l) { //l = 0,1...N/2-1
          cmplx s = A[(1<<i)*j + l];
          cmplx t = A[(1<<i)*j + l + (1<<(i-1))] * base;
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
    vector<cmplx> CA(1<<k,0), CB(1<<k,0);
    for (int i = 0; i < (int)A.size(); ++i) CA[i] = A[i];
    for (int i = 0; i < (int)B.size(); ++i) CB[i] = B[i];
    fft(CA, k, false);
    fft(CB, k, false);
    vector<cmplx> CC(1<<k);
    for (int i = 0; i < (1<<k); ++i) {
      CC[i] = CA[i] * CB[i];
    }
    fft(CC, k, true);
    vector<ll> C(siz);
    for (int i = 0; i < siz; ++i) {
      C[i] = (ll)(real(CC[i]) + 0.5);
    }
    return C;
  }
};
#line 12 "tests/yukicoder_206.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int l,m,n;
  cin >> l >> m >> n;
  vector<ll> a(n,0), b(n,0);
  rep(i,l) {
    int x;
    cin >> x; x--;
    a[x] = 1;
  }
  rep(i,m) {
    int x;
    cin >> x;
    b[n-x] = 1;
  }
  int q;
  cin >> q;
  auto c = FFT::convolve(a, b);
  rep(i, q) {
    cout << c[n-1+i] << endl;
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
