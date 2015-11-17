#include "SimpleIncNoCtrl.hpp"


SimpleIncNoCtrl::SimpleIncNoCtrl(int thread_num, int loop_num)
: SimpleIncBase(thread_num, loop_num){}

function<void()> SimpleIncNoCtrl::increment(){
  return [&](){
    _count++;
  };
}