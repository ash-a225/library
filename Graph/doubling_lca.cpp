/*
https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
https://algo-logic.info/lca/
http://satanic0258.hatenablog.com/entry/2017/02/23/222647
*/
//par[i][v]   vの2^i個上の頂点
struct LowestCommonAncestor {
  private:
    vector<vector<int> > par;
    vector<int> dist; //from root
    const vector<vector<int> > &G;
    const int root;
    void dfs_(int v, int p, int d) {
      par[0][v] = p;
      dist[v] = d;
      for (auto to : G[v]) {
        if (to != p) dfs_(to, v, d+1);
      }
    }
    int query(int u,int v) {
      assert(u < (int)dist.size());
      assert(v < (int)dist.size());
      if (dist[u] > dist[v]) swap(u,v);
      int k = par.size();
      for (int i=0; i<k; ++i) { //LCAまでの距離を揃える
        if (((dist[v]-dist[u])>>i) & 1) v = par[i][v];
      }
      if (u==v) return u;
      for (int i = k-1; i>=0; --i) {
        if (par[i][u] == par[i][v]) continue;
        u = par[i][u];
        v = par[i][v];
      }
      return par[0][u];
    }
  public:
    LowestCommonAncestor(const vector<vector<int> > &G,int root=0):
    G(G),root(root){
      int n=G.size(), k=1;
      while ((1<<k) < n) k++;
      par.assign(k, vector<int>(n,-1));
      dist.assign(n,-1);
      dfs_(root,-1,0);
      for (int i=0; i<k-1; ++i) {
        for (int v=0; v<n; ++v) {
          if (par[i][v] < 0) par[i+1][v] = -1;
          else par[i+1][v] = par[i][par[i][v]];
        }
      }
    };
    int operator()(int u,int v) { return query(u,v);}
    int get_dist(int u, int v){ return dist[u]+dist[v]-2*dist[query(u,v)];}
    bool is_on_path(int u, int v, int a){ return get_dist(u,a)+get_dist(a,v)==get_dist(u,v);}
};