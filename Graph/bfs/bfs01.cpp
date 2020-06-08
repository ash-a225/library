/*
  delta(V v, update(V t, ll w))
  index(V v) -> int
*/
template<class V, class Delta, class Index>
vector<ll> bfs01(int n, V s, Delta delta, Index index) {
  vector<ll> dist(n,numeric_limits<ll>::max());
  using VP = pair<V,ll>;
  deque<VP> que;
  dist[index(s)] = 0;
  que.push_back({s, dist[index(s)]});
  while(!que.empty()) {
    V v = que.front().first;
    ll d = que.front().second;
    que.pop_front();
    if(dist[index(v)] < d) continue;
    auto update = [&](V t, ll weight) {
      if (dist[index(t)] > dist[index(v)] + weight) {
        dist[index(t)] = dist[index(v)] + weight;
        if (weight == 1) que.push_back({t, dist[index(t)]});
        else que.push_front({t, dist[index(t)]});
      }
    };
    delta(v,update);
  }
  return dist;
}