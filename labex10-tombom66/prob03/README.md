# Shopping List
Create a `ShoppingList` class that has 3 private variables, a `string*` `list_`, an `int` `numItems_`, and an `int` `listSize_`.

### ShoppingList Default Constructor
The default constructor should dynamically allocate `list_` to be size 10, and initialize `numItems_` to 0.

### ShoppingList Non-Default Constructor
The non-default constructor should receive an `int` for the size of `list_` that will dynamically allocate `list_` to contain `size` number of items and set `numItems` to 0.

### ShoppingList Accessors
Create accessor functions `getNumItems()` and `getListSize()` that return `numItems_` and `listSize_`.

### ShoppingList Add Item
Create a function `addItem()` that receives a `string` and adds that item to the first available location in the list.
Adding an item should also increment `numItems_` which is also best used as an index that controls where each element is placed in the array.
If you attempt to add an item into a full list, you should display an error message `Error! Shopping List full!`.

### ShoppingList Remove Last Element
Create a function `removeLast()` that removes the last item from the list.
Specifically, it sets the value of the last element to an empty string `""` and decrements `numItems_`.

### ShoppingList Print List
Create a function `printList()` that prints all elements in the list.

### ShoppingList Destructor
Create a destructor that uses the `delete []` keyword to delete the list of shopping items.
Don't forget to set the list pointer to `nullptr` to avoid dangling references.

In `main.cpp`, create a `ShoppingList` object with the non-default constructor (pass in a value of 10), and add items to it (like the output shown below), then call the `printList` function. The values are hard-coded and do not need to be retrieved from the user (i.e., no need for `cin`).

# Output:
```
Shopping List:
1) Milk
2) Eggs
3) Flour
4) Sugar
5) Cocoa Powder
6) Vanilla
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
cd labex10-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `list.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
