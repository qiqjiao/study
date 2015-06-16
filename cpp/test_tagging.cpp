<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>libs/uuid/test/test_tagging.cpp - 1.42.0</title>  <link rel="icon" href="/favicon.ico" type="image/ico" />
  <link rel="stylesheet" type="text/css" href="/style-v2/section-doc.css" />
  <!--[if IE 7]> <style type="text/css"> body { behavior: url(/style-v2/csshover3.htc); } </style> <![endif]-->

</head>

<body>
  <div id="heading">
    <div class="heading-inner">
  <div class="heading-placard"></div>

  <h1 class="heading-title">
  <a href="/">
  <img src="/gfx/space.png" alt= "Boost C++ Libraries" class="heading-logo" />
  <span class="heading-boost">Boost</span>
  <span class="heading-cpplibraries">C++ Libraries</span>
  </a></h1>

  <p class="heading-quote">
  <q>...one of the most highly
  regarded and expertly designed C++ library projects in the
  world.</q> <span class="heading-attribution">&mdash; <a href=
  "http://www.gotw.ca/" class="external">Herb Sutter</a> and <a href=
  "http://en.wikipedia.org/wiki/Andrei_Alexandrescu" class="external">Andrei
  Alexandrescu</a>, <a href=
  "http://safari.awprofessional.com/?XmlId=0321113586" class="external">C++
  Coding Standards</a></span></p>
</div>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-33761719-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
  </div>
  
  <div id="body">
    <div id="body-inner">
      <div id="content">
        <div class="section" id="docs">
          <div class="section-0">
            <div class="section-body">
              <h3>libs/uuid/test/test_tagging.cpp</h3>
<pre>
//  (C) Copyright Andy Tompkins 2009. Permission to copy, use, modify, sell and
//  distribute this software is granted provided this copyright notice appears
//  in all copies. This software is provided &quot;as is&quot; without express or implied
//  warranty, and with no claim as to its suitability for any purpose.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// <a href="http://www.boost.org/LICENSE_1_0.txt">http://www.boost.org/LICENSE_1_0.txt</a>)

//  libs/uuid/test/test_tagging.cpp  -------------------------------//

#include &lt;<a href="../../../boost/uuid/uuid.hpp">boost/uuid/uuid.hpp</a>&gt;
#include &lt;<a href="../../../boost/uuid/uuid_generators.hpp">boost/uuid/uuid_generators.hpp</a>&gt;

#include &lt;<a href="../../../boost/test/included/test_exec_monitor.hpp">boost/test/included/test_exec_monitor.hpp</a>&gt;
#include &lt;<a href="../../../boost/test/test_tools.hpp">boost/test/test_tools.hpp</a>&gt;

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
    
    object(object const&amp; rhs)
        : tag(rhs.tag)
        , state(rhs.state)
    {}
    
    bool operator==(object const&amp; rhs) const {
        return tag == rhs.tag;
    }
    
    object&amp; operator=(object const&amp; rhs) {
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

template &lt;typename elem, typename traits&gt;
std::basic_ostream&lt;elem, traits&gt;&amp; operator&lt;&lt;(std::basic_ostream&lt;elem, traits&gt;&amp; os, object const&amp; o)
{
    os &lt;&lt; o.get_state();
    return os;
}

int test_main(int, char*[])
{
    //using boost::test_tools::output_test_stream;
    
    object o1(1);

    object o2 = o1;
    BOOST_CHECK_EQUAL(o1, o2);

    o2.set_state(2);
    BOOST_CHECK_EQUAL(o1, o2);
    
    object o3;
    o3.set_state(3);

    BOOST_CHECK_NE(o1, o3);
    BOOST_CHECK_NE(o2, o3);
    
    return 0;
}
</pre>
            </div>
          </div>
        </div>
      </div>

      <div class="clear"></div>
    </div>
  </div>

  <div id="footer">
    <div id="footer-left">
      <div id="revised">
        <p>Revised $Date$</p>
      </div>

      <div id="copyright">
        <p>Copyright Beman Dawes, David Abrahams, 1998-2005.</p>

        <p>Copyright Rene Rivera 2004-2008.</p>
      </div>  <div id="license">
    <p>Distributed under the <a href="/LICENSE_1_0.txt" class=
    "internal">Boost Software License, Version 1.0</a>.</p>
  </div>
    </div>

    <div id="footer-right">
        <div id="banners">
    <p id="banner-xhtml"><a href="http://validator.w3.org/check?uri=referer"
    class="external">XHTML 1.0</a></p>

    <p id="banner-css"><a href=
    "http://jigsaw.w3.org/css-validator/check/referer" class=
    "external">CSS</a></p>

    <p id="banner-osi"><a href=
    "http://www.opensource.org/docs/definition.php" class="external">OSI
    Certified</a></p>
  </div>
    </div>

    <div class="clear"></div>
  </div>
</body>
</html>
