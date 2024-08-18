#include<string>
#include<string_view>
#include<algorithm>
#include<cctype>
#include"Lib.hpp"

const std::string to_lower_string(std::string_view sv){
  std::string result(sv.size(),' ');
  std::transform(sv.begin(),sv.end(),result.begin(),::tolower);
  return result;
}
