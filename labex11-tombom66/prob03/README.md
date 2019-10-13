# Department Budget
Create a `DepartmentBudget` class that will have the following:

### Private Member Variables
1. `name_` which is a `string` that will be the name of the department
1. `budget_` which is a `double` that will be the budget allocated to this particular department
1. `current_balance_` which is a `double` that will be the current balance the department has in regards to its budget.

Ex.) If the department has yet to spend any money, and it has a `budget_` of $100 then `current_balance_` is also $100.

### Default Constructor
Create a default constructor that will:

1. initialize `name_` to the string `NULL`
1. initialize `budget_` to a value of 100.0
1. initialize `current_balance_` to a value of 100.0

### Non-Default Constructor
The non-default constructor should take only 1 parameter
1. `filename` which is a `string` that represents the file in which the spending report is located in.

EX.) Spending_Report.txt.

If the file is a valid file then it should read in the following:

1. The first input from the text file is the name of the department.
1. The second input from the text file is the budget allocated to this department.

You should use those first two values to set the `name_`, `current_balance_`, and `budget_` member variables.

Then the remaining inputs are for the spending data for the department. The department can either

1. Take out of their budget (negative inputs).
1. Put money into their budget (positive inputs).

If you look at the text file you can see a mix of positive and negative numbers.
Use these numbers to load in the spending data, and add these to our current balance.

*Hint: adding negative numbers is the same as subtracting.*

After you are done reading all inputs from the file do not forget to close the file.

If the file cannot be opened the following should happen.

1. initialize `name_` to the string `"Error"`
1. initialize `budget_` to -1
1. initialize `current_balance_` to -1

Additionally, you should output the message:
`Error with the spending report\n`

### Accessors
Create accessors that will return each of our data members.
1. `getName()` returns the `name_`
1. `getBudget()` returns the `budget_`
1. `getCurrentBalance()` returns the `current_balance_`

### Mutators
Create mutators for each of these member variables.
1. `setName()` should set the name of the department.
1. `setBudget()` should set both ` budget_` and `current_balance_` to the value passed in
1. `setCurrentBalance()` should set the current balance

### Record Spending Method
Create a `void` member function called `recordSpending` that should take in a `double` and should add that value to the `current_balance_`

## Main Function
This program should ask the user for the filename of a *spending report*. This filename should be used to create a `DepartmentBudget` object using the non-default constructor that will use the information contained in the file.

There are 3 different outputs you might encounter after loading information from the file.

  1. Your department went over budget.

The department will go over budget when the current balance is less than 0.
In that case you should output
```
<department_name> has gone over budget!\n
```
  2. Your department has budget available
The department will have budget available if the current balance is greater than or equal to 0
```
<department_name> has $<current_balance> left on their budget\n
```
  3. You read in a non-existent file
You made a slight typo or tried to load in a non-existent file.
```
Error with the spending report\n
Please choose a valid spending report\n
```

# Sample Output
Budget left over
```
Enter the name of the Spending Report you want to process: Spending_Report1.txt
Product Marketing has $7075.82 left on their budget

```
Over budget
```
Enter the name of the Spending Report you want to process: Spending_Report2.txt
Small Project has gone over budget!

```

File cannot be found.
```
Enter the name of the Spending Report you want to process: DNE.txt
Error with the spending report
Please choose a valid spending report
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `department_budget.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
    git commit -m "short description of code changes"
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
