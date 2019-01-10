class SortedStrings {
public:
  void AddString(const string& s) {
    bag.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
    sort(begin(bag), end(bag));
    return bag;
  }
private:
    vector<string> bag;
};