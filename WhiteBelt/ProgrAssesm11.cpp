#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add_issue(vector<string>& v, int d, string issue){
    int real_date = d-1;
    if(v[real_date].empty()){
        v[real_date] = issue;
    }else{
        v[real_date]+=(" "+issue);
    }
    
}

void PrintIssue(const vector<string>& v, int d){
    int real_date = d - 1;
    int issue_counter = 0;

    if (v.size() < real_date){
        cout << issue_counter <<endl;

    }else{

            if(v[real_date].empty()){
                 cout << 0 <<endl;
            }else{
            for(char s : v[real_date]){
                if(s ==' '){
                    ++issue_counter;
                }
            }   
    cout<<issue_counter+1<<" "<<v[real_date]<<endl;

    }

    }

}
 

void next_month(vector<string>& v, int c){
    vector<int> dim = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<string> new_v = v;
    int pntr = c;
    int next_pntr = c + 1;

    if(c == 11){
        next_pntr = 0;
    }
    new_v.resize(dim[next_pntr]);
   // new_v[dim[next_pntr]] = "";

   // for (auto s : new_v){
    //    cout<<s<<" ";
   // }
    //vector<string> new_calendar = v.resize(dim[c+1]);
   // cout<<"The last day"<< new_v[28]<<endl;
    if (dim[pntr] > dim[next_pntr]){
        //new_v.insert(end(new_v), begin(v[dim[c+1] - 1]), end(v[dim[c] - 1]));

        for (int i = dim[next_pntr]; i <= dim[pntr]; i++){
            if(v[i-1].empty()){
                continue;
            }
            if (i == dim[next_pntr]){

                if(new_v[dim[next_pntr] - 1] == (v[i-1])){
                         new_v[dim[next_pntr] - 1] +=" ";
                         continue;

                     }
                // cout<<"The last day"<< new_v[28]<<endl;
            ///if(new_v[new_v.size()-1] == (v[i-1])){
                  //  continue;
               // }else{
                    ////new_v[new_v.size()] += ((v[i-1]));
                    //break;
                    //new_v[new_v.size()-1] += " ";
                
                }else{
                     //cout<<"The last day"<< new_v[28]<<endl;
                     
                new_v[dim[next_pntr] - 1] += (v[i-1]);
                if(i != dim[pntr] && v[i-1].empty()){
                    new_v[dim[next_pntr] - 1] += " ";

                }
            //cout<<"Working!!!"<<endl;
            }

            
            
        }
    }
    //new_v.resize(dim[next_pntr]-1);
   // for(auto s: new_v){
    //            cout << s<<" ";
    //        }

    v = new_v;
    //cout << v.size()<<endl;
}

int main(int argc, char const *argv[])
{   
    vector<string> calendar(31);
    int n; // command counter
    cin >> n;
    //vector<int> days_in_months = {31,28,31,30,31,30,31,31,30,31,30,31}

    string command;
    int date;
    string issue;
    int next_counter = 0;
    for (int i = 0; i < n; i++){
        // default 31 days in this month, untill NEXT command
        cin >> command;
        //if (command == "NEXT"){
       //     next_issue(calendar, next_counter);
        //    }
       // }
        if (command == "ADD"){
            cin>>date>>issue;
            add_issue(calendar, date, issue);
        }
        if (command == "DUMP"){
            cin>>date;
            PrintIssue(calendar, date);
        }

        if (command == "NEXT"){
            next_month(calendar,next_counter);
            next_counter++;
            if (next_counter > 11){
                next_counter = next_counter - 12;
            }
        }
    }
    
    



    return 0;
}
