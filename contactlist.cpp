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
string deleteContact(string name){
    // first find the requested contact
  if(contacts.find(name) != contacts.end()){
    // edit name to have new number
    contacts.erase(name);
  }
  else{
    throw "Contact Not found";
  }
}

// edit contact
string editContact(string name, string newNumber) {
  // first find the requested contact
  if(contacts.find(name) != contacts.end()){
    // edit name to have new number
    contacts[name] = newNumber;
  }
  else{
    throw "Contact Not found";
  }
}

// search contact
string searchContact(string name){
  //search for a contact in the map using the name as the key
  if(contacts.find(name) != contacts.end()){
    cout << "Found Contact with Name: " << name << " and number: " << contacts[name] << endl;
  }
  else {
    throw "contact not found";
  }
  return 0;
};

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

  // string name;
  // string number;
  // cout << "Enter name: "; 
  // cin >> name;
  // cout << "Enter number: ";
  // cin >> number;

  // map<string, string> addKeyValue = addContact(name, number);
  // string list = listContacts();
  // cout << list << endl;

  try{
    searchContact("John");
  }catch(const char* error){
    cout << error << endl;
  }



  return 0;
}