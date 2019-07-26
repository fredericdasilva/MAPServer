<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  
  


  

  <head>
    <title>
      /branches/release/boost/archive/text_iarchive.hpp –
      Boost C++ Libraries – Trac
    </title>
        <link rel="search" href="/trac/boost/search" />
        <link rel="help" href="/trac/boost/wiki/TracGuide" />
        <link rel="alternate" href="/trac/boost/export/48390/branches/release/boost/archive/text_iarchive.hpp" type="text/plain" title="Original Format" />
        <link rel="up" href="/trac/boost/browser/branches/release/boost/archive" title="Parent directory" />
        <link rel="start" href="/trac/boost/wiki" />
        <link rel="stylesheet" href="/trac/boost/chrome/common/css/trac.css" type="text/css" /><link rel="stylesheet" href="/trac/boost/chrome/common/css/code.css" type="text/css" /><link rel="stylesheet" href="/trac/boost/chrome/common/css/browser.css" type="text/css" />
        <link rel="shortcut icon" href="http://beta.boost.org/favicon.ico" type="image/x-icon" />
        <link rel="icon" href="http://beta.boost.org/favicon.ico" type="image/x-icon" />
      <link type="application/opensearchdescription+xml" rel="search" href="/trac/boost/search/opensearch" title="Search Boost C++ Libraries" />
    <script type="text/javascript" src="/trac/boost/chrome/common/js/jquery.js"></script><script type="text/javascript" src="/trac/boost/chrome/common/js/trac.js"></script><script type="text/javascript" src="/trac/boost/chrome/common/js/search.js"></script>
    <!--[if lt IE 7]>
    <script type="text/javascript" src="/trac/boost/chrome/common/js/ie_pre7_hacks.js"></script>
    <![endif]-->
    <script type="text/javascript">
      jQuery(document).ready(function($) {
        $("#jumploc input").hide();
        $("#jumploc select").change(function () {
          this.parentNode.parentNode.submit();
        })
      });
    </script>
  </head>
  <body>
    <div id="banner">
      <div id="header">
        <a id="logo" href="http://svn.boost.org/trac/boost"><img src="http://www.boost.org/boost.png" alt="C++ Boost" /></a>
      </div>
      <form id="search" action="/trac/boost/search" method="get">
        <div>
          <label for="proj-search">Search:</label>
          <input type="text" id="proj-search" name="q" size="18" value="" />
          <input type="submit" value="Search" />
        </div>
      </form>
      <div id="metanav" class="nav">
    <ul>
      <li class="first"><a href="/trac/boost/login">Login</a></li><li><a href="/trac/boost/wiki/TracGuide">Help/Guide</a></li><li><a href="/trac/boost/about">About Trac</a></li><li class="last"><a href="/trac/boost/prefs">Preferences</a></li>
    </ul>
  </div>
    </div>
    <div id="mainnav" class="nav">
    <ul>
      <li class="first"><a href="/trac/boost/wiki">Wiki</a></li><li><a href="/trac/boost/timeline">Timeline</a></li><li><a href="/trac/boost/roadmap">Roadmap</a></li><li class="active"><a href="/trac/boost/browser">Browse Source</a></li><li><a href="/trac/boost/report">View Tickets</a></li><li><a href="/trac/boost/newticket">New Ticket</a></li><li class="last"><a href="/trac/boost/search">Search</a></li>
    </ul>
  </div>
    <div id="main">
      <div id="ctxtnav" class="nav">
        <h2>Context Navigation</h2>
          <ul>
            <li class="first "><a href="/trac/boost/changeset/41369/branches/release/boost/archive/text_iarchive.hpp">Last Change</a></li><li><a href="/trac/boost/browser/branches/release/boost/archive/text_iarchive.hpp?annotate=blame&amp;rev=41369" title="Annotate each line with the last changed revision (this can be time consuming...)">Annotate</a></li><li class="last"><a href="/trac/boost/log/branches/release/boost/archive/text_iarchive.hpp">Revision Log</a></li>
          </ul>
        <hr />
      </div>
    <div id="content" class="browser">
      <h1>
    <a class="pathentry first" title="Go to root directory" href="/trac/boost/browser">root</a><span class="pathentry sep">/</span><a class="pathentry" title="View branches" href="/trac/boost/browser/branches">branches</a><span class="pathentry sep">/</span><a class="pathentry" title="View release" href="/trac/boost/browser/branches/release">release</a><span class="pathentry sep">/</span><a class="pathentry" title="View boost" href="/trac/boost/browser/branches/release/boost">boost</a><span class="pathentry sep">/</span><a class="pathentry" title="View archive" href="/trac/boost/browser/branches/release/boost/archive">archive</a><span class="pathentry sep">/</span><a class="pathentry" title="View text_iarchive.hpp" href="/trac/boost/browser/branches/release/boost/archive/text_iarchive.hpp">text_iarchive.hpp</a>
    <br style="clear: both" />
  </h1>
      <div id="jumprev">
        <form action="" method="get">
          <div>
            <label for="rev">
              View revision:</label>
            <input type="text" id="rev" name="rev" size="6" />
          </div>
        </form>
      </div>
      <div id="jumploc">
        <form action="" method="get">
          <div class="buttons">
            <label for="preselected">Visit:</label>
            <select id="preselected" name="preselected">
              <option selected="selected"></option>
              <optgroup label="branches">
                <option value="/trac/boost/browser/trunk">trunk</option><option value="/trac/boost/browser/branches/array_wrapper">branches/array_wrapper</option><option value="/trac/boost/browser/branches/bbv2python">branches/bbv2python</option><option value="/trac/boost/browser/branches/bcbboost">branches/bcbboost</option><option value="/trac/boost/browser/branches/bitten">branches/bitten</option><option value="/trac/boost/browser/branches/BOOST_BUILD_PYTHON">branches/BOOST_BUILD_PYTHON</option><option value="/trac/boost/browser/branches/BOOST_VERSION_NUMBER">branches/BOOST_VERSION_NUMBER</option><option value="/trac/boost/browser/branches/build">branches/build</option><option value="/trac/boost/browser/branches/CMake">branches/CMake</option><option value="/trac/boost/browser/branches/cpp0x">branches/cpp0x</option><option value="/trac/boost/browser/branches/doc">branches/doc</option><option value="/trac/boost/browser/branches/fast_array_serialization">branches/fast_array_serialization</option><option value="/trac/boost/browser/branches/fusion">branches/fusion</option><option value="/trac/boost/browser/branches/hash">branches/hash</option><option value="/trac/boost/browser/branches/i18n">branches/i18n</option><option value="/trac/boost/browser/branches/iostreams_dev">branches/iostreams_dev</option><option value="/trac/boost/browser/branches/iterator_build">branches/iterator_build</option><option value="/trac/boost/browser/branches/jam">branches/jam</option><option value="/trac/boost/browser/branches/libs">branches/libs</option><option value="/trac/boost/browser/branches/multi_array">branches/multi_array</option><option value="/trac/boost/browser/branches/multi_array_python">branches/multi_array_python</option><option value="/trac/boost/browser/branches/pdimov_pre_136">branches/pdimov_pre_136</option><option value="/trac/boost/browser/branches/proto">branches/proto</option><option value="/trac/boost/browser/branches/python-voidptr">branches/python-voidptr</option><option value="/trac/boost/browser/branches/quickbook">branches/quickbook</option><option value="/trac/boost/browser/branches/RC_1_33_0">branches/RC_1_33_0</option><option value="/trac/boost/browser/branches/RC_1_34_0">branches/RC_1_34_0</option><option value="/trac/boost/browser/branches/release">branches/release</option><option value="/trac/boost/browser/branches/serialization_header_order">branches/serialization_header_order</option><option value="/trac/boost/browser/branches/SPIRIT_1_6">branches/SPIRIT_1_6</option><option value="/trac/boost/browser/branches/SPIRIT_1_8">branches/SPIRIT_1_8</option><option value="/trac/boost/browser/branches/SPIRIT_1_9">branches/SPIRIT_1_9</option><option value="/trac/boost/browser/branches/SPIRIT_RC_1_8_5">branches/SPIRIT_RC_1_8_5</option><option value="/trac/boost/browser/branches/system">branches/system</option><option value="/trac/boost/browser/branches/thread_rewrite">branches/thread_rewrite</option><option value="/trac/boost/browser/branches/xpressive">branches/xpressive</option><option value="/trac/boost/browser/branches/zip_iterator_fusion">branches/zip_iterator_fusion</option>
              </optgroup><optgroup label="tags">
                <option value="/trac/boost/browser/tags/before_adding_complex?rev=9301">tags/before_adding_complex</option><option value="/trac/boost/browser/tags/before_partial_unit_test_merge?rev=9522">tags/before_partial_unit_test_merge</option><option value="/trac/boost/browser/tags/boost%2B%2Bgraph?rev=24506">tags/boost++graph</option><option value="/trac/boost/browser/tags/boost-initial?rev=10676">tags/boost-initial</option><option value="/trac/boost/browser/tags/BOOST_BUILD_PYTHON_BASE?rev=27040">tags/BOOST_BUILD_PYTHON_BASE</option><option value="/trac/boost/browser/tags/boost_python_llnl_?rev=15542">tags/boost_python_llnl_</option><option value="/trac/boost/browser/tags/build-development-checkpoint-2?rev=10370">tags/build-development-checkpoint-2</option><option value="/trac/boost/browser/tags/conversion-merge-1?rev=7674">tags/conversion-merge-1</option><option value="/trac/boost/browser/tags/detailified?rev=8275">tags/detailified</option><option value="/trac/boost/browser/tags/dwa-postlicense?rev=35069">tags/dwa-postlicense</option><option value="/trac/boost/browser/tags/dwa-prelicense?rev=35235">tags/dwa-prelicense</option><option value="/trac/boost/browser/tags/factor_out_redundant_macro_code_into_base_class?rev=15400">tags/factor_out_redundant_macro_code_into_base_class</option><option value="/trac/boost/browser/tags/graph_devel_merged_to_trunk?rev=24411">tags/graph_devel_merged_to_trunk</option><option value="/trac/boost/browser/tags/header-cache?rev=14038">tags/header-cache</option><option value="/trac/boost/browser/tags/iostreams_pre_non_blocking?rev=28309">tags/iostreams_pre_non_blocking</option><option value="/trac/boost/browser/tags/jan18?rev=21829">tags/jan18</option><option value="/trac/boost/browser/tags/merge_wg21_random_proposal?rev=18951">tags/merge_wg21_random_proposal</option><option value="/trac/boost/browser/tags/merged_to_graph_devel?rev=24507">tags/merged_to_graph_devel</option><option value="/trac/boost/browser/tags/merged_to_mplbook?rev=22366">tags/merged_to_mplbook</option><option value="/trac/boost/browser/tags/minmax?rev=22393">tags/minmax</option><option value="/trac/boost/browser/tags/monthly?rev=12985">tags/monthly</option><option value="/trac/boost/browser/tags/mpl_root_license_rename_1?rev=22780">tags/mpl_root_license_rename_1</option><option value="/trac/boost/browser/tags/n1889?rev=31125">tags/n1889</option><option value="/trac/boost/browser/tags/parameter_merged_to_RC_1_34_0?rev=38382">tags/parameter_merged_to_RC_1_34_0</option><option value="/trac/boost/browser/tags/pre_serialization_header_order?rev=34069">tags/pre_serialization_header_order</option><option value="/trac/boost/browser/tags/reference_types_in_return_type_deduction?rev=12313">tags/reference_types_in_return_type_deduction</option><option value="/trac/boost/browser/tags/release?rev=48100">tags/release</option><option value="/trac/boost/browser/tags/Root_uBLAS_assignment_sematics?rev=29865">tags/Root_uBLAS_assignment_sematics</option><option value="/trac/boost/browser/tags/Root_uBLAS_pure?rev=25681">tags/Root_uBLAS_pure</option><option value="/trac/boost/browser/tags/SPIRIT_1_6_4?rev=37103">tags/SPIRIT_1_6_4</option><option value="/trac/boost/browser/tags/SPIRIT_1_6_4_MINIBOOST?rev=38030">tags/SPIRIT_1_6_4_MINIBOOST</option><option value="/trac/boost/browser/tags/SPIRIT_1_8_5?rev=38961">tags/SPIRIT_1_8_5</option><option value="/trac/boost/browser/tags/SPIRIT_1_8_5_MINIBOOST?rev=38962">tags/SPIRIT_1_8_5_MINIBOOST</option><option value="/trac/boost/browser/tags/SPIRIT_MINIBOOST_1_34_0?rev=38032">tags/SPIRIT_MINIBOOST_1_34_0</option><option value="/trac/boost/browser/tags/start?rev=44233">tags/start</option><option value="/trac/boost/browser/tags/state-perforce_2_4_merge-1?rev=13110">tags/state-perforce_2_4_merge-1</option><option value="/trac/boost/browser/tags/state-update_rule-1?rev=14282">tags/state-update_rule-1</option><option value="/trac/boost/browser/tags/thread_base?rev=17054">tags/thread_base</option><option value="/trac/boost/browser/tags/thread_rewrite_1?rev=33565">tags/thread_rewrite_1</option><option value="/trac/boost/browser/tags/tools?rev=44341">tags/tools</option><option value="/trac/boost/browser/tags/type_traits2_sub?rev=8507">tags/type_traits2_sub</option><option value="/trac/boost/browser/tags/uBLAS_good?rev=36209">tags/uBLAS_good</option><option value="/trac/boost/browser/tags/USING_BOOST_TEST?rev=24206">tags/USING_BOOST_TEST</option><option value="/trac/boost/browser/tags/Version_1_25_1_BGL?rev=11635">tags/Version_1_25_1_BGL</option>
              </optgroup>
            </select>
            <input type="submit" value="Go!" title="Jump to the chosen preselected path" />
          </div>
        </form>
      </div>
      <table id="info" summary="Revision info">
        <tr>
          <th scope="col">
            Revision <a href="/trac/boost/changeset/41369">41369</a>, <span title="3788 bytes">3.7 kB</span>
            (checked in by bemandawes, <a class="timeline" href="/trac/boost/timeline?from=2007-11-25T13%3A07%3A19Z-0500&amp;precision=second" title="2007-11-25T13:07:19Z-0500 in Timeline">9 months</a> ago)
          </th>
        </tr>
        <tr>
          <td class="message searchable">
              <p>
Full merge from trunk at revision 41356 of entire boost-root tree. <br />
</p>
          </td>
        </tr>
        <tr>
          <td colspan="2">
            <ul class="props">
              <li>
                  Property <strong>svn:mime-type</strong> set to
                    <em><code>text/plain</code></em>
              </li><li>
                  Property <strong>svn:eol-style</strong> set to
                    <em><code>native</code></em>
              </li><li>
                  Property <strong>svn:keywords</strong> set to
                    <em><code>Author Date Id Revision</code></em>
              </li>
            </ul>
          </td>
        </tr>
      </table>
      <div id="preview" class="searchable">
    <table class="code"><thead><tr><th class="lineno" title="Line numbers">Line</th><th class="content"> </th></tr></thead><tbody><tr><th id="L1"><a href="#L1">1</a></th><td>#ifndef BOOST_ARCHIVE_TEXT_IARCHIVE_HPP</td></tr><tr><th id="L2"><a href="#L2">2</a></th><td>#define BOOST_ARCHIVE_TEXT_IARCHIVE_HPP</td></tr><tr><th id="L3"><a href="#L3">3</a></th><td></td></tr><tr><th id="L4"><a href="#L4">4</a></th><td>// MS compatible compilers support #pragma once</td></tr><tr><th id="L5"><a href="#L5">5</a></th><td>#if defined(_MSC_VER) &amp;&amp; (_MSC_VER &gt;= 1020)</td></tr><tr><th id="L6"><a href="#L6">6</a></th><td># pragma once</td></tr><tr><th id="L7"><a href="#L7">7</a></th><td>#endif</td></tr><tr><th id="L8"><a href="#L8">8</a></th><td></td></tr><tr><th id="L9"><a href="#L9">9</a></th><td>/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8</td></tr><tr><th id="L10"><a href="#L10">10</a></th><td>// text_iarchive.hpp</td></tr><tr><th id="L11"><a href="#L11">11</a></th><td></td></tr><tr><th id="L12"><a href="#L12">12</a></th><td>// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . </td></tr><tr><th id="L13"><a href="#L13">13</a></th><td>// Use, modification and distribution is subject to the Boost Software</td></tr><tr><th id="L14"><a href="#L14">14</a></th><td>// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at</td></tr><tr><th id="L15"><a href="#L15">15</a></th><td>// http://www.boost.org/LICENSE_1_0.txt)</td></tr><tr><th id="L16"><a href="#L16">16</a></th><td></td></tr><tr><th id="L17"><a href="#L17">17</a></th><td>//  See http://www.boost.org for updates, documentation, and revision history.</td></tr><tr><th id="L18"><a href="#L18">18</a></th><td></td></tr><tr><th id="L19"><a href="#L19">19</a></th><td>#include &lt;istream&gt;</td></tr><tr><th id="L20"><a href="#L20">20</a></th><td></td></tr><tr><th id="L21"><a href="#L21">21</a></th><td>#include &lt;boost/archive/detail/auto_link_archive.hpp&gt;</td></tr><tr><th id="L22"><a href="#L22">22</a></th><td>#include &lt;boost/archive/basic_text_iprimitive.hpp&gt;</td></tr><tr><th id="L23"><a href="#L23">23</a></th><td>#include &lt;boost/archive/basic_text_iarchive.hpp&gt;</td></tr><tr><th id="L24"><a href="#L24">24</a></th><td>#include &lt;boost/config.hpp&gt;</td></tr><tr><th id="L25"><a href="#L25">25</a></th><td></td></tr><tr><th id="L26"><a href="#L26">26</a></th><td>#include &lt;boost/archive/detail/abi_prefix.hpp&gt; // must be the last header</td></tr><tr><th id="L27"><a href="#L27">27</a></th><td></td></tr><tr><th id="L28"><a href="#L28">28</a></th><td>namespace boost { </td></tr><tr><th id="L29"><a href="#L29">29</a></th><td>namespace archive {</td></tr><tr><th id="L30"><a href="#L30">30</a></th><td></td></tr><tr><th id="L31"><a href="#L31">31</a></th><td>template&lt;class Archive&gt;</td></tr><tr><th id="L32"><a href="#L32">32</a></th><td>class text_iarchive_impl : </td></tr><tr><th id="L33"><a href="#L33">33</a></th><td>    public basic_text_iprimitive&lt;std::istream&gt;,</td></tr><tr><th id="L34"><a href="#L34">34</a></th><td>    public basic_text_iarchive&lt;Archive&gt;</td></tr><tr><th id="L35"><a href="#L35">35</a></th><td>{</td></tr><tr><th id="L36"><a href="#L36">36</a></th><td>#ifdef BOOST_NO_MEMBER_TEMPLATE_FRIENDS</td></tr><tr><th id="L37"><a href="#L37">37</a></th><td>public:</td></tr><tr><th id="L38"><a href="#L38">38</a></th><td>#else</td></tr><tr><th id="L39"><a href="#L39">39</a></th><td>    friend class detail::interface_iarchive&lt;Archive&gt;;</td></tr><tr><th id="L40"><a href="#L40">40</a></th><td>    friend class basic_text_iarchive&lt;Archive&gt;;</td></tr><tr><th id="L41"><a href="#L41">41</a></th><td>    friend class load_access;</td></tr><tr><th id="L42"><a href="#L42">42</a></th><td>protected:</td></tr><tr><th id="L43"><a href="#L43">43</a></th><td>#endif</td></tr><tr><th id="L44"><a href="#L44">44</a></th><td>    template&lt;class T&gt;</td></tr><tr><th id="L45"><a href="#L45">45</a></th><td>    void load(T &amp; t){</td></tr><tr><th id="L46"><a href="#L46">46</a></th><td>        basic_text_iprimitive&lt;std::istream&gt;::load(t);</td></tr><tr><th id="L47"><a href="#L47">47</a></th><td>    }</td></tr><tr><th id="L48"><a href="#L48">48</a></th><td>    BOOST_ARCHIVE_DECL(void) </td></tr><tr><th id="L49"><a href="#L49">49</a></th><td>    load(char * t);</td></tr><tr><th id="L50"><a href="#L50">50</a></th><td>    #ifndef BOOST_NO_INTRINSIC_WCHAR_T</td></tr><tr><th id="L51"><a href="#L51">51</a></th><td>    BOOST_ARCHIVE_DECL(void) </td></tr><tr><th id="L52"><a href="#L52">52</a></th><td>    load(wchar_t * t);</td></tr><tr><th id="L53"><a href="#L53">53</a></th><td>    #endif</td></tr><tr><th id="L54"><a href="#L54">54</a></th><td>    BOOST_ARCHIVE_DECL(void) </td></tr><tr><th id="L55"><a href="#L55">55</a></th><td>    load(std::string &amp;s);</td></tr><tr><th id="L56"><a href="#L56">56</a></th><td>    #ifndef BOOST_NO_STD_WSTRING</td></tr><tr><th id="L57"><a href="#L57">57</a></th><td>    BOOST_ARCHIVE_DECL(void) </td></tr><tr><th id="L58"><a href="#L58">58</a></th><td>    load(std::wstring &amp;ws);</td></tr><tr><th id="L59"><a href="#L59">59</a></th><td>    #endif</td></tr><tr><th id="L60"><a href="#L60">60</a></th><td>    // note: the following should not needed - but one compiler (vc 7.1)</td></tr><tr><th id="L61"><a href="#L61">61</a></th><td>    // fails to compile one test (test_shared_ptr) without it !!!</td></tr><tr><th id="L62"><a href="#L62">62</a></th><td>    // make this protected so it can be called from a derived archive</td></tr><tr><th id="L63"><a href="#L63">63</a></th><td>    template&lt;class T&gt;</td></tr><tr><th id="L64"><a href="#L64">64</a></th><td>    void load_override(T &amp; t, BOOST_PFTO int){</td></tr><tr><th id="L65"><a href="#L65">65</a></th><td>        basic_text_iarchive&lt;Archive&gt;::load_override(t, 0);</td></tr><tr><th id="L66"><a href="#L66">66</a></th><td>    }</td></tr><tr><th id="L67"><a href="#L67">67</a></th><td>    BOOST_ARCHIVE_DECL(void)</td></tr><tr><th id="L68"><a href="#L68">68</a></th><td>    load_override(class_name_type &amp; t, int);</td></tr><tr><th id="L69"><a href="#L69">69</a></th><td>    BOOST_ARCHIVE_DECL(void)</td></tr><tr><th id="L70"><a href="#L70">70</a></th><td>    init();</td></tr><tr><th id="L71"><a href="#L71">71</a></th><td>    BOOST_ARCHIVE_DECL(BOOST_PP_EMPTY()) </td></tr><tr><th id="L72"><a href="#L72">72</a></th><td>    text_iarchive_impl(std::istream &amp; is, unsigned int flags);</td></tr><tr><th id="L73"><a href="#L73">73</a></th><td>    BOOST_ARCHIVE_DECL(BOOST_PP_EMPTY()) </td></tr><tr><th id="L74"><a href="#L74">74</a></th><td>    ~text_iarchive_impl(){};</td></tr><tr><th id="L75"><a href="#L75">75</a></th><td>};</td></tr><tr><th id="L76"><a href="#L76">76</a></th><td></td></tr><tr><th id="L77"><a href="#L77">77</a></th><td>// do not derive from the classes below.  If you want to extend this functionality</td></tr><tr><th id="L78"><a href="#L78">78</a></th><td>// via inhertance, derived from text_iarchive_impl instead.  This will</td></tr><tr><th id="L79"><a href="#L79">79</a></th><td>// preserve correct static polymorphism.</td></tr><tr><th id="L80"><a href="#L80">80</a></th><td></td></tr><tr><th id="L81"><a href="#L81">81</a></th><td>// same as text_iarchive below - without the shared_ptr_helper</td></tr><tr><th id="L82"><a href="#L82">82</a></th><td>class naked_text_iarchive : </td></tr><tr><th id="L83"><a href="#L83">83</a></th><td>    public text_iarchive_impl&lt;naked_text_iarchive&gt;</td></tr><tr><th id="L84"><a href="#L84">84</a></th><td>{</td></tr><tr><th id="L85"><a href="#L85">85</a></th><td>public:</td></tr><tr><th id="L86"><a href="#L86">86</a></th><td>    naked_text_iarchive(std::istream &amp; is, unsigned int flags = 0) :</td></tr><tr><th id="L87"><a href="#L87">87</a></th><td>        text_iarchive_impl&lt;naked_text_iarchive&gt;(is, flags)</td></tr><tr><th id="L88"><a href="#L88">88</a></th><td>    {}</td></tr><tr><th id="L89"><a href="#L89">89</a></th><td>    ~naked_text_iarchive(){}</td></tr><tr><th id="L90"><a href="#L90">90</a></th><td>};</td></tr><tr><th id="L91"><a href="#L91">91</a></th><td></td></tr><tr><th id="L92"><a href="#L92">92</a></th><td>} // namespace archive</td></tr><tr><th id="L93"><a href="#L93">93</a></th><td>} // namespace boost</td></tr><tr><th id="L94"><a href="#L94">94</a></th><td></td></tr><tr><th id="L95"><a href="#L95">95</a></th><td>// note special treatment of shared_ptr. This type needs a special</td></tr><tr><th id="L96"><a href="#L96">96</a></th><td>// structure associated with every archive.  We created a "mix-in"</td></tr><tr><th id="L97"><a href="#L97">97</a></th><td>// class to provide this functionality.  Since shared_ptr holds a</td></tr><tr><th id="L98"><a href="#L98">98</a></th><td>// special esteem in the boost library - we included it here by default.</td></tr><tr><th id="L99"><a href="#L99">99</a></th><td>#include &lt;boost/archive/shared_ptr_helper.hpp&gt;</td></tr><tr><th id="L100"><a href="#L100">100</a></th><td></td></tr><tr><th id="L101"><a href="#L101">101</a></th><td>namespace boost { </td></tr><tr><th id="L102"><a href="#L102">102</a></th><td>namespace archive {</td></tr><tr><th id="L103"><a href="#L103">103</a></th><td></td></tr><tr><th id="L104"><a href="#L104">104</a></th><td>class text_iarchive : </td></tr><tr><th id="L105"><a href="#L105">105</a></th><td>    public text_iarchive_impl&lt;text_iarchive&gt;,</td></tr><tr><th id="L106"><a href="#L106">106</a></th><td>    public detail::shared_ptr_helper</td></tr><tr><th id="L107"><a href="#L107">107</a></th><td>{</td></tr><tr><th id="L108"><a href="#L108">108</a></th><td>public:</td></tr><tr><th id="L109"><a href="#L109">109</a></th><td>    text_iarchive(std::istream &amp; is, unsigned int flags = 0) :</td></tr><tr><th id="L110"><a href="#L110">110</a></th><td>        text_iarchive_impl&lt;text_iarchive&gt;(is, flags)</td></tr><tr><th id="L111"><a href="#L111">111</a></th><td>    {}</td></tr><tr><th id="L112"><a href="#L112">112</a></th><td>    ~text_iarchive(){}</td></tr><tr><th id="L113"><a href="#L113">113</a></th><td>};</td></tr><tr><th id="L114"><a href="#L114">114</a></th><td></td></tr><tr><th id="L115"><a href="#L115">115</a></th><td>} // namespace archive</td></tr><tr><th id="L116"><a href="#L116">116</a></th><td>} // namespace boost</td></tr><tr><th id="L117"><a href="#L117">117</a></th><td></td></tr><tr><th id="L118"><a href="#L118">118</a></th><td>// required by export</td></tr><tr><th id="L119"><a href="#L119">119</a></th><td>BOOST_SERIALIZATION_REGISTER_ARCHIVE(boost::archive::text_iarchive)</td></tr><tr><th id="L120"><a href="#L120">120</a></th><td></td></tr><tr><th id="L121"><a href="#L121">121</a></th><td>#include &lt;boost/archive/detail/abi_suffix.hpp&gt; // pops abi_suffix.hpp pragmas</td></tr><tr><th id="L122"><a href="#L122">122</a></th><td></td></tr><tr><th id="L123"><a href="#L123">123</a></th><td>#endif // BOOST_ARCHIVE_TEXT_IARCHIVE_HPP</td></tr></tbody></table>
      </div>
      <div id="help">
        <strong>Note:</strong> See <a href="/trac/boost/wiki/TracBrowser">TracBrowser</a>
        for help on using the browser.
      </div>
      <div id="anydiff">
        <form action="/trac/boost/diff" method="get">
          <div class="buttons">
            <input type="hidden" name="new_path" value="/branches/release/boost/archive/text_iarchive.hpp" />
            <input type="hidden" name="old_path" value="/branches/release/boost/archive/text_iarchive.hpp" />
            <input type="hidden" name="new_rev" value="41369" />
            <input type="hidden" name="old_rev" value="41369" />
            <input type="submit" value="View changes..." title="Select paths and revs for Diff" />
          </div>
        </form>
      </div>
    </div>
    <div id="altlinks">
      <h3>Download in other formats:</h3>
      <ul>
        <li class="last first">
          <a rel="nofollow" href="/trac/boost/export/48390/branches/release/boost/archive/text_iarchive.hpp">Original Format</a>
        </li>
      </ul>
    </div>
    </div>
    <div id="footer" lang="en" xml:lang="en"><hr />
      <a id="tracpowered" href="http://trac.edgewall.org/"><img src="/trac/boost/chrome/common/trac_logo_mini.png" height="30" width="107" alt="Trac Powered" /></a>
      <p class="left">
        Powered by <a href="/trac/boost/about"><strong>Trac 0.11</strong></a><br />
        By <a href="http://www.edgewall.org/">Edgewall Software</a>.
      </p>
      <p class="right">Visit the Trac open source project at<br /><a href="http://trac.edgewall.org/">http://trac.edgewall.org/</a></p>
    </div>
  </body>
</html>