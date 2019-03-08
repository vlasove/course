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



void NamePred(){
  Person person;
  person.ChangeFirstName(1966, "Kek");
  person.ChangeLastName(1977, "Lol");

  AssertEqual(person.GetFullName(1965), "Incognito", "First Empty name test");
  AssertEqual(person.GetFullName(1966), "Kek with unknown last name", "Second Empty name test");
  AssertEqual(person.GetFullName(1976), "Kek with unknown last name", "Third Empty name test");
  AssertEqual(person.GetFullName(1978), "Kek Lol", "Fourth Empty name test");
}

void SurnamePred(){
  Person person;
  person.ChangeLastName(1966, "Kek");
  person.ChangeFirstName(1977, "Lol");

  AssertEqual(person.GetFullName(1965), "Incognito", "First Empty Surname test");
  AssertEqual(person.GetFullName(1966), "Kek with unknown first name", "Second Empty Surname test");
  AssertEqual(person.GetFullName(1976), "Kek with unknown first name", "Third Empty Surname test");
  AssertEqual(person.GetFullName(1978), "Lol Kek", "Fourth Empty Surname test");

}

void TestChanger(){
  Person person;
  person.ChangeFirstName(1966, "Kek");
  person.ChangeLastName(1967, "Lol");

  AssertEqual(person.GetFullName(1970), "Kek Lol", "First Changer Test");

  person.ChangeFirstName(1975, "Polina");
  AssertEqual(person.GetFullName(1972), "Kek Lol", "Second Changer Test");
  AssertEqual(person.GetFullName(1975), "Polina Lol", "Third Changer Test");
  AssertEqual(person.GetFullName(1979), "Polina Lol", "Fourth Changer Test");


  person.ChangeLastName(1980, "Petrova");
  person.ChangeFirstName(1985, "Appolony");
  AssertEqual(person.GetFullName(1980), "Polina Petrova", "5-th Changer Test");
  AssertEqual(person.GetFullName(1984), "Polina Petrova", "6-th Changer Test");
  AssertEqual(person.GetFullName(1987), "Appolony Petrova", "7-th Changer Test");


}


void TestAll(){
  TestRunner tr;
  tr.RunTest(NamePred,"NamePred");
  tr.RunTest(SurnamePred,"SurnamePred");
  tr.RunTest(TestChanger,"TestChanger");
}

int main() {
  TestAll();
  //TestRunner runner;
  // добавьте сюда свои тесты
  return 0;
}