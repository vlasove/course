#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;




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

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{

        SortedStrings strings;
  
        strings.AddString("first");
        strings.AddString("third");
        strings.AddString("second");
        PrintSortedStrings(strings);
        
        strings.AddString("second");
        PrintSortedStrings(strings);
    
    return 0;
}
