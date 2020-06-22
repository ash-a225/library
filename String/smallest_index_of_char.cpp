//sのi番目以降でcが最初に登場するindex
struct SmallestIndex {
  vector<vector<int> > index;
  SmallestIndex(const string &s) {
    int n = s.length();
    index.assign(n, vector<int>('z'-'a'+1, n));
    string words = s; //sの文字
    sort(all(words));
    words.erase(unique(all(words)),words.end());
    for (int i = n-1; i >= 0; --i) {
      for (auto x : words) {
        int ind = x - 'a';
        if (s[i] == x) index[i][ind] = i; //update
        else if (i < n-1) {
          index[i][ind] = index[i+1][ind];
        }
      }
    }
  }
  int operator()(int i, char c) {
    assert(i < (int)index.size());
    return index[i][c - 'a'];
  }
};