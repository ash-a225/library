#ifndef Z_ALGO_H
#define Z_ALGO_H

struct z_array {
  vector<int> prefix;
  void build(const string &s) {
    prefix.assign(s.size(),0);
    for(int i=1, j=0; i < (int)s.size(); ++i) {
      if(i+prefix[i-j] < j+prefix[j]) {
        prefix[i] = prefix[i-j];
      }
      else {
        int k = std::max(0,j+prefix[j]-i);
        while(i+k < (int)s.size() && s[k] == s[i+k]) ++k;
        prefix[i] = k;
        j = i;
      }
    }
    prefix[0] = s.size();
  }
  int operator[](const int i) const{ 
    assert(i < (int)prefix.size());
    return prefix[i];
  }
  int size(){ return prefix.size();}
};

#endif