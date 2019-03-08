#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};



void TestSingle(){
  
  Assert(IsPalindrom(""), "1-st empty test");
  Assert(IsPalindrom(" "), "2-nd empty test");
  Assert(IsPalindrom("a"), "3-rd empty test");
  Assert(!IsPalindrom("ab"), "4-th empty test");
  
}

void TestSpaced(){
  Assert(IsPalindrom(" a "), "1-st spaced test");
  Assert(!IsPalindrom("  a "), "2-nd spaced test");
  Assert(IsPalindrom(" abc cba "), "3-rd spaced test");
  Assert(!IsPalindrom("abc cba "), "4-th spaced test");
  Assert(IsPalindrom("   a b a   "), "5-th space stest");
  Assert(IsPalindrom("    "), "6-th space stest");
  Assert(!IsPalindrom("  ab  "), "7-th space stest");


}

void TestGeneral(){
  Assert(IsPalindrom("abcba"), "1-st general test");
  Assert(!IsPalindrom("bcba"), "2-nd general test");
  Assert(IsPalindrom("madam"), "3-rd general test");
  Assert(!IsPalindrom("baobab"), "4-th general test");
}

void TestAll(){
  TestRunner tr;
  tr.RunTest(TestSingle,"TestSingle");
  tr.RunTest(TestSpaced,"TestSpaced");
  tr.RunTest(TestGeneral,"TestGeneral");

}



int main() {
  TestAll();
  // добавьте сюда свои тесты
  return 0;
}
