#include "DataStructure/unionfind.cpp"

template<typename T>
struct Edge { 
  int u, v, id;
  T cost; 
  Edge():id(0){}
	Edge(int u,int v,T cost,int id=0):u(u),v(v),id(id),cost(cost){}
  bool operator<(const Edge &e) const{ return cost<e.cost;};
};

template<typename T>
struct Kruskal {
  private:
    T sum;
    vector<Edge<T> > edges;
    UnionFind uf;
    vector<bool> used;
  public:
    Kruskal(int n, const vector<Edge<T> > &edges_):edges(edges_),uf(n){
      sum = 0;
      used.assign((int)edges.size(),false);
      sort(edges.begin(),edges.end());
      for (auto &e : edges) {
        if (!uf.same(e.u,e.v)) { //circleなし
          uf.unite(e.u,e.v);
          sum += e.cost;
          used[e.id] = true;
        }
      }
    }
    T get_sum(){ return sum;}
    bool is_used(int id){ 
      assert(id < (int)edges.size());
      return used[id];
    }
};