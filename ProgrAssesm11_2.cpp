#include <iostream>
#include <string>
#include <vector>

using namespace std;

void next_func(vector<string>& v, int& dm){


    int next_days_pointer;
    vector<int> days_in_months = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(dm == (days_in_months.size()-1) ){
        next_days_pointer = 0;
    }else{
        next_days_pointer = dm+1;
    }
    vector<string> new_v(days_in_months[next_days_pointer]);

    if(days_in_months[next_days_pointer] < days_in_months[dm]){
        //vector<string> new_v(days_in_months[next_days_pointer]);
        for(int i = 0; i < (days_in_months[next_days_pointer]-1); i++){
            new_v[i] = v[i];
        }
        for(int i = (days_in_months[next_days_pointer]-1); i < days_in_months[dm]; i++){
            if(new_v[days_in_months[next_days_pointer]-1].empty()){
                new_v[days_in_months[next_days_pointer]-1]+=v[i];
                continue;
            }

            if(!new_v[days_in_months[next_days_pointer]-1].empty() && !v[i].empty()){
                new_v[days_in_months[next_days_pointer]-1]+=(" "+v[i]);
            }
            //new_v[days_in_months[next_days_pointer]-1]+=v[i]
        }
    }else{
        //vector<string> new_v(days_in_months[next_days_pointer]);
        for(int i = 0; i < days_in_months[dm]; i++){
            new_v[i] = v[i];

        }
    }
    dm = next_days_pointer;
    v.clear();
    v = new_v;
}

void dump_func(const vector<string>& v, int date){
    int real_date = date - 1;
    int counter = 1;
    if(v[real_date].empty()){
        cout<<0<<endl;
    }else{
        for(char s : v[real_date]){
            if(s==' '){
                counter++;
            }
        }
        cout<<counter<<" "<<v[real_date]<<endl;
    }
}

void add_func(vector<string>& v, int date, string issue){
    int real_date = date - 1;
    if(v[real_date].empty()){
        v[real_date] = issue;
    }else{
        v[real_date]+=" "+issue;
    }
    
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<string> calendar(31);
    
    

    int day, month_counter;
    string issue, command;
    month_counter = 0;

    for (int i = 0; i < n; i++){
        cin >> command;
        if(command == "ADD"){
            cin>>day>>issue;
            add_func(calendar, day,issue);
        }

        if(command == "DUMP"){
            cin>>day;
            dump_func(calendar, day);
        }

        if(command == "NEXT"){
            next_func(calendar, month_counter);
        }
    }

    




    return 0;
}
