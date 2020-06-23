template<typename T>
int LIS(const vector<T> &a, bool strict = true) {
  vector<T> dp(a.size(), numeric_limits<T>::max()/2);
  for (auto&& x : a) {
    if (strict) *lower_bound(dp.begin(), dp.end(), x) = x;
    else *upper_bound(dp.begin(), dp.end(), x) = x;
  }
  int len = lower_bound(dp.begin(), dp.end(), numeric_limits<T>::max()/2) - dp.begin();
  return len;
}