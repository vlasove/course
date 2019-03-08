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







void TestConstruct(){
  {
    Rational rat;
    Assert((rat.Numerator() == 0 && rat.Denominator() == 1), "First Constructor Test");
  }
  {
    Rational rat(2,3);
    Assert((rat.Numerator() == 2 && rat.Denominator() == 3), "Second Constructor Test");

  }
  {
    Rational rat(2,4);
    Assert((rat.Numerator() == 1 && rat.Denominator() == 2), "Third Constructor Test");

  }
  {
    Rational rat(12,24);
    Assert((rat.Numerator() == 1 && rat.Denominator() == 2), "4-th Constructor Test");
  }
}

void TestMinus(){
  {
    Rational rat(-1,2);
    Assert((rat.Numerator() == -1 && rat.Denominator() == 2), "First Minus Test");
    
  }
  {
    Rational rat(2,-3);
    Assert((rat.Numerator() == -2 && rat.Denominator() == 3), "Second Minus Test");
    
  }
  {
    Rational rat(2,-4);
    Assert((rat.Numerator() == -1 && rat.Denominator() == 2), "Third Minus Test");
    
  }
}

void TestPlus(){
  {
    Rational rat(1,2);
    Assert((rat.Numerator() == 1 && rat.Denominator() == 2), "First Plus Test");
    
  }
  {
    Rational rat(-1,-2);
    Assert((rat.Numerator() == 1 && rat.Denominator() == 2), "Second Plus Test");
    
  }

}

void TestZeroNumerator(){
  {
    Rational rat(0,20000);
    Assert((rat.Numerator() == 0 && rat.Denominator() == 1), "First ZeroNumerator Test");
    
  }
  {
    Rational rat(0,-30000);
    Assert((rat.Numerator() == 0 && rat.Denominator() == 1), "Second ZeroNumerator Test");
    
  }

  {
    Rational rat(-0,-3);
    Assert((rat.Numerator() == 0 && rat.Denominator() == 1), "Third ZeroNumerator Test");
    
  }

}

void TestAll(){
  TestRunner tr;
  tr.RunTest(TestConstruct, "TestConstruct");
  tr.RunTest(TestMinus, "TestMinus");
  tr.RunTest(TestPlus,"TestPlus");
  tr.RunTest(TestZeroNumerator,"TestZeroNumerator");
}

int main() {
  TestAll();
  // добавьте сюда свои тесты
  return 0;
}