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


# :x: tests/AOJ_DPL_1_D2.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DPL_1_D2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-23 21:51:46+09:00




## Depends on

* :x: <a href="../../library/DP/lis.cpp.html">DP/lis.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DP/lis.cpp"

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  cout << LIS(a, true) << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_DPL_1_D2.test.cpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "DP/lis.cpp"
template<typename T>
int LIS(const vector<T> &a, bool strict = true) {
  vector<T> dp(a.size(), numeric_limits<T>::max()/2);
  for (auto&& x : a) {
    if (strict) *lower_bound(dp.begin(), dp.end(), x) = x;
    else *upper_bound(dp.begin(), dp.end(), x) = x;
  }
  int len = lower_bound(dp.begin(), dp.end(), numeric_limits<T>::max()/2) - dp.begin();
  return len;
}
#line 11 "tests/AOJ_DPL_1_D2.test.cpp"

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  cout << LIS(a, true) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

