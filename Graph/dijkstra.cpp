#ifndef DIJKSTRA_H
#define DIJKSTRA_H

template <typename T>
struct Dijkstra {
  private:
    struct edge{
      int to;
      T cost;
      edge(int to,T cost):to(to),cost(cost){}
      bool operator<(const edge &e)const{return cost>e.cost;}
    };
    int n;
    vector<vector<edge> > G;
    vector<T> dist;
    vector<int> preV;
  public:
    Dijkstra(int n_):n(n_),G(n_){};
    void add_edge(int u, int v, T c) {
      assert(u < n);
      assert(v < n);
      G[u].emplace_back(v,c);
    }
    void build(int s) {
      dist.assign(n,numeric_limits<T>::max());
      preV.assign(n,-1);
      dist[s] = 0;
      priority_queue<edge> que;
      que.push(edge(s,0LL));
      while(!que.empty()) {
        auto p = que.top(); que.pop();
        int v = p.to;
        if (dist[v] < p.cost) continue;
        for (const auto&& e:G[v]) {
          if (dist[e.to] > dist[v]+e.cost) {
            dist[e.to] = p.cost+e.cost;
            preV[e.to] = v;
            que.push(edge(e.to,dist[e.to]));
          }
        }
      }
    }
    vector<int> get_path(int to) { //経路復元
      vector<int> path;
      for(; to != -1; to = preV[to]){
        path.emplace_back(to);
      }
      reverse(path.begin(), path.end());
      return path;
    }
    T operator[](int k){
      assert(k < n);
      return dist[k];
    }
};

#endif