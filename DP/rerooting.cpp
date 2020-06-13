template <typename T> struct ReRooting {
private:
  using F = function<T(T,int,int)>; //(dp,v,i):dpの更新
  using F2 = function<T(T,int)>;
  using H = function<T(T,T)>;
  int n;
  const vector<vector<int> > G;
  vector<vector<T> > dp;
  vector<T> ans;
  //dp_v = g(combine(f(dp_u1,u1), f(dp_u2,u2), ..., f(dp_uk,uk)), v)
  const F f;
  const H combine;
  const T NE; //neutral of combine
  const F2 g;

  T dfs1(int v, int p = -1) {
    T res = NE;
    dp[v].assign(G[v].size(), NE);
    for (int i = 0; i < (int)G[v].size(); ++i) {
      int to = G[v][i];
      if (to == p) continue;
      dp[v][i] = dfs1(to, v);
      res = combine(res, f(dp[v][i], v, i));
    }
    return g(res,v);
  }
  void dfs2(int v, const T& pre, int p = -1) {
    int m = G[v].size();
    for (int i = 0; i < m; ++i){
      if (G[v][i] == p) {
        dp[v][i] = pre; break;
      } 
    }
    vector<T> dp_l(G[v].size()+1,NE), dp_r(G[v].size()+1,NE); //累積combine
    for (int i = 0; i < m; ++i) {
      dp_l[i+1] = combine(dp_l[i], f(dp[v][i], v, i));
    }
    for (int i = G[v].size(); i > 0; --i) {
      dp_r[i-1] = combine(dp_r[i], f(dp[v][i-1], v, i-1));
    }
    ans[v] = g(dp_l[m], v);
    for (int i = 0; i < m; ++i) {
      int to = G[v][i];
      if (to == p) continue;
      dfs2(to, g(combine(dp_l[i], dp_r[i+1]), v), v);
    }
  }
public:
  ReRooting(const vector<vector<int> >& G, const F &f, const H &combine, T ne, 
  F2 g=[](T a, int b){ return a;}): G(G),f(f),combine(combine),NE(ne),g(g) {
    n = G.size();
    dp.resize(n);
    ans.assign(n,NE);
  }
  void build(int root = 0) {
    dfs1(root);
    dfs2(root, NE);
  }
  T operator[](const int &v) {
    assert(v < n);
    return ans[v];
  }
};