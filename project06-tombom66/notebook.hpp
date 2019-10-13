#include <fstream>
#include <string>
class Note {
private:
  std::string title_, body_;

public:
  void setTitle(std::string data) { title_ = data; }
  std::string getTitle() { return title_; }
  void setBody(std::string data) { body_ = data; }
  std::string getBody() { return body_; }
  Note() : title_("Untitled"), body_("") {}
  Note(const std::string &title,
       const std::string &body) // note objects lines 12-13
      : title_(title), body_(body) {}
  virtual void display();
  virtual std::string serialize();
  // settings its title  and body to the given parameters
};
class Notebook {
private:
  int capacity_, size_;
  Note **notes_;

public:
  int getCapacity() { return capacity_; }
  int getSize() { return size_; }
  Notebook() {
    capacity_ = 100;
    size_ = 0;
    notes_ = new Note *[capacity_];
  }
  Notebook(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    notes_ = new Note *[capacity];
  }
  ~Notebook() {
    delete[] notes_;
    notes_ = nullptr;
  }
  Note *getNotes(int index) const { return *(notes_ + index); }
  void addNote(Note *new_note); // still need to work on this
  void listNotes() const;       // work once
  void viewNote() const;
  void saveNotes(const std::string &filename);
  void loadNotes(const std::string &filename);
};
class EncryptedNote : public Note {
private:
  std::string password_;

public:
  EncryptedNote() : password_("") {}
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : password_(password), Note(title, body) {}
  virtual void display() override;
  std::string serialize() override;
};
Note *createNote();
void listNotes();
void viewNote();
void saveNotes(const std::string &file_name);
void loadNotes(const std::string &filename);
EncryptedNote *createEncryptedNote();
