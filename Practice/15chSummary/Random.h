#include<chrono>
#include<random>

namespace Random{


  int get(int min,int max){

  std::random_device rd{};
  std::seed_seq ss{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()),rd(),rd(),rd(),rd(),rd(),rd(),rd()};

  std::mt19937 mt{ss};
  std::uniform_int_distribution genR{min,max};

  return genR(mt);
  }


};
