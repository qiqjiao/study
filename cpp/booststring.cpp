#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
static char lc(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
    return c;
}
int main(int argc, char **argv) {
  std::string s = "ABCDEFG";
  // boost to_lower is 25 times slower than customized tolower, as boost tolower
  // has localization handling.
  if (string(argv[1]) == "boost.tolower") {
    for (int i = 0; i < 30000000; ++i) {
      boost::algorithm::to_lower(s);
      //boost::algorithm::to_upper(s);
    }
  }
  if (string(argv[1]) == "custom.tolower") {
    for (int i = 0; i < 30000000; ++i) {
      std::transform(s.begin(), s.end(), s.begin(), lc);
      //boost::algorithm::to_upper(s);
    }
  }

  // stringstream is 5 times slower
  if (string(argv[1]) == "oss") {
    for (int i = 0; i < 30000000; ++i) {
        ostringstream oss;
        oss << i;
        s = oss.str();
    }
  }
  if (string(argv[1]) == "sprintf") {
    for (int i = 0; i < 30000000; ++i) {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", i);
        s = buf;
    }
  }

  return s.length();
}
