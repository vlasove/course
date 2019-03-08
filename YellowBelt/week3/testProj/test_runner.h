#ifndef TEST_RUNNER
#define TEST_RUNNER

// operator << reloading for map and set
template <class Key, class Value>
ostream &operator<<(ostream &os, const map<Key, Value> &m)
{
    os << "{";
    bool first = true;
    for (const auto &item : m)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << item.first << ": " << item.second;
    }
    return os << '}';
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &item : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << s;
    }
    return os << '}';
}

//Template For testing framework:
template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint)
{
    if (t != u)
    {
        ostringstream ss;
        ss << "Assertion failed: " << t << " != " << u << ". Hint: " << hint;
        throw runtime_error(ss.str());
    }
}

void Assert(bool b, const string &hint)
{
    AssertEqual(b, true, hint);
}

//Template for exceptions:
class TestRunner
{
  public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string &testName)
    {
        try
        {
            func();
            cerr << testName << " OK!" << endl;
        }
        catch (runtime_error &e)
        {
            fail_count++;
            cerr << testName << " failed: " << e.what() << endl;
        }
    }
    ~TestRunner()
    {
        if (fail_count > 0)
        {
            cerr << fail_count << " tests failed. Terminate" << endl;
            exit(1);
        }
    }

  private:
    int fail_count = 0;
};

#endif