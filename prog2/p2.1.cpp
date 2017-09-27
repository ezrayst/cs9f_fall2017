#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

// Function Prototypes
void InterpretUpdate(std::istringstream& cmds) {
    std::string word, temp;
    int number;

    if (cmds >> word >> number) {        
        if (cmds >> temp) {
          std::cout << "Invalid input! \nPlease write your command: ";  
        } else {
          std::cout << "Valid input. Copy: update " << word << " " << number << "\nPlease write your command: ";
        }

    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretList(std::istringstream& cmds) {
    std::string names, temp;
    int quantities;

    if (cmds >> names) {
        if (cmds >> temp) {
          std::cout << "Invalid input! \nPlease write your command: ";  
        } else {
          std::cout << "Valid input. Copy: list " << names << "\nPlease write your command: ";
        }
    } else if (cmds >> quantities) {
        cmds >> quantities;
        std::cout << "Valid input. Copy: list " << quantities << "\nPlease write your command: ";
    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretBatch(std::istringstream& cmds) {
    std::string filename, line; 
    std::ifstream file;
    
    if (cmds >> filename) {
        std::cout << "Valid input. Copy: batch " << filename << "\n";
        
        std::ifstream file;
        file.open(filename.c_str(), std::ios::in);
        if (!file.is_open())
          std::cout << "Specified input file does not exist.\n";
        if (file.good()) {
          std::getline(file, line);
          while (line != "") {
            std::istringstream inputline;
            inputline.str(line);
            std::cout << line << "\n";
            std::getline(file, line);
          } 
        }

        std::cout << "Please write your command: ";
    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretQuit(std::istringstream& cmds) {
    exit(0);
}

//! Function to interpret what kind of command it is
void InterpretCommands(std::istream& cmds)
{
    std::string line, lineInWord;
    std::getline(cmds, line);

    // TODO: Get a line.
    while (true) {

        std::istringstream lineIn(line);
        lineIn >> lineInWord;

        // TODO: Get the line's first word.
        if (lineInWord.empty()) {

            // TODO: Do something if there weren't any words.
            std::cerr << "Please write your command: "; 

        } else if (lineInWord == "update") {

            InterpretUpdate (lineIn);

        } else if (lineInWord == "list") {

            InterpretList (lineIn);

        } else if (lineInWord == "batch") {

            InterpretBatch (lineIn);

        } else if (lineInWord == "quit") {

            InterpretQuit(lineIn);

        } else {
            std::cerr << "Unrecognizable command word." << std::endl;
            std::cout << "Please write your command: ";
        }

        std::getline(cmds, line);    
    }
}

/**
 * Driver Function
 */
int main()
{
    std::cout << "Please write your command: ";
    InterpretCommands(std::cin);
    return 0;
}
