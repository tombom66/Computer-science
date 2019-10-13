#include "../notebook.hpp"
#include "gtest_ext.h"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

const std::string UNITEST_FILENAME = "my_notes.txt";

class NotePointerFactory {
private:
  std::vector<Note *> notes_;
  bool clean_up_;

public:
  NotePointerFactory(bool clean_up) : clean_up_(clean_up) {}
  NotePointerFactory() : NotePointerFactory(true) {}
  Note *build() {
    Note *ptr_note = new Note;
    notes_.push_back(ptr_note);
    return ptr_note;
  }

  Note *build(const std::string &title, const std::string &body) {
    Note *ptr_note = build();
    ptr_note->setTitle(title);
    ptr_note->setBody(body);
    return ptr_note;
  }
  ~NotePointerFactory() {
    if (clean_up_) {
      for (int i = 0; i < notes_.size(); i++) {
        if (notes_[i] != nullptr) {
          delete notes_[i];
          notes_[i] = nullptr;
        }
      }
    }
  }
};

class EncryptedNotePointerFactory {
private:
  std::vector<Note *> notes_;
  bool clean_up_;

public:
  EncryptedNotePointerFactory(bool clean_up) : clean_up_(clean_up) {}
  EncryptedNotePointerFactory() : EncryptedNotePointerFactory(true) {}
  EncryptedNote *build() {
    EncryptedNote *ptr_note = new EncryptedNote;
    notes_.push_back(ptr_note);
    return ptr_note;
  }

  EncryptedNote *build(const std::string &title, const std::string &body,
                       const std::string &password) {
    EncryptedNote *ptr_note = new EncryptedNote(title, body, password);
    return ptr_note;
  }
  ~EncryptedNotePointerFactory() {
    if (clean_up_) {
      for (int i = 0; i < notes_.size(); i++) {
        if (notes_[i] != nullptr) {
          delete notes_[i];
          notes_[i] = nullptr;
        }
      }
    }
  }
};

class FileIO : public ::testing::Test {
protected:
  void SetUp() override {
    std::ifstream my_empty_file;
    my_empty_file.open(UNITEST_FILENAME);
    if (my_empty_file.good()) {
      rename(UNITEST_FILENAME.c_str(), TEMP_FILENAME.c_str());
      file_exists = true;
    }
    my_empty_file.close();
  }

  void TearDown() override {
    if (file_exists) {
      rename(TEMP_FILENAME.c_str(), UNITEST_FILENAME.c_str());
    } else {
      remove(UNITEST_FILENAME.c_str());
    }
  }
  std::string TEMP_FILENAME = "user_notes.txt";
  bool file_exists = false;
};

TEST(Milestone1, FiniteChoiceLoop) {
  srand(time(NULL));
  ASSERT_DURATION_LE(3, { main_output("tuffynotes", "c\nX\nX\ne"); });
}

TEST(Milestone1, CreateNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nPlease enter "
      "the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[N] Create an "
      "encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\ne\n", unittest_output); });
}

TEST(Milestone6, CreateEncryptedNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nPlease enter "
      "the note's title: Please "
      "enter the note: Please enter the password: \nEncrypted Note "
      "added!\n\n[C] Create a note\n[N] Create an encrypted note\n[L] List "
      "notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "n\nX\nX\nX\ne\n", unittest_output);
  });
}

TEST(Milestone3, ListNotesChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nPlease enter "
      "the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[N] Create an "
      "encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: "
      "\nNotes\n1. X\n\n[C] Create a note\n[N] Create an encrypted note\n[L] "
      "List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nThank you for "
      "using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nl\ne\n", unittest_output);
  });
}

TEST(Milestone3, ViewNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[N] Create an "
      "encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nNotes\n1. X\n\nPlease input note index: \n[X]\nX\n\n[C] "
      "Create a note\n[N] Create an encrypted note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "c\nX\nX\nv\n1\ne\n", unittest_output);
  });
}

TEST(Milestone6, ViewEncryptedNoteChoiceCorrectPassword) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: Please enter the password: \nEncrypted Note "
      "added!\n\n[C] Create a note\n[N] Create an encrypted note\n[L] List "
      "notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nNotes\n1. X\n\nPlease input note index: Please enter "
      "password to view note: \n[X]\nX\n\n[C] "
      "Create a note\n[N] Create an encrypted note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load "
      "notes\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "n\nX\nX\nX\nv\n1\nX\ne\n", unittest_output);
  });
}

TEST(Milestone6, ViewEncryptedNoteChoiceIncorrectPassword) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: Please enter the password: \nEncrypted Note "
      "added!\n\n[C] Create a note\n[N] Create an encrypted note\n[L] List "
      "notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nNotes\n1. X\n\nPlease input note index: Please enter "
      "password to view note: \nSorry, you do not have the permission to view "
      "note.\n\n[C] "
      "Create a note\n[N] Create an encrypted note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load "
      "notes\n[E] Exit\nChoice: \nThank "
      "you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("tuffynotes", "n\nX\nX\nX\nv\n1\nY\ne\n", unittest_output);
  });
}

TEST(Milestone1, QuitChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", "e\n", unittest_output); });
}

TEST(Milestone1, InvalidOptionChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nInvalid choice. Please try "
      "again.\n\n[C] Create a note\n[N] Create an encrypted note\n[L] List "
      "notes\n[V] View note\n[S] Save "
      "notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(
      3, {ASSERT_EXECIO_EQ("tuffynotes", "x\ne\n", unittest_output)});
}

TEST_F(FileIO, Milestone1_4_6_ChoiceLoopLowercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n";
  char choices[] = {'c', 'n', 'e', 'l', 'v', 's', 'o',
                    'L', 'C', 'N', 'E', 'V', 'S', 'O'};
  unsigned int note_count = 1;
  unsigned int saved_note_count = note_count;
  std::string note_list = "\nNotes\n";
  std::string saved_note_list = note_list;
  char saved_first_note_type = 'x', first_note_type = 'x';
  char choice = ' ';
  do {
    choice = choices[rand() % 7];
    unittest_output += "\n[C] Create a note\n[N] Create an encrypted note\n[L] "
                       "List notes\n[V] View note\n[S] "
                       "Save notes\n[O] Load notes\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'c':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      if (first_note_type == 'x') {
        first_note_type = 'c';
      }
      break;
    case 'n':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: Please enter the password: "
                         "\nEncrypted Note added!\n";
      input += "t\\nb\\np\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      if (first_note_type == 'x') {
        first_note_type = 'n';
      }
      break;
    case 'l':
      if (note_count > 1) {
        unittest_output += note_list;
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'v':
      if (note_count > 1) {
        if (first_note_type == 'c') {
          unittest_output +=
              note_list + "\nPlease input note index: \n[t]\nb\n";
          input += "1\\n";
        } else if (first_note_type == 'n') {
          unittest_output +=
              note_list + "\nPlease input note index: Please enter password "
                          "to view note: \n[t]\nb\n";
          input += "1\\np\\n";
        }
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 's':
      unittest_output += "\nPlease enter the filename: \nNotes saved!\n";
      input += UNITEST_FILENAME + "\\n";
      saved_note_count = note_count;
      saved_note_list = note_list;
      saved_first_note_type = first_note_type;
      break;
    case 'o':
      unittest_output += "\nPlease enter the filename: \nNotes loaded!\n";
      input += UNITEST_FILENAME + "\\n";
      note_list = saved_note_list;
      note_count = saved_note_count;
      first_note_type = saved_first_note_type;
      break;
    case 'e':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "\nInvalid choice. Please try again.\n";
    }
  } while (choice != 'e');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST_F(FileIO, Milestone1_4_6_ChoiceLoopUppercase) {
  std::string input = "";
  std::string unittest_output = "Welcome to TuffyNotes!\n";
  char choices[] = {'c', 'n', 'e', 'l', 'v', 's', 'o',
                    'L', 'C', 'N', 'E', 'V', 'S', 'O'};
  unsigned int note_count = 1;
  unsigned int saved_note_count = note_count;
  std::string note_list = "\nNotes\n";
  std::string saved_note_list = note_list;
  char saved_first_note_type = 'x', first_note_type = 'x';
  char choice = ' ';
  do {
    choice = choices[rand() % 7 + 7];
    unittest_output += "\n[C] Create a note\n[N] Create an encrypted note\n[L] "
                       "List notes\n[V] View note\n[S] "
                       "Save notes\n[O] Load notes\n[E] Exit\nChoice: ";
    std::string s_choice(1, choice);
    input += s_choice + "\\n";
    switch (choice) {
    case 'C':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: \nNote added!\n";
      input += "t\\nb\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      if (first_note_type == 'x') {
        first_note_type = 'c';
      }
      break;
    case 'N':
      unittest_output += "\nPlease enter the note's title: ";
      unittest_output += "Please enter the note: Please enter the password: "
                         "\nEncrypted Note added!\n";
      input += "t\\nb\\np\\n";
      note_list += std::to_string(note_count) + ". t\n";
      note_count++;
      if (first_note_type == 'x') {
        first_note_type = 'n';
      }
      break;
    case 'L':
      if (note_count > 1) {
        unittest_output += note_list;
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'V':
      if (note_count > 1) {
        if (first_note_type == 'c') {
          unittest_output +=
              note_list + "\nPlease input note index: \n[t]\nb\n";
          input += "1\\n";
        } else if (first_note_type == 'n') {
          unittest_output +=
              note_list + "\nPlease input note index: Please enter password "
                          "to view note: \n[t]\nb\n";
          input += "1\\np\\n";
        }
      } else {
        unittest_output += "\nNo notes have been added.\n";
      }
      break;
    case 'S':
      unittest_output += "\nPlease enter the filename: \nNotes saved!\n";
      input += UNITEST_FILENAME + "\\n";
      saved_note_count = note_count;
      saved_note_list = note_list;
      saved_first_note_type = first_note_type;
      break;
    case 'O':
      unittest_output += "\nPlease enter the filename: \nNotes loaded!\n";
      input += UNITEST_FILENAME + "\\n";
      note_list = saved_note_list;
      note_count = saved_note_count;
      first_note_type = saved_first_note_type;
      break;
    case 'E':
      unittest_output += "\nThank you for using TuffyNotes!\n";
      break;
    default:
      unittest_output += "\nInvalid choice. Please try again.\n";
    }
  } while (choice != 'E');
  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output); });
}

TEST(Milestone2_6, NoteClass) {
  Note temp;
  temp.setTitle("title");
  temp.setBody("body");
  temp.getTitle();
  temp.getBody();
  temp.serialize();
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\n[title]\nbody\n", {
      temp.display();
    });
  });
}

TEST(Milestone2, NoteTitleGetSet) {
  Note your_note_object;
  std::string unittest_title = generate_string(10);
  your_note_object.setTitle(unittest_title);
  ASSERT_EQ(your_note_object.getTitle(), unittest_title);
}

TEST(Milestone2, NoteBodyGetSet) {
  Note your_note_object;
  std::string unittest_body = generate_string(10);
  your_note_object.setBody(unittest_body);
  ASSERT_EQ(your_note_object.getBody(), unittest_body);
}

TEST(Milestone5, NoteDefaultConstructor) {
  Note your_note_object;
  ASSERT_EQ(your_note_object.getTitle(), "Untitled");
  ASSERT_EQ(your_note_object.getBody(), "");
}

TEST(Milestone5, NoteNonDefaultConstructor) {
  std::string unittest_title, unittest_body;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  Note your_note_object(unittest_title, unittest_body);
  ASSERT_EQ(your_note_object.getTitle(), unittest_title);
  ASSERT_EQ(your_note_object.getBody(), unittest_body);
}

TEST(Milestone5, NoteDisplay) {
  std::string unittest_title, unittest_body, unittest_display;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  unittest_display = "\n[" + unittest_title + "]\n" + unittest_body + "\n";
  Note your_note_object(unittest_title, unittest_body);
  ASSERT_DURATION_LE(
      3, ASSERT_SIO_EQ("", unittest_display, { your_note_object.display(); }));
}

TEST(Milestone6, NoteSerialize) {
  std::string unittest_title, unittest_body, unittest_display;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  Note your_note_object(unittest_title, unittest_body);
  ASSERT_EQ(your_note_object.serialize(),
            "[Note]\n" + unittest_title + "\n" + unittest_body + "\n")
      << "Where unittest_title = " << unittest_title
      << " unittes_body = " << unittest_body;
}

TEST(Milestone6, EncNoteInheritance) {
  bool encrypted_note_inherits_from_note =
      std::is_base_of<Note, EncryptedNote>::value;
  ASSERT_TRUE(encrypted_note_inherits_from_note);
}

TEST(Milestone6, EncNoteClass) {
  EncryptedNote temp;
  temp.setTitle("title");
  temp.setBody("body");
  temp.getTitle();
  temp.getBody();
  temp.serialize();
}

TEST(Milestone6, EncNoteTitleGetSet) {
  EncryptedNote your_encryptednote_object;
  std::string unittest_title = generate_string(10);
  your_encryptednote_object.setTitle(unittest_title);
  ASSERT_EQ(your_encryptednote_object.getTitle(), unittest_title);
}

TEST(Milestone6, EncNoteBodyGetSet) {
  EncryptedNote your_encryptednote_object;
  std::string unittest_body = generate_string(10);
  your_encryptednote_object.setBody(unittest_body);
  ASSERT_EQ(your_encryptednote_object.getBody(), unittest_body);
}

TEST(Milestone6, EncNoteDefaultConstructor) {
  EncryptedNote your_encryptednote_object;
  ASSERT_EQ(your_encryptednote_object.getTitle(), "Untitled");
  ASSERT_EQ(your_encryptednote_object.getBody(), "");
}

TEST(Milestone6, EncNoteNonDefaultConstructor) {
  std::string unittest_title, unittest_body;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  EncryptedNote your_encryptednote_object(unittest_title, unittest_body,
                                          generate_string(10));
  ASSERT_EQ(your_encryptednote_object.getTitle(), unittest_title);
  ASSERT_EQ(your_encryptednote_object.getBody(), unittest_body);
}

TEST(Milestone6, EncNoteDisplayCorrectPassword) {
  std::string unittest_title, unittest_body, unittest_display,
      unittest_password;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  unittest_password = generate_string(10);
  unittest_display = "Please enter password to view note: \n[" + unittest_title +
                     "]\n" + unittest_body + "\n";
  EncryptedNote your_encryptednote_object(unittest_title, unittest_body,
                                          unittest_password);
  ASSERT_DURATION_LE(3, ASSERT_SIO_EQ(unittest_password, unittest_display, {
                       your_encryptednote_object.display();
                     }));
}

TEST(Milestone6, EncNoteDisplayIncorrectPassword) {
  std::string unittest_title, unittest_body, unittest_display,
      unittest_password;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  unittest_password = generate_string(10);
  unittest_display = "Please enter password to view note: \nSorry, you do not "
                     "have the permission to view note.\n";
  EncryptedNote your_encryptednote_object(unittest_title, unittest_body, "x");
  ASSERT_DURATION_LE(3, ASSERT_SIO_EQ(unittest_password, unittest_display, {
                       your_encryptednote_object.display();
                     }));
}

TEST(Milestone6, EncNoteSerialize) {
  std::string unittest_title, unittest_body, unittest_display,
      unittest_password;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  unittest_password = generate_string(10);
  EncryptedNote your_encryptednote_object(unittest_title, unittest_body,
                                          unittest_password);
  ASSERT_EQ(your_encryptednote_object.serialize(),
            "[EncNote]\n" + unittest_title + "\n" + unittest_body + "\n" +
                unittest_password + "\n")
      << "Where unittest_title = " << unittest_title
      << " unittest_body = " << unittest_body
      << " unittest_password = " << unittest_password;
}

TEST(Milestone5_6, NotebookDefaultConstructor) {
  Notebook your_notebook;
  ASSERT_EQ(your_notebook.getCapacity(), 100);
  ASSERT_EQ(your_notebook.getSize(), 0);
}

TEST(Milestone5_6, NotebookNonDefaultConstructor) {
  int unittest_capacity = rand() % 10;
  Notebook your_notebook(unittest_capacity);
  ASSERT_EQ(your_notebook.getCapacity(), unittest_capacity);
  ASSERT_EQ(your_notebook.getSize(), 0);
}

TEST(Milestone5_6, NotebookAdd) {
  NotePointerFactory nf(false);
  std::string unittest_title, unittest_body, unittest_display;
  unittest_title = generate_string(10);
  unittest_body = generate_string(10);
  Note *test_note = nf.build(unittest_title, unittest_body);
  Notebook your_notebook;
  your_notebook.addNote(test_note);
  ASSERT_EQ(your_notebook.getSize(), 1);
  ASSERT_EQ(your_notebook.getNote(0)->getTitle(), unittest_title);
  ASSERT_EQ(your_notebook.getNote(0)->getBody(), unittest_body);
}

TEST(Milestone5_6, NotebookGet) {
  int notes_size = rand() % 10 + 1;
  NotePointerFactory nf(false);
  Notebook your_notebook;
  std::string unittest_titles[notes_size];
  std::string unittest_bodies[notes_size];

  for (int i = 0; i < notes_size; i++) {
    Note *temp = nf.build();
    std::string temp_str = generate_string(10);
    unittest_titles[i] = temp_str;
    temp->setTitle(temp_str);
    temp_str = generate_string(10);
    unittest_bodies[i] = temp_str;
    temp->setBody(temp_str);
    your_notebook.addNote(temp);
  }

  for (int i = 0; i < notes_size; i++) {
    std::string unittest_title = unittest_titles[i];
    ASSERT_EQ(your_notebook.getNote(i)->getTitle(), unittest_title);
    std::string unittest_body = unittest_bodies[i];
    ASSERT_EQ(your_notebook.getNote(i)->getBody(), unittest_body);
  }
}

TEST(Milestone2, CreateNote) {
  Note *your_note_object;
  std::string unittest_title = generate_string(10);
  std::string unittest_body = generate_string(10);
  std::string input = unittest_title + "\n" + unittest_body + "\n";
  std::string unittest_output = "\nPlease enter the note's title: ";
  unittest_output += "Please enter the note: \nNote added!\n";
  // create_note returns a pointer. should we manage this?
  ASSERT_SIO_EQ(input, unittest_output, { your_note_object = createNote(); });
  ASSERT_EQ(your_note_object->getTitle(), unittest_title);
  ASSERT_EQ(your_note_object->getBody(), unittest_body);
}

TEST(Milestone6, CreateEncryptedNote) {
  EncryptedNote *your_encryptednote_object;
  std::string unittest_title = generate_string(10);
  std::string unittest_body = generate_string(10);
  std::string unittest_password = generate_string(10);
  std::string input =
      unittest_title + "\n" + unittest_body + "\n" + unittest_password + "\n";
  std::string unittest_output = "\nPlease enter the note's title: ";
  unittest_output += "Please enter the note: Please enter the password: "
                     "\nEncrypted Note added!\n";
  // create_note returns a pointer. should we manage this?
  ASSERT_SIO_EQ(input, unittest_output,
                { your_encryptednote_object = createEncryptedNote(); });
  ASSERT_EQ(your_encryptednote_object->getTitle(), unittest_title);
  ASSERT_EQ(your_encryptednote_object->getBody(), unittest_body);
}

TEST(Milestone5, ListNotesEmpty) {
  Notebook unittest_notebook;
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n",
                  { unittest_notebook.listNotes(); });
  });
}

TEST(Milestone5, ListNotesSingle) {
  NotePointerFactory nf(false);
  Notebook unittest_notebook;
  Note *temp = nf.build();
  unittest_notebook.addNote(temp);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNotes\n1. Untitled\n",
                  { unittest_notebook.listNotes(); });
  });
}

TEST(Milestone5, ListNotesMultiple) {
  NotePointerFactory nf(false);
  Notebook unittest_notebook;
  Note *temp = nf.build("Buy groceries", "");
  unittest_notebook.addNote(temp);
  Note *temp2 = nf.build("CPSC 121 guide questions", "");
  unittest_notebook.addNote(temp2);
  Note *temp3 = nf.build("Group mates list", "");
  unittest_notebook.addNote(temp3);
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("",
                  "\nNotes\n1. Buy groceries\n2. CPSC 121 guide questions\n3. "
                  "Group mates list\n",
                  { unittest_notebook.listNotes(); });
  });
}

TEST(Milestone5, ViewNoteEmpty) {
  Notebook unittest_notebook;
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", "\nNo notes have been added.\n",
                  { unittest_notebook.viewNote(); });
  });
}

TEST(Milestone5, ViewNote) {
  NotePointerFactory nf(false);
  Notebook unittest_notebook;
  Note *temp = nf.build("Group mates list", "");
  unittest_notebook.addNote(temp);
  Note *temp2 = nf.build("Buy groceries", "1 qt. of milk, 5 apples, 1 dozen eggs");
  unittest_notebook.addNote(temp2);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: \n[Buy groceries]\n1 qt. of milk, 5 apples, 1 dozen eggs\n",
        { unittest_notebook.viewNote(); });
  });
}

TEST(Milestone6, ViewEncryptedNoteCorrectPassword) {
  EncryptedNotePointerFactory ef(false);
  Notebook unittest_notebook;
  EncryptedNote *temp = ef.build("Group mates list", "", "");
  unittest_notebook.addNote(temp);
  EncryptedNote *temp2 = ef.build("Buy groceries", "1 qt. of milk, 5 apples, 1 dozen eggs", "p");
  unittest_notebook.addNote(temp2);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2 p",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: Please enter password to view note: \n[Buy groceries]\n1 qt. of milk, 5 apples, 1 dozen eggs\n",
        { unittest_notebook.viewNote(); });
  });
}

TEST(Milestone6, ViewEncryptedNoteIncorrectPassword) {
  EncryptedNotePointerFactory ef(false);
  Notebook unittest_notebook;
  EncryptedNote *temp = ef.build("Group mates list", "", "");
  unittest_notebook.addNote(temp);
  EncryptedNote *temp2 = ef.build("Buy groceries", "1 qt. of milk, 5 apples, 1 dozen eggs", "p");
  unittest_notebook.addNote(temp2);

  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ(
        "2\\nx",
        "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease input note "
        "index: Please enter password to view note: \nSorry, you do not have the permission to view note.\n",
        { unittest_notebook.viewNote(); });
  });
}

TEST(Milestone5, ViewNoteInvalidIndex) {
  NotePointerFactory nf(false);
  Notebook unittest_notebook;
  Note *temp = nf.build("Group mates list", "");
  unittest_notebook.addNote(temp);
  Note *temp2 = nf.build("Buy groceries", "1 qt. of milk, 5 apples, 1 dozen eggs");
  unittest_notebook.addNote(temp2);
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("8",
                  "\nNotes\n1. Group mates list\n2. Buy groceries\n\nPlease "
                  "input note index: \nInvalid note index.\n",
                  { unittest_notebook.viewNote(); });
  });
}

TEST_F(FileIO, Milestone5_6_SaveNotes) {
  int notes_size = rand() % 10 + 1;
  NotePointerFactory nf(false);
  Notebook unittest_notebook;
  std::string unittest_file_output = std::to_string(notes_size) + "\n";

  for (int i = 0; i < notes_size; i++) {
    Note *temp = nf.build();
    std::string temp_str = generate_string(10);
    temp->setTitle(temp_str);
    unittest_file_output += "[Note]\n" + temp_str + "\n";
    temp_str = generate_string(10);
    temp->setBody(temp_str);
    unittest_file_output += temp_str + "\n";
    unittest_notebook.addNote(temp);
  }
  ASSERT_SIO_EQ("", "\nNotes saved!\n",
                { unittest_notebook.saveNotes(UNITEST_FILENAME); });
  std::ifstream the_file;
  the_file.open(UNITEST_FILENAME);
  std::string your_file_output = "", temp_str = "";
  while (std::getline(the_file, temp_str)) {
    your_file_output += temp_str + "\n";
  }
  the_file.close();
  ASSERT_GT(your_file_output.length(), 0)
      << "   Your file appears to be empty. Check your code to see if the file "
         "is saved properly.";
  ASSERT_EQ(your_file_output, unittest_file_output)
      << "   Your file does not seem to follow the expected format.";
}

TEST_F(FileIO, Milestone6_SaveEncryptedNotes) {
  int notes_size = rand() % 10 + 1;
  EncryptedNotePointerFactory ef(false);
  Notebook unittest_notebook;
  std::string unittest_file_output = std::to_string(notes_size) + "\n";

  for (int i = 0; i < notes_size; i++) {
    std::string unittest_title = generate_string(10);
    std::string unittest_body = generate_string(10);
    std::string unittest_password = generate_string(10);
    EncryptedNote *temp = ef.build(unittest_title, unittest_body, unittest_password);
    unittest_file_output += "[EncNote]\n" + unittest_title + "\n" +
                            unittest_body + "\n" + unittest_password + "\n";
    unittest_notebook.addNote(temp);
  }
  ASSERT_SIO_EQ("", "\nNotes saved!\n",
                { unittest_notebook.saveNotes(UNITEST_FILENAME); });
  std::ifstream the_file;
  the_file.open(UNITEST_FILENAME);
  std::string your_file_output = "", temp_str = "";
  while (std::getline(the_file, temp_str)) {
    your_file_output += temp_str + "\n";
  }
  the_file.close();
  ASSERT_GT(your_file_output.length(), 0)
      << "   Your file appears to be empty. Check your code to see if the file "
         "is saved properly.";
  ASSERT_EQ(your_file_output, unittest_file_output)
      << "   Your file does not seem to follow the expected format.";
}

TEST_F(FileIO, Milestone5_6_LoadNotes) {
  NotePointerFactory nf(false);
  int unittest_notes_size = rand() % 10 + 1;
  Notebook unittest_notebook;
  std::ofstream the_file;
  the_file.open(UNITEST_FILENAME);
  the_file << unittest_notes_size << "\n";
  for (int i = 0; i < unittest_notes_size; i++) {
    Note *temp = nf.build();
    the_file << "[Note]\n";
    std::string temp_string = generate_string(10);
    temp->setTitle(temp_string);
    the_file << temp_string << "\n";
    temp_string = generate_string(10);
    temp->setBody(temp_string);
    the_file << temp_string << "\n";
    unittest_notebook.addNote(temp);
  }
  the_file.close();
  Notebook your_notebook;
  ASSERT_SIO_EQ("", "\nNotes loaded!\n",
                { your_notebook.loadNotes(UNITEST_FILENAME); });
  ASSERT_EQ(your_notebook.getSize(), unittest_notebook.getSize())
      << "  Your code did not load the correct number of notes.";
  for (int i = 0; i < unittest_notes_size; i++) {
    ASSERT_EQ(your_notebook.getNote(i)->getTitle(), unittest_notebook.getNote(i)->getTitle())
        << "  The title of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ASSERT_EQ(your_notebook.getNote(i)->getBody(), unittest_notebook.getNote(i)->getBody())
        << "  The body of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ;
  }
}

TEST_F(FileIO, Milestone6_LoadEncryptedNotes) {
  EncryptedNotePointerFactory ef(false);
  int unittest_notes_size = rand() % 10 + 1;
  Notebook unittest_notebook;
  std::ofstream the_file;
  the_file.open(UNITEST_FILENAME);
  the_file << unittest_notes_size << "\n";
  for (int i = 0; i < unittest_notes_size; i++) {
    std::string unittest_title = generate_string(10);
    std::string unittest_body = generate_string(10);
    std::string unittest_password = generate_string(10);
    EncryptedNote *temp =
        ef.build(unittest_title, unittest_body, unittest_password);
    the_file << "[EncNote]\n";
    the_file << unittest_title << "\n";
    the_file << unittest_body << "\n";
    the_file << unittest_password << "\n";
    unittest_notebook.addNote(temp);
  }
  the_file.close();
  Notebook your_notebook;
  ASSERT_SIO_EQ("", "\nNotes loaded!\n",
                { your_notebook.loadNotes(UNITEST_FILENAME); });
  ASSERT_EQ(your_notebook.getSize(), unittest_notebook.getSize())
      << "  Your code did not load the correct number of notes.";
  for (int i = 0; i < unittest_notes_size; i++) {
    ASSERT_EQ(your_notebook.getNote(i)->getTitle(), unittest_notebook.getNote(i)->getTitle())
        << "  The title of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ASSERT_EQ(your_notebook.getNote(i)->getBody(), unittest_notebook.getNote(i)->getBody())
        << "  The body of the Note object at index " << i
        << " is incorrect. Check if the file is lodaded properly.";
    ;
  }
}

TEST_F(FileIO, Milestone4_SaveNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: \nNote added!\n\n[C] Create a note\n[N] Create an "
      "encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the filename: \nNotes saved!\n\n"
      "[C] Create a note\n[N] Create an encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] "
      "Load notes\n[E] Exit\nChoice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    std::string input = "c\nX\nX\ns\n" + UNITEST_FILENAME + "\ne\n";
    ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output);
  });
}

TEST_F(FileIO, Milestone6_SaveEncryptedNoteChoice) {
  std::string unittest_output =
      "Welcome to TuffyNotes!\n\n[C] Create a note\n[N] Create an encrypted "
      "note\n[L] List notes\n[V] View "
      "note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the note's title: Please "
      "enter the note: Please enter the password: \nEncrypted Note added!\n\n[C] Create a note\n[N] Create an "
      "encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] Load notes\n[E] Exit\n"
      "Choice: \nPlease enter the filename: \nNotes saved!\n\n"
      "[C] Create a note\n[N] Create an encrypted note\n[L] List notes\n[V] "
      "View note\n[S] Save notes\n[O] "
      "Load notes\n[E] Exit\nChoice: \nThank you for using TuffyNotes!\n";
  ASSERT_DURATION_LE(3, {
    std::string input = "n\nX\nX\nX\ns\n" + UNITEST_FILENAME + "\ne\n";
    ASSERT_EXECIO_EQ("tuffynotes", input, unittest_output);
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
