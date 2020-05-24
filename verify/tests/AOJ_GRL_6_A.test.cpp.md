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


# :heavy_check_mark: tests/AOJ_GRL_6_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b61a6d542f9036550ba9c401c80f00ef">tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/tests/AOJ_GRL_6_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 18:53:15+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/dinic.cpp.html">Graph/dinic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

#include "Graph/dinic.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n,m;
  cin >> n >> m;
  Dinic<ll> dinic(n);
  rep(i,m) {
    int u,v;
    ll c;
    cin >> u >> v >> c;
    dinic.add_edge(u,v,c);
  }
  cout << dinic.max_flow(0,n-1) << endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/AOJ_GRL_6_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

#line 1 "Graph/dinic.cpp"
/*
https://ei1333.github.io/luzhiled/snippets/graph/dinic.html
*/
template<typename T>
struct Dinic {
  private:
    const T INF;
    struct edge {
      int to, rev, idx; 
      T cap; 
      bool isrev; 
      edge(){}
      edge(int to,T cap,int rev,bool isrev,int idx=-1):
      to(to),rev(rev),idx(idx),cap(cap),isrev(isrev) {}
    };
    vector<vector<edge> > G;
    vector<int> min_cost, iter;
    
    bool bfs(int s, int t) {
      min_cost.assign(G.size(),-1);
      queue<int> que;
      min_cost[s] = 0;
      que.push(s);
      while(!que.empty() && min_cost[t] == -1) {
        int p = que.front();
        que.pop();
        for(auto &e : G[p]) {
          if(e.cap > 0 && min_cost[e.to] == -1) {
            min_cost[e.to] = min_cost[p] + 1;
            que.push(e.to);
          }
        }
      }
      return min_cost[t] != -1;
    }
    T dfs(int v, const int t, T flow) {
      if(v == t) return flow;
      for(int &i = iter[v]; i < (int)G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && min_cost[v] < min_cost[e.to]) {
          T d = dfs(e.to, t, min(flow, e.cap));
          if(d == 0) continue;
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
      return 0;
    }
  public:
    Dinic(int n):INF(numeric_limits<T>::max()),G(n) {}
    void add_edge(int from, int to, T cap, int idx=-1) {
      G[from].emplace_back(edge(to, cap, (int)G[to].size(), false, idx));
      G[to].emplace_back(edge(from, 0, (int)G[from].size()-1, true, idx));
    }
    T max_flow(int s, int t) {
      assert(s < (int)G.size());
      assert(t < (int)G.size());
      T flow = 0;
      while(bfs(s,t)) {
        iter.assign(G.size(), 0);
        T f = 0;
        while((f = dfs(s,t,INF)) > 0) flow += f;
      }
      return flow;
    }
    void output() {
      for(int i = 0; i < (int)G.size(); i++) {
        for(auto &e : G[i]) {
          if(e.isrev) continue;
          auto &rev_e = G[e.to][e.rev];
          cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
        }
      }
    }
};
#line 20 "tests/AOJ_GRL_6_A.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n,m;
  cin >> n >> m;
  Dinic<ll> dinic(n);
  rep(i,m) {
    int u,v;
    ll c;
    cin >> u >> v >> c;
    dinic.add_edge(u,v,c);
  }
  cout << dinic.max_flow(0,n-1) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

