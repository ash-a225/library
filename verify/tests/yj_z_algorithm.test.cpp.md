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


# :heavy_check_mark: tests/yj_z_algorithm.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/yj_z_algorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 16:00:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/z_algorithm.cpp.html">String/z_algorithm.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#include "String/z_algorithm.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string str;
  cin >> str;
  z_array a; //LCP
  a.build(str);
  rep(i,(int)str.size()) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/yj_z_algorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }

#line 1 "String/z_algorithm.cpp"



struct z_array {
  vector<int> prefix;
  void build(const string &s) {
    prefix.assign(s.size(),0);
    for(int i=1, j=0; i < (int)s.size(); ++i) {
      if(i+prefix[i-j] < j+prefix[j]) {
        prefix[i] = prefix[i-j];
      }
      else {
        int k = std::max(0,j+prefix[j]-i);
        while(i+k < (int)s.size() && s[k] == s[i+k]) ++k;
        prefix[i] = k;
        j = i;
      }
    }
    prefix[0] = s.size();
  }
  int operator[](const int k) const{ return prefix[k];}
  int size(){ return prefix.size();}
};


#line 12 "tests/yj_z_algorithm.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string str;
  cin >> str;
  z_array a; //LCP
  a.build(str);
  rep(i,(int)str.size()) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

