//https://drken1215.hatenablog.com/entry/2019/09/16/014600
// Suffix Array ( Manber&Myers: O(n (logn)^2) )
struct suffix_array {
  private:
    string str;
    vector<int> sa;   // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
      int n,k;
      const vector<int> &rank;
      CompareSA(int n, int k, const vector<int> &rank_sa):n(n),k(k),rank(rank_sa){}
      bool operator()(int i, int j) {
        if (rank[i] != rank[j]) return (rank[i] < rank[j]);
        else {
          int rank_ik = (i + k <= n ? rank[i + k] : -1);
          int rank_jk = (j + k <= n ? rank[j + k] : -1);
          return (rank_ik < rank_jk);
        }
      }
    };  
    void buildSA() {
      int n = (int)str.size();
      sa.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
      for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
      sa[n] = n, rank_sa[n] = -1;
      for (int k = 1; k <= n; k *= 2) {
        CompareSA csa(n, k, rank_sa);
        sort(sa.begin(), sa.end(), csa);
        tmp_rank_sa[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
          tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
          if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
        }
        for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
      }
    }
  public:
    suffix_array(const string& str_):str(str_) { buildSA();}
    void init(const string& str_) { str = str_; buildSA();}

    inline int& operator [] (int i) { //sa[0]は空文字のsuffix
      assert(i < (int)sa.size()-1);
      return sa[i+1];
    }
    void output() { //接尾辞i : str.substr(i)
      for (int i = 0; i < (int)sa.size()-1; ++i) {
        cout << sa[i+1] << " " << str.substr(sa[i+1]) << "\n";
      }
    }
};