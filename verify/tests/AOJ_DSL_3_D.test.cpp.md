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


# :heavy_check_mark: tests/AOJ_DSL_3_D.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_DSL_3_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 13:58:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/queue_aggression.cpp.html">DataStructure/queue_aggression.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "DataStructure/queue_aggression.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, L;
	cin >> n >> L;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
  auto f = [](ll a, ll b){ return min(a,b);};
  queue_aggression<ll, decltype(f)> que(f);
	rep(i,L) que.push(a[i]);
  rep(i,n-L+1) {
    if (i) cout << " ";
    cout << que.fold_all();
    que.pop();
    que.push(a[i+L]);
  }
  cout << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_DSL_3_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

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
#line 11 "tests/AOJ_DSL_3_D.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, L;
	cin >> n >> L;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
  auto f = [](ll a, ll b){ return min(a,b);};
  queue_aggression<ll, decltype(f)> que(f);
	rep(i,L) que.push(a[i]);
  rep(i,n-L+1) {
    if (i) cout << " ";
    cout << que.fold_all();
    que.pop();
    que.push(a[i+L]);
  }
  cout << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

