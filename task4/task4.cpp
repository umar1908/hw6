#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
// #include<random>
#include<sstream>
// #include"json.hpp"
#include<iterator>
#include<filesystem>
#include<fstream>
struct Person;
string Person_to_json(const Person&,bool with_relatives=false,size_t ident=0);
void save_person(const Person&);

struct Person{
  string name;
  string surname;
  unsigned int age;
  string passport;
  bool student;
  vector<Person> relatives;
  Person()=default;
  friend istream& operator>>(istream& is, Person& person){
    cout<<"Введите имя:\n";
    is>>person.name;
    cout<<"Введите фамилию:\n";
    is>>person.surname;
    cout<<"Введите возраст:\n";
    is>>person.age;
    cout<<"Введите пасспорт:\n";
    is>>person.passport;
    cout<<"Студент? (true или false)\n";
    is>>boolalpha>>person.student;
    cout<<"Введите количество роственников\n";
    size_t n;
    cin>>n;
    if(n>0){
      cout<<"Введите данные каждого родственника:\n";
    }
    for (size_t i = 0; i < n; i++) {
      cout<<"Родственник № "<<i+1<<endl;
      Person buff;
      cin>>buff;
      person.relatives.push_back(buff);
    }
    return is;
  }
  Person(string name_,string surname_, unsigned int age_, string passport_,bool student_):
                                                      name(name_),surname(surname_),age(age_),
                                                      passport(passport_),student(student_){};
};


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  cout<<endl;
  cout<<"Сколько человек вы хотите добавить?\n";
  size_t t;
  cin>>t;
  for (size_t i = 0; i < t; i++) {
    cout<<"Введите данные чекловека №"<<i+1<<endl;
    Person buff;
    cin>>buff;
    save_person(buff);
  }

}



void save_person(const Person& p){
  if(!filesystem::exists("./Persons")){
    filesystem::create_directory("Persons");
  }
  string json=Person_to_json(p,true);
  fstream file("Persons\\"+p.name+".txt",ios::out);
  if(!file){
    cout<<"Error!";
    // return EXIT_FAILURE;
  }
  copy(json.begin(),json.end(),ostream_iterator<char>(file));
  file.close();
  cout<<"Person "<<p.name<<" successfully saved\n\n";
}




string Person_to_json(const Person&p,bool with_relatives,size_t ident ){
  string json="";
  stringstream str;
  auto paste_ident=[](stringstream& str,size_t n){for (size_t i = 0; i < n; i++) {
    str<<'\t';
  }};


  paste_ident(str,ident);
  str<<"{\n";
  json.append(str.str());
  ident++;
  str.str("");
  str.clear();



  paste_ident(str,ident);
  str<<"\"name:\"  "<<"\""<<p.name<<"\","<<endl;
  json.append(str.str());
  str.str("");
  str.clear();

  paste_ident(str,ident);
  str<<"\"surname:\"  "<<"\""<<p.surname<<"\","<<endl;
  json.append(str.str());
  str.str("");
  str.clear();


  paste_ident(str,ident);
  str<<"\"age:\"  "<<p.age<<','<<endl;
  json.append(str.str());
  str.str("");
  str.clear();

  paste_ident(str,ident);
  str<<"\"passport:\"  "<<"\""<<p.passport<<"\","<<endl;
  json.append(str.str());
  str.str("");
  str.clear();

  paste_ident(str,ident);
  str<<boolalpha<<"\"student:\"  "<<p.student<<','<<endl;
  json.append(str.str());
  str.str("");
  str.clear();

  if(with_relatives){
    paste_ident(str,ident);
    str<<"\"relatives:\" ["<<endl;
    ident++;
    for(const auto& elem:p.relatives){
      str<<Person_to_json(elem,with_relatives=false,ident)<<",\n";
    }
    ident--;
    str<<endl;
    paste_ident(str,ident);
    str<<"],\n";
    json.append(str.str());
    str.str("");
    str.clear();
  }

  paste_ident(str,ident-1);
  str<<'}';
  json.append(str.str());
  ident--;
  return json;

}
