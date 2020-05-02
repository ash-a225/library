#ifndef DIJKSTRA_H
#define DIJKSTRA_H

vector<int> preV;

template <typename T>
vector<T> dijkstra(int n, int s, const vector<vector<pair<int,T> > > &G) {
  priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > que;
  const T INF = numeric_limits<T>::max();
  vector<T> dist(n, INF);
  preV = vector<int>(n, -1);
  dist[s] = 0;
  que.push(pair<T,int>(0,s));
  while(!que.empty()) {
    pair<T,int> p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (auto e : G[v]) {
      int to = e.first;
      T cost = e.second;
      if (dist[to] > dist[v] + cost) {
        dist[to] = p.first + cost;
        preV[to] = v;
        que.push(pair<T,int>(dist[to], to));
      }
    }
  }
  return dist;
}

vector<int> get_path(int t) { //tへの経路復元
  vector<int> path;
  for(; t != -1; t = preV[t]){
    path.emplace_back(t);
  }
  reverse(path.begin(), path.end());
  return path;
}

#endif