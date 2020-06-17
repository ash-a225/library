template<class T>
vector<T> rekkyo(vector<T> item) {
  vector<T> a(1);
  for (auto i : item) {
    vector<T> b = a, c;
    for (auto &e : b) {
      e += i;
    }
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));
    std::swap(a,c);
  }
  return a;
}