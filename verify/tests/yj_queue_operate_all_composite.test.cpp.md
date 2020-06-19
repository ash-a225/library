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


# :heavy_check_mark: tests/yj_queue_operate_all_composite.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_queue_operate_all_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 12:15:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/queue_aggression.cpp.html">DataStructure/queue_aggression.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/modint.cpp.html">Math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "Math/modint.cpp"
#include "DataStructure/queue_aggression.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int q;
  cin >> q;
  using mint = modint<998244353>;
  using P = pair<mint, mint>;
  auto f = [](P a, P b) {
    return P(a.first*b.first, b.first*a.second + b.second); //合成
  };
  queue_aggression<P, decltype(f)> que(f);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      P p; cin >> p.first.x >> p.second.x;
      que.push(p);
    }
    else if (com == 1) {
      que.pop();
    }
    else {
      mint x; cin >> x.x;
      if (!que.empty()) {
        P p = que.fold_all();
        mint res = p.first*x + p.second;
        cout << res.x << "\n";
      }
      else cout << x.x << "\n";
    }
  }  
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_queue_operate_all_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
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
#line 1 "DataStructure/queue_aggression.cpp"
template<class T, class F> struct queue_aggression {
private:
  // using F = function<T(T,T)>;
  struct node {
    T val, sum;
    node(const T &val, const T &sum):val(val),sum(sum){}
  };
  const F f;
  stack<node> front_stack, back_stack;

public:
  queue_aggression(const F &f):f(f){}
  bool empty() const { return front_stack.empty() && back_stack.empty();}
  int size() const { return front_stack.size() + back_stack.size();}

  T fold_all() {
    assert(!empty());
    if (front_stack.empty()) return back_stack.top().sum;
    else if (back_stack.empty()) return front_stack.top().sum;
    else return f(front_stack.top().sum, back_stack.top().sum);
  }
  void push(const T &x) {
    if (back_stack.empty()) back_stack.emplace(x, x);
    else {
      T s = f(back_stack.top().sum, x);
      back_stack.emplace(x, s);
    }
  }
  void pop() {
    assert(!empty());
    if (front_stack.empty()) {
      front_stack.emplace(back_stack.top().val, back_stack.top().val);
      back_stack.pop();
      while(!back_stack.empty()) {
        T s = f(back_stack.top().val, front_stack.top().sum);
        front_stack.emplace(back_stack.top().val, s);
        back_stack.pop();
      }
    }
    front_stack.pop();
  }
};
//https://scrapbox.io/data-structures/Sliding_Window_Aggregation
#line 12 "tests/yj_queue_operate_all_composite.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int q;
  cin >> q;
  using mint = modint<998244353>;
  using P = pair<mint, mint>;
  auto f = [](P a, P b) {
    return P(a.first*b.first, b.first*a.second + b.second); //合成
  };
  queue_aggression<P, decltype(f)> que(f);
  while(q--) {
    int com; cin >> com;
    if (com == 0) {
      P p; cin >> p.first.x >> p.second.x;
      que.push(p);
    }
    else if (com == 1) {
      que.pop();
    }
    else {
      mint x; cin >> x.x;
      if (!que.empty()) {
        P p = que.fold_all();
        mint res = p.first*x + p.second;
        cout << res.x << "\n";
      }
      else cout << x.x << "\n";
    }
  }  
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

