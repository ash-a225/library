#ifndef DINIC_H
#define DINIC_H
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

#endif