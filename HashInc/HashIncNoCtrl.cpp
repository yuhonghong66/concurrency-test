#include "HashIncNoCtrl.hpp"


HashIncNoCtrl::HashIncNoCtrl(int iters, int conc, int load, int len, int dens, int chunk, double ro)
: HashIncBase(iters, conc, load, len, dens, chunk, ro){}

void HashIncNoCtrl::increment(){
  const auto rnd = rand();
  const auto index = rand_index();

  auto sum = 0;
  for(int i = 0; i < _chunk; i++)
    sum += (rnd % 100 < (int)(_ro * 100)) ? ++_v[index] : _v[index];
  for(int i = 0; i < _load; i++){
    sum++;
    sum--;
  }
}
