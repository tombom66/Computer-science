# Print Array Reverse
Display the contents of an array in reverse.

### printArrayReverse()
Create a function called `printArrayReverse` that prints out the contents of an integer array in reverse order (i.e., starting with the last item in the array).

Within this function you must use pointer arithmetic rather than the `[]` operator to access elements of the array.

`printArrayReverse()` will have two parameters in total:
1. an integer pointer called `array`
1. an integer called `size`

Your function has two main scenarios it could encounter.

If your function encounters an array with a size of 0 or negative, then it should output: `There are no contents in this array!`

Refer to the sample output below.

Complete the code in `main.cpp`, provide the headers in `print_array_reverse.hpp` and the implementation in `print_array_reverse.cpp`.

# Sample Output
```
Enter an integer from 1 to 10 for the size of the array: 10
Inputs for the array:
Enter the integer for index 0: 4
Enter the integer for index 1: 3
Enter the integer for index 2: 2
Enter the integer for index 3: 1
Enter the integer for index 4: 89
Enter the integer for index 5: 15
Enter the integer for index 6: 100
Enter the integer for index 7: 24
Enter the integer for index 8: 254
Enter the integer for index 9: 2
The contents of the array in reverse are:
2
254
24
100
15
89
1
2
3
4
```

```
Enter an integer from 1 to 10 for the size of the array: 0
Inputs for the array:
There are no contents in this array!
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `print_array_reverse.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
    git commit -m "Short description of your code changes"
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
