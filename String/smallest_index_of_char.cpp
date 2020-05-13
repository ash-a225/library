#ifndef SIOC_H
#define SIOC_H

//sのi番目以降でcが最初に登場するインデックスを返す
//名前は適当

struct SmallestIndex {
  vector<vector<int> > index;
  void build(const string &s) {
    index.assign(s.size(),vector<int>('z'-'a'+1,-1));
    string words = s; //sの文字
    sort(all(words));
    words.erase(unique(all(words)),words.end());
    for (int i = (int)s.size()-1; i >= 0; --i) {
      for (auto x : words) {
        int ind = x - 'a';
        if (s[i] == x) index[i][ind] = i; //update
        else if (i < (int)s.size()-1) {
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

#endif