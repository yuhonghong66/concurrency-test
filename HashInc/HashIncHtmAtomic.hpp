#ifndef HASHINCHTMATOMIC
#define HASHINCHTMATOMIC

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include "HashIncBase.hpp"

using namespace std;


class HashIncHtmAtomic: public HashIncBase{
protected:
  function<void()> increment();
  
public:
  HashIncHtmAtomic(int thread_num, int loop_num, int len);
};

#endif