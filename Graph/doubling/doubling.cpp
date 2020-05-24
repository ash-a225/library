//to[i][v] vの2^i個上の頂点
template<typename T>
struct Doubling {
  private:
    const vector<vector<int> > &G;
    vector<vector<int> > to;
    vector<vector<T> > sum_w, min_w;
  public:
    Doubling(const vector<pair<int,T> > &G):G(G){};
    void build(ll max_k) {
      int k = 1;
      while ((1LL<<k) <= max_k) k++;
      int n = G.size();
      to.assign(k, vector<int>(n,-1));
      sum_w.assign(k, vector<T>(n,0));
      min_w.assign(k, vector<T>(n,numeric_limits<T>::max()));
      for(int i=0; i<k-1; ++i) {
        for(int v=0: v<n; ++v) {
          if (to[i][v] < 0) to[i+1][v] = -1;
          else {
            to[i+1][v] = to[i][to[i][v]];
            sum_w[i+1][v] = sum_w[i][v] + sum_w[i][to[i][v]];
            min_w[i+1][v] = min(min_w[i][v], min_w[i][to[i][v]]);
          }
        }
      }
    }
    int get_i(int i, ll k) { //iのk個先
      assert(i < (int)G.size());
      int ind = i;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) ind = to[j][ind];
      }
      return ind;
    }
    T get_sum_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll sum = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          sum += sum_w[j][ind];
          ind = to[j][ind];
        }
      }
      return sum;
    }
    T get_min_w(int i, ll k) {
      assert(i < (int)G.size());
      int ind = i;
      ll mini = 0;
      for (int j=0; j<k; ++j) {
        if (k & (1LL<<j)) {
          chmin(mini, min_w[j][ind]);
          ind = to[j][ind];
        }
      }
      return mini;
    }
};