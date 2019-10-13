#include "notebook.hpp"
#include <fstream>
#include <iostream>
#include <string>
Note *createNote() {

  std::string title, body;
  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);
  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);
  std::cout << "\n";
  Note *noteptr = new Note(title, body);
  std::cout << "Note added!\n\n";

  return noteptr;
}
/*
void listNotes(Note array1[], int size) {
  if (size == 0) {
    std::cout << "No notes have been added" << std::endl;
  } else {
    std::cout << "\nNotes \n";
    for (int i = 0; i < size; i++) {
      std::cout << i + 1 << "." << array1[i].getTitle() << std::endl;
    }
    std::cout << "\n";
  }
}
void viewNote(Note array1[], int size) {
  int index;
  int i;
  listNotes(array1, size);
  std::cout << "Please input note index: ";
  std::cin >> index;
  std::cout << "\n";
  std::cout << "[" << array1[index - 1].getTitle() << "]" << std::endl;
  std::cout << array1[index - 1].getBody() << std::endl;
  std::cout << "\n";
}
void saveNotes(std::string filename, Note array1[], int ARRAY_NOTES) {
  std::ofstream outputFile;
  outputFile.open(filename);
  outputFile << ARRAY_NOTES << std::endl;
  for (int i = 0; i < ARRAY_NOTES; i++) {
    outputFile << "[Note]\n";
    outputFile << array1[i].getTitle() << std::endl;
    outputFile << array1[i].getBody() << std::endl;
  }
  outputFile.close();
  std::cout << "Notes saved!" << std::endl;
}
void loadNotes(std::string filename, Note array2[], int *ARRAY_NOTES1) {
  std::string data;
  std::ifstream inputFile;
  inputFile.open(filename);
  inputFile >> *ARRAY_NOTES1;
  inputFile.ignore();
  for (int i = 0; i < *ARRAY_NOTES1; i++) {
    std::getline(inputFile, data);
    std::getline(inputFile, data);
    array2[i].setTitle(data);
    std::getline(inputFile, data);
    array2[i].setBody(data);
  }
  inputFile.close();
  std::cout << "Notes Loaded!\n";
}
*/
void Note::display() {
  std::cout << "\n[" << title_ << "]\n" << body_ << std::endl;
}
void Notebook::addNote(Note *new_note) {
  if (size_ < capacity_) {
    notes_[size_++] = new_note;
  } else {
    std::cout << "Note is full " << capacity_ << ".\n";
  }
}
void Notebook::listNotes() const {

  if (size_ == 0) {
    std::cout << "No notes have been added" << std::endl;
  } else {
    std::cout << "\nNotes \n";
    for (int i = 0; i < size_; i++) {
      std::cout << i + 1 << "." << (*(notes_ + i))->getTitle() << std::endl;
    }
    std::cout << "\n";
  }
}
void Notebook::viewNote() const {
  int index;
  Notebook::listNotes();

  std::cout << "Please input note index: ";
  std::cin >> index;
  std::cout << "\n";
  if (index > 0 && index <= size_) {
    (*(notes_ + index - 1))->display();
  } else {
    std::cout << "\nInvalid note idex\n\n";
  } // not in for loop because if we do find the array then wewant to output
    // this
}

void Notebook::saveNotes(const std::string &filename) {
  std::ofstream outputFile;
  outputFile.open(filename);
  outputFile << size_ << std::endl;
  for (int i = 0; i < size_; i++) {
    outputFile << (*(notes_ + i))->serialize();
    /*  outputFile << "[Note]\n";
      outputFile << notes_[i].getTitle() << std::endl;
      outputFile << notes_[i].getBody() << std::endl;*/
  }
  outputFile.close();
  std::cout << "Notes saved!" << std::endl;
}

void Notebook::loadNotes(const std::string &filename) {

  std::string data;
  std::ifstream inputFile;
  inputFile.open(filename);

  inputFile.ignore();
  for (int i = 0; i < size_; i++) {
    std::getline(inputFile, data);
    std::getline(inputFile, data);
    (*(notes_ + i))->setTitle(data); // set to notes_2
    std::getline(inputFile, data);
    (*(notes_ + i))->setBody(data); // set to notes_
    (*(notes_ + i))->serialize();
  }
  inputFile.close();
  std::cout << "Notes Loaded!\n";
}

std::string EncryptedNote::serialize() {
  std::string dp =
      "[EncNote]\n" + getTitle() + "\n" + getBody() + "\n" + password_ + "\n";
  return dp;
}

EncryptedNote *createEncryptedNote() {
  std::string title, body, pass;

  std::cout << "\nPlease enter the note's title: ";
  std::getline(std::cin, title);

  std::cout << "Please enter the note: ";
  std::getline(std::cin, body);

  std::cout << "Please enter the password: ";
  std::getline(std::cin, pass);

  std::cout << "\n";
  EncryptedNote *n = new EncryptedNote(title, body, pass);
  std::cout << "Encrypted Note added!\n\n";
  return n;
}
void EncryptedNote::display() {
  std::string disp;
  std::cout << "Please enter password to view note: ";
  std::cin >> disp; // needs fixing

  if (disp != password_) {
    std::cout << "Sorry, you do not have the permission to view note."
              << std::endl;
  } else {
    std::cout << "\n[" << getTitle() << "]\n" << getBody() << std::endl;
  }
}
std::string Note::serialize() {
  std::string dp = "[Note]\n" + title_ + "\n" + body_ + "\n";
  return dp;
}
