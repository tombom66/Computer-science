# Dynamic Student Array
In this exercise you are going to read strings from a file, `students.txt` to load `Student` objects that are stored into a `Classroom` object. The first line of the file contains the total number of students, the second line is the first student's name, the third line is the student's id, the fourth line is the second student's name, the fifth line is the second student's id, and so on.

## Student Class
Create a class called `Student` that will have the following:

### Private Data Members
The class will have two member variables: a `std::string` `name_`, and an `int` `id_`.

### Default Constructor
Create a default constructor that sets `name_` to `"Stu Dent"` and `id_` to `123456789`.

### Accessors and Mutators
Create accessors called `getName()` and `getId()`.
Create mutators called `setName()` and `setId()`.

## Classroom Class
Create a class called `Classroom` that will have the following:

### Private Data Members
The class will have two member variables: a `Student` **pointer** and an `int` representing number of students enrolled. The array will contain all `Student` objects enrolled in the classroom.

### Default Constructor
Create a default constructor that sets number of students to `0` and the `Student` pointer to `nullptr`.

### Accessors
Create an accessor called `getNumStudents()`.

### Classroom Destructor
Create a destructor that appropriately frees the dynamically allocated space. However, be careful to only delete the address if it was already dynamically allocated (*Hint:* What is the initial value of `student_` before it is assigned to the dynamically allocated array?). Make sure the destructor avoids creating dangling pointers.

### Populate Member Function
Create a `void` member function for `Classroom` called `populate` that will pass in a `std::string` for a file name
as the parameter.

This function should:

1. Check if it has already dynamically allocated space and assigned it to `student_`. If it has, then the old array should be deleted from memory. (*Hint:* What is the initial value of `student_` before it is assigned to the dynamically allocated array?)
1. Dynamically allocate space according to the number of students and assign the address to `student_`.
1. Read each name and id pair from the file into a `Student` object that is stored into the array pointed to by `student_`.

Take note of the `\n` characters that might throw off your file loading. If you read data directly using the extraction
operator (`>>`), then `ignore()` will be your best friend.

### List Member Function
Create a `void` member function for `Classroom` called `list` that simply displays the list of students using the format shown
in the sample output below.

## Main Function
The main function has already been created for you. No need to modify `main.cpp`.

## Sample Output:
```
Student list
1. 505895605 Lonnie Hansen
2. 265588505 Sunny To
3. 161732427 Leah Smith
4. 877254949 San Tran
5. 644480729 Andrew Gomez
```

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Call function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex08-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cpp` and `dsa.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 dsa.cpp main.cpp -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
