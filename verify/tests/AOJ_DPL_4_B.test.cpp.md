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


# :x: tests/AOJ_DPL_4_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DPL_4_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-17 15:20:52+09:00




## Depends on

* :x: <a href="../../library/Other/rekkyo.cpp.html">Other/rekkyo.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Other/rekkyo.cpp"

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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, k;
  ll L, R;
  cin >> n >> k >> L >> R;
  vector<item_t> A(n, item_t(0,1));
  rep(i,n) cin >> A[i].w;

  //a,b はwについて昇順
  auto a = rekkyo<item_t>({A.begin(), A.begin() + n/2});
  auto b = rekkyo<item_t>({A.begin() + n/2, A.end()});
  vector<vector<ll> > cnt1(k+1), cnt2(k+1); //cnt[i]:=i個のコインでできる値段の集合
  for (auto& e : a) {
    if (e.v <= k) cnt1[e.v].emplace_back(e.w);
  }
  for (auto& e : b) {
    if (e.v <= k) cnt2[e.v].emplace_back(e.w);
  }
  ll ans = 0;
  rep(i, k+1) {
    if (cnt1[i].size() == 0) continue;
    for (auto& e : cnt1[i]) {
      ll num = upper_bound(all(cnt2[k-i]), R-e) - lower_bound(all(cnt2[k-i]), L-e);
      ans += num;
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
#line 1 "tests/AOJ_DPL_4_B.test.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

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
#line 11 "tests/AOJ_DPL_4_B.test.cpp"

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

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, k;
  ll L, R;
  cin >> n >> k >> L >> R;
  vector<item_t> A(n, item_t(0,1));
  rep(i,n) cin >> A[i].w;

  //a,b はwについて昇順
  auto a = rekkyo<item_t>({A.begin(), A.begin() + n/2});
  auto b = rekkyo<item_t>({A.begin() + n/2, A.end()});
  vector<vector<ll> > cnt1(k+1), cnt2(k+1); //cnt[i]:=i個のコインでできる値段の集合
  for (auto& e : a) {
    if (e.v <= k) cnt1[e.v].emplace_back(e.w);
  }
  for (auto& e : b) {
    if (e.v <= k) cnt2[e.v].emplace_back(e.w);
  }
  ll ans = 0;
  rep(i, k+1) {
    if (cnt1[i].size() == 0) continue;
    for (auto& e : cnt1[i]) {
      ll num = upper_bound(all(cnt2[k-i]), R-e) - lower_bound(all(cnt2[k-i]), L-e);
      ans += num;
    }
  }
  cout << ans << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

