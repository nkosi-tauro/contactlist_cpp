#include <iostream>
#include <string>
#include <map>
using namespace std;

// contact maps to store name and number
map<string, string> contacts;
//loop control
bool programOpen = true;

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
    return "Contact deleted";
  }
  else{
    throw "Contact Not found";
  }
  return 0;
}

// edit contact
string editContact(string name, string newNumber) {
  // first find the requested contact
  if(contacts.find(name) != contacts.end()){
    // edit name to have new number
    return contacts[name] = newNumber;
  }
  else{
    throw "Contact Not found\n";
  }
}

// search contact
string searchContact(string name){
  //search for a contact in the map using the name as the key
  string output;
  if(contacts.find(name) != contacts.end()){
    output = "Found Contact with Name: " + name + " and number: " + contacts[name] + "\n";
    return output;
  }
  else {
    throw "contact not found\n";
  }
  return 0;
};

// list all contacts
string listContacts(){
  string output;
  //create an iterator that begins at the start of the contacts map
  map<string, string>::iterator it = contacts.begin();

  if (contacts.size() == 0){
    output = "You have no contacts in your contact list\n";
    return output;
  }
  
  while(it != contacts.end()) {
    cout << "Name: " << it->first << ", Number: " << it->second << endl;
    ++it;
  }
  return 0;
};



int main(){

  int choice;
  string name;
  string number;

  while(programOpen){
    // display menu
    cout << "Welcome to the Rubiks Contact List.\n" << endl;
    cout << "What would you like to do?\n" << endl;
    cout << "1. Add a new contact" << endl;
    cout << "2. Search for a contact" << endl;
    cout << "3. Delete a contact" << endl;
    cout << "4. Edit a contact" << endl;
    cout << "5. Display all contacts" << endl;
    cout << "6. Quit the program\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1) {
      cout << "Enter the name of the contact: ";
      cin >> name;
      cout << "Enter the number of the contact: ";
      cin >> number;
      addContact(name, number);
    }
    else if(choice == 2) {
      cout << "Enter the name of the contact you want to search for: ";
      cin >> name;

      try{
        cout << searchContact(name);
      }catch(const char* msg){
        cout << msg << endl;
      }
    }
    else if(choice == 3) {
      cout << "Enter the name of the contact you want to delete: ";
      cin >> name;

      try{
        deleteContact(name);
      }catch(const char* msg){
        cout << msg << endl;
      }

    }
    else if(choice == 4){
      cout << "Enter the name of the contact you want to Edit: ";
      cin >> name;
      cout << "Enter the new number of the contact: ";
      cin >> number;

      try{
        editContact(name, number);
      }catch(const char* msg){
        cout << msg << endl;
      }
    }
    else if(choice == 5) {
      cout << "Here is your contact list:\n" << listContacts();
    }
    else if(choice == 6) {
      programOpen = false;
      break;
    }
    else{
      cout << "Invalid choice\n" << endl;
    }
  }



  return 0;
}