#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int str_to_int(string &s, int begin, int end){ //Принимает строку и индексы первого и последнего символов, между которыми в ней (предположительно) записано число (последний не включительно).
    int val = 0;                //Возвращает объект типа int, значение которого равно этому числу.
    bool negative = 0;          //Является ли число отрицательным?
    if(s[begin] == '+') begin++;//Плюс игнорируется.
    else{
        if(s[begin] == '-'){    //Проверка на отрицательность.
            negative = 1;
            begin++;
        }
    }
    for(auto i = begin; i < end; ++i){   //Обработка самих цифр числа.
        val *= 10;
        val += s[i] - 48;
    }
    if(val == 0 && s[begin] != '0') val++; //Если значение получилось равным нулю, но в исходной строке не только ноль, значит, обрабатывается строка вида "+x", в которой при записи опускается единица
    if(negative == 1) val *= -1;
    return val;
}
 
string int_to_str(int val){ //Возвращает строку с записанным в ней числом val.
    string s, tmp;
    if(val > 0) s.push_back('+'); //Проверка на отрицательность.
    else{
        val *= -1;
        s.push_back('-');
    }
    while(val > 0){
        tmp.push_back(val%10 + 48);  //В tmp хранится запись числа в обратном порядке.
        val /= 10;
    }
    for(int i = tmp.size()-1; i >= 0; --i){ //Переписывание элементво из tmp в s в верном порядке.
        s.push_back(tmp[i]);
    }
    return s;
}
 
void erase_the_plus(string &s){  //Удаляет плюс, стоящий в начале строки.
    if(s[0] == '+') s.erase(s.begin());
}
 
void erase_the_one(string &s){   //Удаляет единицу из строк вида "+1", "-1".
    if((s[1] == '1') && (s.size() == 2)) s.erase(s.begin()+1);
}
 
void analyze(string &s, vector <int> &v){  //Анализирует строку и увеличивает соответствующие элементы вектора на коэфициенты при степенях х.
    if(s.find("x") == string::npos) v[0] += str_to_int(s, 0, s.size()); //Если в строке содержится запись константаы.
    else{
        if(s.find("^") == string::npos) v[1] += str_to_int(s, 0, s.find("x"));  //Строка вида "ax".
        else{
            int power = str_to_int(s, s.find("^") + 1, s.size()); //Строка вида "ax^y".
            v[power] += str_to_int(s, 0, s.find("x"));
        }
    }
}
 
vector <int> decompose(string &s){ //Разбивает многочлен на слагаемые и возвращает вектор, индексы элементов которого соответствуют степеням х, а сами элементы - коэффициентам при них.
    vector <int> v(11);
    string cur_s;
    int i = 0;
    while(i < s.size()){
        cur_s.clear();
        cur_s.push_back(s[i]);
        i++;
        while((s[i] != '+') && (s[i] != '-') && (i < s.size())){ //cur_s - анализируемое в данный момент слагаемое.
            cur_s.push_back(s[i]);
            i++;
        }
        analyze(cur_s, v);
    }
    return v;
}
 
vector <int> multiplicate (vector <int> &a, vector <int> &b){ //Умножение многочленов.
    vector <int> c(21);       //Возвращает вектор, индексы элементов которого соответствуют степеням х, а сами элементы - коэффициентам при них.
    for(int i = 0; i < c.size(); ++i) c[i] = 0;
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < b.size(); ++j){
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}
 
string compose(vector <int> &v){ //Из элементов вектора составляет строку, в которой записан многочлен.
    string s;
    for(int i = v.size() - 1; i >= 2; --i){
        if(v[i] != 0){
            string coef = int_to_str(v[i]); //Коэффициент.
            erase_the_one(coef);
            s = s + coef;
            s.push_back('x');
            s.push_back('^');
            string power = int_to_str(i);  //Степень х.
            erase_the_plus(power);
            s = s + power;
        }
    }
    if(v[1] != 0){   //Записи слагаемых с первой и нулевой степенями х отличаются.
        string coef = int_to_str(v[1]);
        erase_the_one(coef);
        s = s + coef;
        s.push_back('x');
    }
    if(v[0] != 0){
        s = s + int_to_str(v[0]);
    }
    return s;
}
 
int main() {
    string a,b;
    vector <int> a_decomposed(11, 0);
    vector <int> b_decomposed(11, 0);
    getline(cin, a);    //Ввод многочленов.
    getline(cin, b);
    a_decomposed = decompose(a);
    b_decomposed = decompose(b);
    vector <int> c_decomposed = multiplicate(a_decomposed, b_decomposed);
    string c = compose(c_decomposed);
    erase_the_plus(c);  //Удаляется первый плюс, если он есть.
    if(c.size() > 0) cout << c;
    else cout << 0;       //Если в ответе получаем константу 0.
    return 0;
}