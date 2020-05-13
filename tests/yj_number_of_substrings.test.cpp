#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

#include "String/suffix_array.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string str;
  cin >> str;
  int n = str.length();
  suffix_array SA(str);
  // SA.output();
  int ans = 1; //SA[0]の1文字
  for (int i = 1; i < n; ++i) {
    //(i番目の接尾辞の長さ)-(i-1番目の接尾辞とi番目の設備辞のLCP)
    ans += (n-SA[i]) - SA.getLCP(SA[i-1], SA[i]); 
  }
  cout << ans << endl;
  return 0;
}


/*
 "abcbcba" を見て "ab", "abc", "abcb", "abcbc", "abcbcb", "abcbcba" を数え上げる.
  このとき部分文字列の数は ("abcbcba" の長さ) - ("a" と "abcbcba" の最長共通接頭辞) 
  のようにして計算することができる. 言い換えると "ab" から始まる部分文字列を数え上げている.
  https://kopricky.github.io/code/ClassicProblem/distinct_substrings.html
*/