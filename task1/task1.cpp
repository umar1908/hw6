#include <iostream>
#include <fstream>
using namespace std;

void file_print(fstream& file){
  file.seekp(0,ios::beg);
  cout<<file.tellg();
  if(!file){
    cout<<"err";
  }
  string out_str;
  while(file){
    getline(file,out_str);
    cout<<out_str<<endl;
  }
}


int main(){
  system("chcp 1251");

  fstream file("file3.cpp", ios::in|ios::out|ios::binary);
  if (!file){
    cout<<"open err";
  }

  bool not_str=true;
  bool in_multycomm =false;
  string curr_str;
  char curr_char;
  char next_char;
  char prev_char='\0';
  while(file.get(curr_char)){
    if(!file.get(next_char)){
      // cout<<file.tellg();
      break;
    }
    if((curr_char=='/') && (next_char=='/') && (not_str) && (!in_multycomm) ){
      file.seekg(-2,ios::cur);
      //дл€ нашл€дности не удал€ю символы //, а замен€ю их на знак $$ (можно заменить на "  ")
      file<<"$$";
      file.seekg(0,ios::cur);
      getline(file, curr_str);
    }
    else{
      file.seekg(-1,ios::cur);
    }
    if ((curr_char=='"') && (prev_char!='\\') && (!in_multycomm)){
      if (not_str){
        not_str=false;
      }
      else{
        not_str=true;
      }
    }

    if ((curr_char=='/') && (next_char=='*') && (not_str) && (!in_multycomm)){
      in_multycomm=true;
      file.seekp(-1,ios::cur);
      //дл€ нагл€дности не удал€ю символ начала многострочного комментари€ /* а
                        // замен€ю его на ## (можно заменить на "  ")
      file<<"##";

    }

    if ((curr_char=='*') && (next_char=='/') && (not_str) && (in_multycomm)){
      in_multycomm=false;
      file.seekp(-1,ios::cur);
      //дл€ нагл€дности не удал€ю символ конца многострочного комментари€ /*
                          //а замен€ю его на && (можно заменить на "  ")
      file<<"&&";
    }

    prev_char=curr_char;





  }


  //не знаю почему, но вывести файл после преобразовани€ получаетс€ только после
  //закрати€ и повторного открыти€ файла.
  file.close();
  file.open("file3.cpp");
  file.seekg(0,ios::beg);



  file_print(file);
  file.close();









}
