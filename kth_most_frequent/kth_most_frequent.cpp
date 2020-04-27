#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// Kth Most Frequent String
//
// Question: 
//
//   Given a list of strings,
//   write a function to get the kth most frequently
//   occurring string.

using Strings = std::vector<std::string>;

auto kth_most_frequent(const Strings&, int k) -> std::string;


auto main() -> int {

  Strings strings {"a", "b", "c", "a", "b", "a"};

  std::string answer = kth_most_frequent(strings, 2);

  std::cout << answer << std::endl;
  
  return 0;
}


using Pair = std::pair<std::string, int>;
using Pairs = std::vector<Pair>;
using FreqTable = std::unordered_map<std::string, int>;

Pairs mapToVector(const FreqTable& map);


auto operator << (std::ostream& o, const Pairs& pairs) -> std::ostream& {

    for (auto pair: pairs) {
      o << "(" << pair.first << " , " << pair.second << ") ";
    }
    return o;
}


auto kth_most_frequent(const Strings& strs, int kth) -> std::string {

  FreqTable freq_table;

  for (auto str: strs) {
    freq_table[str]++;
  }

  // Get list of entries from the freq_table and 
  // sort the values, not keys

  Pairs v = mapToVector(freq_table);

  std::cout << v << std::endl;

  std::sort(begin(v), end(v), [](Pair a, Pair b) {
      return b.second < a.second;
  });

  std::cout << v << std::endl;

  if (kth >= 0 && kth < v.size()) {
    return v[kth].first;
  }

  return std::string("");
}


auto mapToVector(const FreqTable& map) -> Pairs {

  Pairs v;

  for (auto iter = map.begin(); iter != map.end(); ++iter) {
    v.push_back(*iter);
  }

  return v;
}

