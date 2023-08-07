#include <iostream>
#include <string>
#include <map>
using namespace std;

// contact maps to store name and number
map<string, string> contacts;

map<string, string> addContact(string name, string number){
  contacts.insert(pair<string, string>(name, number));
  return contacts;
};

// delete contact

// edit contact

// search contact

// list all contacts
string listContacts(){
  //create an iterator that begins at the start of the contacts map
  map<string, string>::iterator it = contacts.begin();

  while(it != contacts.end()) {
    cout << "Name: " << it->first << ", Number: " << it->second << endl;
    ++it;
  }

  return 0;
};



int main(){

  string name;
  string number;
  cout << "Enter name: "; 
  cin >> name;
  cout << "Enter number: ";
  cin >> number;

  map<string, string> addKeyValue = addContact(name, number);
  string list = listContacts();
  cout << list << endl;



  return 0;
}