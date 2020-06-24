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


# :heavy_check_mark: tests/AOJ_DPL_1_H.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DPL_1_H.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 13:32:51+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Other/item_t.cpp.html">Other/item_t.cpp</a>
* :heavy_check_mark: <a href="../../library/Other/rekkyo.cpp.html">Other/rekkyo.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=ja"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Other/item_t.cpp"
#include "Other/rekkyo.cpp"

int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<item_t> item(n);
  rep(i,n) cin >> item[i].v >> item[i].w;
  auto a = rekkyo<item_t>({item.begin(), item.begin() + n/2}); //半分全列挙
  auto b = rekkyo<item_t>({item.begin() + n/2, item.end()}); //wについて昇順
  ll maxv = 0;
  for (auto &x : b) { //x.v <- x.w以下で達成できる価値の最大値
    chmax(maxv, x.v);
    x.v = maxv;
  }
  reverse(all(a));
  ll ans = 0;
  int r = 0;
  for (auto &x : a) {
    while (r+1 < (int)b.size() && x.w + b[r+1].w <= W) r++;
    if (x.w + b[r].w > W) continue;
    chmax(ans, x.v + b[r].v);
  }
  cout << ans << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_DPL_1_H.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H&lang=ja"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,m,n) for (int i = m; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template<class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "Other/item_t.cpp"
struct item_t {
  ll w, v;
  item_t(ll w, ll v):w(w),v(v){}
  item_t():w(0),v(0){}
  void operator+=(const item_t &r) {
    w += r.w;
    v += r.v;
  }
  bool operator<(const item_t &r) const { return w < r.w; }
};
#line 1 "Other/rekkyo.cpp"
template<class T>
vector<T> rekkyo(vector<T> item) {
  vector<T> a(1);
  for (auto i : item) {
    vector<T> b = a, c;
    for (auto &e : b) {
      e += i;
    }
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));
    std::swap(a,c);
  }
  return a;
}
// O(2^n)で全列挙
#line 13 "tests/AOJ_DPL_1_H.test.cpp"

int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<item_t> item(n);
  rep(i,n) cin >> item[i].v >> item[i].w;
  auto a = rekkyo<item_t>({item.begin(), item.begin() + n/2}); //半分全列挙
  auto b = rekkyo<item_t>({item.begin() + n/2, item.end()}); //wについて昇順
  ll maxv = 0;
  for (auto &x : b) { //x.v <- x.w以下で達成できる価値の最大値
    chmax(maxv, x.v);
    x.v = maxv;
  }
  reverse(all(a));
  ll ans = 0;
  int r = 0;
  for (auto &x : a) {
    while (r+1 < (int)b.size() && x.w + b[r+1].w <= W) r++;
    if (x.w + b[r].w > W) continue;
    chmax(ans, x.v + b[r].v);
  }
  cout << ans << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

