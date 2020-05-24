template <typename T>
bool bellman_ford(int n, int s, vector<T> &dist, const vector<vector<pair<int,T> > > &G) {
  const T INF = numeric_limits<T>::max();
  dist.resize(n, INF);
  dist[s] = 0;
  rep(cnt,n) {
    rep(v,n) {
      for (auto e : G[v]) {
        int to = e.first;
        T cost = e.second;
        if (dist[v] != INF && dist[to] > dist[v]+cost) {
          dist[to] = dist[v] + cost;
          if (cnt == n-1) return false; //NEGATIVE CYCLE
        }
      }
    }
  }
  return true;
}