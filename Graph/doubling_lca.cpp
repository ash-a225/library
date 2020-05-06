#ifndef D_LCA_H
#define D_LCA_H

//https://ei1333.github.io/luzhiled/snippets/tree/doubling-lowest-common-ancestor.html
//https://algo-logic.info/lca/
//http://satanic0258.hatenablog.com/entry/2017/02/23/222647

struct LowestCommonAncestor {
  private:
    vector<vector<int> > par;
    vector<int> dist; //from root
    const vector<vector<int> > &G;
    const int root;
  public:
    LowestCommonAncestor(const vector<vector<int> > &G,int root=0):
    G(G),root(root){init();};
    void init() {
      int n = G.size(), k = 1;
      while ((1<<k) < n) k++;
      par.assign(k, vector<int>(n,-1));
      dist.assign(n,-1);
      // build
      dfs(root, -1, 0);
      for (int i=0; i<k-1; ++i) {
        for (int v=0; v<n; ++v) {
          if (par[i][v] < 0) par[i+1][v] = -1;
          else par[i+1][v] = par[i][par[i][v]];
        }
      }
    }
    void dfs(int v, int p, int d) {
      par[0][v] = p;
      dist[v] = d;
      for (auto to : G[v]) {
        if (to != p) dfs(to, v, d+1);
      }
    }
    int query(int u, int v) {
      if (dist[u] > dist[v]) swap(u,v);
      int k = par.size();
      for (int i=0; i<k; ++i) { //LCAまでの距離を揃える
        if (((dist[v]-dist[u])>>i) & 1) v = par[i][v];
      }
      if (u==v) return u;
      for (int i = k-1; i>=0; --i) {
        if (par[i][u] != par[i][v]) {
          u = par[i][u];
          v = par[i][v];
        }
      }
      return par[0][u];
    }
    int get_dist(int u, int v) { return dist[u]+dist[v]-2*dist[query(u,v)];}
    bool is_on_path(int u, int v, int a) { 
      return get_dist(u,a)+get_dist(a,v) == get_dist(u,v); 
    }
};

#endif