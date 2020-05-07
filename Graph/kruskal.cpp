#ifndef KRUSKAL_H
#define KRUSKAL_H

struct Edge { 
  int u, v, id;
  ll cost; 
  Edge(){}
	Edge(int u,int v,ll cost,int id):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

struct Kruskal {
  private:
    ll sum;
    vector<Edge> edges;
    int n;
    UnionFind uf;
    vector<bool> used;
  public:
    Kruskal(int n_, const vector<Edge> &edges_):
    edges(edges_),n(n_),uf(n_){ init();}
    void init() {
      sum = 0;
      used.assign((int)edges.size(),false);
    }
    void build() {
      sort(edges.begin(),edges.end());
      for (auto e : edges) {
        if (!uf.same(e.u, e.v)) { //閉路にならない
          uf.merge(e.u, e.v);
          sum += e.cost;
          used[e.id] = true;
        }
      }
    }
    ll get_sum(){ return sum;}
    bool is_used(int id){ 
      assert(id < n);
      return used[id];
    }
};

#endif