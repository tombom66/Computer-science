# Power
Write the `power` function in `power.cpp`, then use it in `main.cpp` where you ask the user for input. The power function takes two integer parameters: base and power. It returns the result of the base raised to the power.

Assume that the base will always be a positive integer (zero or greater).

The `main` function in `main.cpp` should ask the user to input a number and and call the appropriate function to display the correct output. Take a look at the sample input/output below.

*Hint: Be careful with your local variable names. If you use the same name for a local variable as the function name, the compiler will assume you are referring to the local variable when you try to call the function. This has to do with scope. Your function's name should be `power`, so the local variables need to be something else.*

Sample input/output:
```
Please enter the base number: 5
Please enter the power: 3
5 ^ 3 = 125
```

```
Please enter the base number: 2
Please enter the power: 2
2 ^ 2 = 4
```

```
Please enter the base number: 4
Please enter the power: 4
4 ^ 4 = 256
```

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Called function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. Tested the program using the sample inputs
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex06-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex06-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `power.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 power.cpp main.cpp -o main
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
    Or to add only specific files, provide the list of file names you wish to add. For example,
    ```
    git add filename1.cpp filename1.hpp filename2.cpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit -m "Description of the code updates"
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
