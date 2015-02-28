//  Name: Han Qinfei, matric number: A0114077
//  main.cpp
//  TextBuddy
//  CE2


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include "Tester.h"
#include "gtest/gtest.h"
#include "TextBuddy.h"

  void saveToFile() {
    ofstream outFile(fileName);
    for (int i = 0; i < list.size(); i++) {
      outFile << list[i] << endl;
    }
    outFile.close();
  }
  
  void addEntry(const string& entry) {
    if (entry.empty()) {
      cout << "There is no valid entry entered" << endl;
      return;
    }
    
    list.push_back(entry);
    cout << "added to " << fileName << ": \"" << entry << "\"" << endl;
  }
  
  // deleteEntry deletes entry from the list
  void deleteEntry(const string& entryNo) {
    int i = atoi(entryNo.c_str());
    if (i <= list.size() && i > 0) {
      //Save the deleted entry for display later
      const string &deleted = list[i - 1];
      list.erase(list.begin() + i - 1);
      cout << "deleted from " << fileName << ": \"" << deleted << "\"" << endl;
    } else {
      cout << "Invalid entry number: " << entryNo << endl;
    }
  }
  
  void displayEntries() {
    if(!list.empty()) {
      for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i] << endl;
      }
    } else {
      cout << fileName << " is empty" << endl;
    }
  }

  void displayEntries(const vector<int> entryIndexes) {
    for (vector<int>::const_iterator it = entryIndexes.begin(); it != entryIndexes.end(); it++) {
      int i = *it;
      cout << i + 1 << ". " << list[i] << endl;
    }
  }
  
  void clearEntries() {
    list.clear();
    cout << "all content deleted from " << fileName <<endl;
  }
  
  void exitProgram() {
    // The file can be saved to the disk when the user exit the program
    saveToFile();
  }
  
  void processCommand(const string& input) {
    const pair<string, string> commandArg = parseInput(input);
    const string& command = commandArg.first;
    const string& arg = commandArg.second;
    
    if (command == "add") {
      addEntry(arg);
    }
    else if (command == "display") {
      displayEntries();
    }
    else if (command == "delete") {
      deleteEntry(arg);
    }
    else if (command == "clear") {
      clearEntries();
    }
    else if (command == "exit") {
      exitProgram();
      exit(0);
    }
    else if (command == "sort") {
      sortEntries();
    }
    else if (command == "search") {
      searchEntries(arg);
    }
    else {
      cout << "Invalid command, please re-enter" << endl;
    }
  }
  
  void initializeList() {
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
      return;
    }
    string templine;
    while (!inFile.eof()) {
      getline(inFile, templine);
      if (templine.length() > 0) {
        list.push_back(templine);
      }
    }
    inFile.close();
  }
  
  void inputCommand() {
    string input;
    
    while (true) {
      cout << "command: ";
      getline(cin, input);
      
      if (cin.eof()) {
        cout << endl;
        break;
      }
      
      processCommand(input);
    }
  }
  
  void sortEntries() {
    sort(list.begin(), list.end());
  }
  
  //removes spaces from the end of a string
  void TrimString(string& input) {
    while(input[0] == ' ' || input[0] == '\n')
    {
      input = input.substr(1);
    }
    while(input[input.size()-1] == ' ' || input[input.size()-1] == '\n')
    {
      input = input.substr(0,input.size()-1);
    }
  }
  
  bool searchEntries(string pattern) {
    TrimString(pattern);
    vector<int> matchedEntries;
    
    for (int i = 0; i < list.size(); i++) {
      size_t found = list[i].find(pattern);
      if (found != string::npos) {
        matchedEntries.push_back(i);
      }
    }
    if(matchedEntries.empty()) {
      cout << "Unsuccessful Search" << endl;
      return false;
    } else {
      cout << pattern << " found" << endl;
      displayEntries(matchedEntries);
      return true;
    }
  }
  
  void runProgram(char* argv[]) {
    fileName = argv[1];
    initializeList();
    cout << "Welcome to TextBuddy. " << fileName << " is ready for use" << endl;
    inputCommand();
  }
};

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Invalid file name. Press any key to exit." << endl;
    exit(1);
  }
  
  
  //Running unit test
  runTest(argc,argv);
  
  TextBuddy newText;
  newText.runProgram(argv);

  
  return 0;
}
