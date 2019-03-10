#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Lang
{
    string name;
    int age;
};

int main()
{

    vector<Lang> langs = {
        {"Python", 26},
        {"C++", 34},
        {"Java", 22},
        {"C#", 17}
        };

    auto result = find_if(langs.begin(), langs.end(),
                          [](const Lang &lang) {
                              return lang.name[0] == 'C';
                          });
    if(result == langs.end()){
        cout<<"Can not be found!"<<endl;
       
    }else{
        cout << result->age << endl; 

    }
    cout<<"Begin Part"<<endl;
    cout << langs.begin()->name <<endl;
    

    return 0;
}