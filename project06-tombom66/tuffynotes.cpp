
#include "notebook.hpp"
#include <fstream>
#include <iostream>
#include <string>
int main() {
  std::string filename;
  std::string dummy;
  const int ARRAY_NOTES = 100;
  Note array1[ARRAY_NOTES];
  char choice;
  int arraylocation = 0;
  Notebook n;
  std::cout << "Welcome to TuffyNotes!\n";
  do {

    std::cout << "[C] Create a note\n";
    std::cout << "[N] Create an encrypted note\n";
    std::cout << "[L] List notes\n";
    std::cout << "[V] View note\n";
    std::cout << "[S] Save notes\n";
    std::cout << "[O] Load notes\n";
    std::cout << "[E] Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::getline(std::cin, dummy);
    if ((choice == 'c') || (choice == 'C')) {
      n.addNote(createNote());

    } else if ((choice == 'n') || (choice == 'N')) {
      n.addNote(createEncryptedNote()); // fixing
    } else if ((choice == 'l') || (choice == 'L')) {
      n.listNotes();
    } else if ((choice == 'v') || (choice == 'V')) {

      n.viewNote();
    } else if ((choice == 's') || (choice == 'S')) {
      std::cout << "Please enter the filename: ";
      getline(std::cin, filename);
      n.saveNotes(filename);
    } else if ((choice == 'o') || (choice == 'O')) {
      std::cout << "Please enter the filename: ";
      getline(std::cin, filename);
      n.loadNotes(filename);
    } else if ((choice == 'e') || (choice == 'E')) {
      std::cout << "\nThank you for using TuffyNotes!\n";
    } else {
      std::cout << "\nInvalid choice. Please try again.\n\n";
    }
  } while ((choice != 'E') && (choice != 'e'));

  return 0;
}
