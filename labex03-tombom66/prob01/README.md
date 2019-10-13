# Operations
Write a program that will compute an operation based on the user input. The program should ask the user to input the type of operation ('+' = Addition, '-' = Subtraction, '*' = Multiplication, '/' = Division), and input two numbers to be operated upon. The program should display an error message if the user does not input a valid operation number. Display the result of the operation. Follow the sample output below as closely as possible. Take note that different user input results in a different output.

Addition
```
Please enter in the operation (+, -, *, /): +
Please input the first number: 5
Please input the second number: 6
You chose to add: 5 + 6 = 11
```

Subtraction
```
Please enter in the operation (+, -, *, /): -
Please input the first number: 5
Please input the second number: 6
You chose to subtract: 5 - 6 = -1
```

Multiplication
```
Please enter in the operation (+, -, *, /): *
Please input the first number: 5
Please input the second number: 6
You chose to multiply: 5 * 6 = 30
```

Division
```
Please enter in the operation (+, -, *, /): /
Please input the first number: 5
Please input the second number: 6
You chose to divide: 5 / 6 = 0
```

Invalid operation:
```
Please enter in the operation (+, -, *, /): $
Please input the first number: 5
Please input the second number: 6
Invalid operation type.
```
# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp -o main
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
