#include <iostream>
#include <map>
#include <ostream>
#include <random>
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


//Testing function
int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  if (a != 0){
      auto D = b*b - 4*a*c;
      if (D< 0){
        return 0;
      }else if (D == 0){
        return 1;
      }else {
        return 2;
      }
  } else {
    if (b != 0){
      return 1;
    }else{
      return 0;
    }
  
  }
}

//Root Counter test
void TestRootCount(){
  // >=0 and <= 2
  mt19937 gen;
  uniform_real_distribution<> unif(-100, 100);

  for(auto i = 0; i < 1000; i++){
    const auto a = unif(gen);
    const auto b = unif(gen);
    const auto c = unif(gen);

    const auto count = GetDistinctRealRootCount(a,b,c);
    //cout<<a<<"^2 +"<<b<<"+ "<<c<<"= 0 has "<<count<<" solutions."<<endl;
    Assert((count>=0 && count <=2), "QuadraticExpr has >=0 and <=2 solutions");
  }
}
//Test for 1 root
void TestOneRoot(){
  mt19937 gen;
  uniform_real_distribution<> unif(-100, 100);

   for(auto i = 0; i < 1000; i++){
    const auto x1 = unif(gen);
    const auto p = -(x1+x1);
    const auto q = x1*x1;

    const auto count = GetDistinctRealRootCount(1,p,q);
    //cout<<a<<"^2 +"<<b<<"+ "<<c<<"= 0 has "<<count<<" solutions."<<endl;
    stringstream ss;
    ss << showpos<<"x^2 +"<<p<<"x + "<<q<<" = 0";
    AssertEqual(count,1, ss.str());
  }
}

void TestNoRoots(){
  AssertEqual(GetDistinctRealRootCount(2,1,2), 0, "First NO-root test");
  AssertEqual(GetDistinctRealRootCount(1,0,1), 0, "Second No-root test");
  AssertEqual(GetDistinctRealRootCount(0,0,1), 0, "Third N0-root test");
}

void TestLinear(){
  AssertEqual(GetDistinctRealRootCount(0,2,1), 1, "First linear test");
  AssertEqual(GetDistinctRealRootCount(0,1,1), 1, "Second linear test");
  AssertEqual(GetDistinctRealRootCount(0,2,0), 1, "Third linear test");

}

void TestConst(){
  AssertEqual(GetDistinctRealRootCount(0,0,1),0, "First const test");
  AssertEqual(GetDistinctRealRootCount(0,0,12222222),0, "Second const test");
  AssertEqual(GetDistinctRealRootCount(0,0,99999999),0, "Third const test");

}

void TestAll(){
  TestRunner tr;
  tr.RunTest(TestRootCount, "TestRootCount");
  tr.RunTest(TestOneRoot, "TestOneRoot");
  tr.RunTest(TestNoRoots,"TestNoRoots");
  tr.RunTest(TestLinear,"TestLinear");
  tr.RunTest(TestConst,"TestConst");

}

int main() {
    TestRunner tr;
    tr.RunTest(TestRootCount, "TestRootCount");
    tr.RunTest(TestOneRoot, "TestOneRoot");
    tr.RunTest(TestNoRoots,"TestNoRoots");
    tr.RunTest(TestLinear,"TestLinear");
    tr.RunTest(TestConst,"TestConst");
  
    return 0;
}
