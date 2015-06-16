//  (C) Copyright Andy Tompkins 2009. Permission to copy, use, modify, sell and
//  distribute this software is granted provided this copyright notice appears
//  in all copies. This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  libs/uuid/test/test_tagging.cpp  -------------------------------//

#include <iostream>
#include <sstream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class object
{
public:
    object()
        : tag(boost::uuids::random_generator()())
        , state(0)
    {}
    
    explicit object(int state)
        : tag(boost::uuids::random_generator()())
        , state(state)
    {}
    
    object(object const& rhs)
        : tag(rhs.tag)
        , state(rhs.state)
    {}
    
    bool operator==(object const& rhs) const {
        return tag == rhs.tag;
    }
    
    object& operator=(object const& rhs) {
        tag = rhs.tag;
        state = rhs.state;
        return *this;
    }
    
    int get_state() const { return state; }
    void set_state(int new_state) { state = new_state; }
    
private:
    boost::uuids::uuid tag;
    
    int state;
};

template <typename elem, typename traits>
std::basic_ostream<elem, traits>& operator<<(std::basic_ostream<elem, traits>& os, object const& o)
{
    os << o.get_state();
    return os;
}

int main(int, char*[])
{
    boost::uuids::uuid u = boost::uuids::random_generator()();
    std::string s;
    s.resize(u.size());
    std::copy(u.begin(), u.end(), s.begin());
    std::cout << s << "|" << std::endl;;
    return 0;
}

