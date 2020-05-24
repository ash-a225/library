#ifndef BFS_H
#define BFS_H
/*
  delta(V v, update(V t))
  index(V v) -> int
*/
template<class V, class Delta, class Index>
vector<ll> bfs(int n, V s, Delta delta, Index index) {
  vector<ll> dist(n,-1);
  queue<V> que;
  dist[index(s)] = 0;
  que.push(s);
  while(!que.empty()) {
    V v = que.front(); que.pop();
    auto update = [&](V t) {
      if (dist[index(t)] == -1) {
        dist[index(t)] = dist[index(v)]+1;
        que.push(t);
      }
    };
    delta(v,update);
  }
  return dist;
}
#endif