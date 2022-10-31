#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// since I'm just doing a demo project, I'm using std namespace throughout the project to provide some productivity, this will be re-written later without using namespace std.
using namespace std;

class Vitian{
private:
  string name;
  string reg_no;
  int current_year;
  string course;
  string school;
  string specialization;

public:
  Vitian(
    string name,
    string reg_no,
    int current_year,
    string course,
    string school,
    string specialization
    ){
      this->name = name;
      this->reg_no = reg_no;
      this->current_year = current_year;
      this->course = course;
      this->school = school;
      this->specialization = specialization;
    }
  
  // getters and setters

  string get_name(){
    return this->name;
  }

  void put_name(string name){
    this->name = name;
  }

  string get_reg_no(){
    return this->reg_no;
  }

  void put_reg_no(string reg_no){
    this->reg_no = reg_no;
  }

  int get_current_year(){
    return this->current_year;
  }

  void put_current_year(int current_year){
    this->current_year = current_year;
  }

  string get_course(){
    return this->course;
  }
  
  void put_course(string course){
    this->course = course;
  }

  string get_school(){
    return this->school;
  }

  void put_school(string school){
    this->school = school;
  }

  string get_specialization(){
    return this->specialization;
  }

  void put_specialization(string specialization){
    this->specialization = specialization;
  }

};

class VitianNode{
public:
  char reg_no_char;
  unordered_map<char, VitianNode*> children;
  Vitian* contents;

  VitianNode(char reg_no_char){
    this->reg_no_char = reg_no_char;
    contents = nullptr;
  }
};

class Trie{

private:
  VitianNode* root;

public:
  Trie(){
    root = new VitianNode('\0');
  }

  void insert(string reg_no){
    VitianNode* copy_root = root;
    for(int i=0; i<reg_no.size(); i++){
      // to check whether a character exists

      if(copy_root->children.count(reg_no[i])){
        copy_root = copy_root->children[reg_no[i]];
      } else {
        VitianNode* copy_root_new = new VitianNode(reg_no[i]);
        copy_root->children[reg_no[i]] = copy_root_new;
        copy_root = copy_root_new;
      }

    }
    
    string name;
    int current_year;
    string course;
    string school;
    string specialization;

    cout << "Enter Name :";
    cin>>name;
    cout << "Enter Current Year of Study :";
    cin>>current_year;
    cout << "Enter Course Name :";
    cin>>course;
    cout << "Enter School Name :";
    cin>>school;
    cout << "Enter Specialization :";
    cin>>specialization;

    copy_root->contents = new Vitian(name, reg_no, current_year, course, school, specialization);
  }

  Vitian* find(string reg_no){
    VitianNode* copy_root = root;
    for(int i=0; i<reg_no.size(); i++){
      if(copy_root->children.count(reg_no[i])){
        copy_root = copy_root->children[reg_no[i]];
      } else {
        return copy_root->contents;
      }
    }
    return copy_root->contents;
  }

};  

int main(){
  
  Trie vit_search;

  int choice = 1;

  while(choice){
    cout << "\nEnter Your Choice:\n0 => End \n1 => Insertion \n2 => Searching\nChoice :";
    cin>>choice;
    string reg_no;
    if(choice ==  1){
      cout << "Enter Registration Number :";
      cin>>reg_no;
      vit_search.insert(reg_no);
    } else if(choice == 2){
      cout << "Enter Registration Number :";
      cin>>reg_no;
      Vitian* vitian_obj = vit_search.find(reg_no);
      cout << "\nDetails are as follows,\n";
      cout << "Name :" << vitian_obj->get_name() << "\n";
      cout << "Registration Number :" << vitian_obj->get_reg_no() << "\n";
      cout << "Current Year :" << vitian_obj->get_current_year() << "\n";
      cout << "Course :" << vitian_obj->get_course() << "\n";
      cout << "School :" << vitian_obj->get_school() << "\n";
      cout << "Specialization: " << vitian_obj->get_specialization() << "\n";
    }
  }

  cout << "\nThank you for stopping by <3 \nCome back soon!";

  return 0;
}