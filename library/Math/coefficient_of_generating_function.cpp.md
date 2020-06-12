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


# :heavy_check_mark: Math/coefficient_of_generating_function.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/coefficient_of_generating_function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 23:06:18+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/tests/yukicoder_1073.test.cpp.html">tests/yukicoder_1073.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//[z^n]P(z)/Q(z)
//coefficient_of_generating_function
ll CGF(vector<ll> P, vector<ll> Q, ll n, const ll mod = 1000000007) {
  assert(P.size() + 1 == Q.size());
  while (n > 0) {
    vector<ll> NQ = Q;
    for (int i=1; i<(int)Q.size(); i+=2) { //Q(-z)
      NQ[i] *= -1;
      NQ[i] %= mod;
      if (NQ[i] < 0) NQ[i] += mod;
    }
    auto PNQ = ntt_convolve(P, NQ, mod); //P(z)Q(-z)
    if (n&1) {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i+1];
    }
    else {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i];
    }
    auto QNQ = ntt_convolve(Q, NQ, mod); //Q(z)Q(-z)
    for (int i=0; i<(int)Q.size(); ++i) Q[i] = QNQ[2*i];
    n /= 2;
  }
  return P[0];
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/coefficient_of_generating_function.cpp"
//[z^n]P(z)/Q(z)
//coefficient_of_generating_function
ll CGF(vector<ll> P, vector<ll> Q, ll n, const ll mod = 1000000007) {
  assert(P.size() + 1 == Q.size());
  while (n > 0) {
    vector<ll> NQ = Q;
    for (int i=1; i<(int)Q.size(); i+=2) { //Q(-z)
      NQ[i] *= -1;
      NQ[i] %= mod;
      if (NQ[i] < 0) NQ[i] += mod;
    }
    auto PNQ = ntt_convolve(P, NQ, mod); //P(z)Q(-z)
    if (n&1) {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i+1];
    }
    else {
      for (int i=0; i<(int)P.size(); ++i) P[i] = PNQ[2*i];
    }
    auto QNQ = ntt_convolve(Q, NQ, mod); //Q(z)Q(-z)
    for (int i=0; i<(int)Q.size(); ++i) Q[i] = QNQ[2*i];
    n /= 2;
  }
  return P[0];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

