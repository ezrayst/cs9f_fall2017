#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "inventory.h"

//! Make the myProperties global
Inventory myProperties;

void InterpretCommands(std::istream& cmds);

void InterpretUpdate(std::istream& cmds) {
    std::string word, temp;
    int number;

    if (cmds >> word >> number) {        
        if (cmds >> temp) {
          std::cout << "Invalid input! \nPlease write your command: ";  
        } else {
          std::cout << "Valid input. Copy: update " << word << " " << number << "\n";
          myProperties.Update(word, number);
          std::cout << "Please write your command: ";
        }

    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretList(std::istream& cmds) {
    std::string argument, temp;

    if (cmds >> argument) {
        if (cmds >> temp) {
          std::cout << "Invalid input! \nPlease write your command: ";  
        } else if (argument == "names") {
          std::cout << "Valid input. Copy: list names \n";
          myProperties.ListByName();
          std::cout << "Please write your command: ";
        } else if (argument == "quantities") {
          std::cout << "Valid input. Copy: list quantities \n";
          myProperties.ListByQuantity();
          std::cout << "Please write your command: ";
        } else {
          std::cout << "Invalid input! \nPlease write your command: ";  
        }
    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretBatch(std::istream& cmds) {
    std::string filename, line, temp; 
    std::ifstream file;
    
    if (cmds >> filename) {
        if (cmds >> temp) {
          std::cout << "Invalid input! \nPlease write your command: ";  
        } else {
          std::cout << "Valid input. Copy: batch " << filename << "\n";
        
          std::ifstream file;
          file.open(filename.c_str(), std::ios::in);
          if (!file.is_open())
            std::cout << "Specified input file does not exist.\n";
          if (file.good()) {
            do {
              std::getline(file, line);
              std::istringstream inputline;
              inputline.str(line);
              std::cout << line << "\n";
              InterpretCommands(inputline);
            } 
            while (!file.eof());
          std::cout << "Please write your command: ";
        }
      }
    } else {
        std::cout << "Invalid input! \nPlease write your command: ";
    }
}

void InterpretQuit(std::istream& cmds) {
    exit(0);
}

//! Function to interpret what kind of command it is
void InterpretCommands(std::istream& cmds) {
    std::string line, lineInWord;

    while (!cmds.eof()) {
        std::getline(cmds, line);

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
