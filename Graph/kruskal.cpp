#ifndef KRUSKAL_H
#define KRUSKAL_H

struct edge { 
  int u, v;
  ll cost; 
  edge(){}
	edge(int u, int v, ll cost):u(u), v(v), cost(cost){}
  bool operator<(const edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<edge> G;
    int n;
    UnionFind uf;
  public:
    Kruskal(int n_, const vector<edge> &G_):G(G_),n(n_),uf(n_){ init();}
    void init() {
      sort(G.begin(),G.end());
      sum = 0;
      for (auto e : G) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
        }
      }
    }
    ll get_sum(){ return sum;}
};

#endif