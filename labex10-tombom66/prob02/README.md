# Find Number
Create a class called `Numbers`. In the private section, your class should have two variables, an `int` for the size of the array, and an `int*` for the dynamically allocated array.

### Numbers Default Constructor
Create a default constructor that initializes the size of the array to 10, and dynamically allocates a new array using that size.

### Numbers Accessors and Mutators
Create accessors called `getSize` and `getValues`. *NOTE*: the return type of `getValues` is `int*`.
Create mutators called `setSize` and `setValues`. *NOTE*: `setValues` will pass in an `int*`.

### Numbers addIntoArray
The member function `addIntoArray` will be provided for you. This member function sets initial values for your dynamically allocated array. Specifically, the values in the array are set to the even numbers between 2-20 inclusive.

### Numbers displayArray
Create a member function `displayArray` that should print out the contents of
the array, as shown in the output below.

### Numbers findNumber
Create a member function `findNumber` that takes in an `int` for the number you
want to find, but returns nothing.

This member function should check to see if the array contains the number that
is passed. If the number is present, then display a statement saying that
the number is in the array (check the output below).

### Numbers Destructor
Create a destructor that deletes the dynamically allocated array and initializes
the pointer to `nullptr`.

*NOTE: The main function is given to you. Do not edit `main.cpp`.*

# Sample Output
```
2 4 6 8 10 12 14 16 18 20
2 is in the array
10 is in the array
16 is in the array
```

*NOTE: There is a space after the number 20.*

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
cd labex02-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `find_number.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 *.cpp -o main
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
    git commit -m "short description of the code update"
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
