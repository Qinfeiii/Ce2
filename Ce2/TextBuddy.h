//  TextBuddy.h
//  [w11][Han Qinfei][CE2][cpp] 
//

using namespace std;

class TextBuddy {
private:
  char* fileName;
  //store the content from text file into an array of string
  vector<string> list;
  
public:
  TextBuddy() {}
  
  pair<string, string> parseInput(const string& input) {
    const size_t spacePos = input.find_first_of(' ');
    // check if there is no argument
    if (spacePos == string::npos) {
      return make_pair(input, "");
    }
    
    const string command(input, 0, spacePos);
    const string arg(input, spacePos + 1, string::npos);
    return make_pair(command, arg);
    
    void saveToFile();
    void addEntry(const string& entry);
    void deleteEntry(const string& entryNo);
    void displayEntries();
    void displayEntries(const vector<int> entryIndexes);
    void clearEntries();
    void exitProgram();
    void processCommand(const string& input);
    void initializeList();
    void inputCommand();
    void sortEntries();
    void TrimString(string& input);
    bool searchEntries(string pattern);
    void runProgram(char* argv[]);
    
    
    
    
    
    
    
  }