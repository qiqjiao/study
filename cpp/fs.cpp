#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

int main() {
  //boost::system::error_code ec;
  //bool r = create_directories(path("a/b"), ec);
  //cout << r << ec.message() << endl;
  //if (ec.value() != boost::system::errc::success) {
  //  cout << r << ec.message() << endl;
  //}
  for (recursive_directory_iterator i(argv[1]), end; i != end; ++i) {
      cout << i->path() << endl;
  }
  return 0;
}
