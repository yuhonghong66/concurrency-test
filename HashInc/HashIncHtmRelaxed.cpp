#include "HashIncHtmRelaxed.hpp"


HashIncHtmRelaxed::HashIncHtmRelaxed(int thread_num, int loop_num, int len, int density, int chunk)
: HashIncBase(thread_num, loop_num, len, density, chunk){}

function<void()> HashIncHtmRelaxed::increment(double prob){
  return [&](){
    #ifdef HTM
    __transaction_relaxed{
      for(int i = 0; i < _chunk; i++){
        auto index = rand_index();
        if(rand() % 10 < (int)(prob * 10))
          _v[index]++;
        else
          auto x = _v[index];
      }
    }
    #endif
  };
}
