#ifndef GRIDDELTA_H
#define GRIDDELTA_H
template<class F>
struct grid_delta {
  int h,w;
  F caller;
  const int dx[8] = {-1,0,1,0,-1,1,-1,1};
  const int dy[8] = {0,-1,0,1,-1,-1,1,1};
  grid_delta(int h, int w, F f):h(h),w(w),caller(f){}
  template<class G>
  void operator()(P v, G update) {
    int y = v.first, x = v.second;
    for (int i=0; i<4; ++i) {
      int ny = y+dy[i], nx = x+dx[i];
      if (nx<0 || ny<0 || nx>=w || ny>=h) continue;
      caller(v, P(ny,nx), update);
    }
  }
};

template<class F>
grid_delta<F> make_grid_delta(int h, int w, F f) { return grid_delta<F>(h, w, f);}

struct grid_index {
  int h,w;
  grid_index(int h, int w):h(h),w(w){}
  int operator()(P v){ return v.first*w+v.second;}
  P inv(int ind){ return P((ind-(ind%w))/w ,ind%w);}
};
#endif