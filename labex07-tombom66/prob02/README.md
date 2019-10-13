# Car Checker
You goal is to construct an array of `Car` objects. The size of this array should be 3.

The `main` function should prompt the user for 3 sets of car information. That being: *name*, *price*, and *mileage*. (Assume names are just 1 word long) After the cars have been inputted, then the program should find the car with the lowest price on the array, and return its *name*, *price*, and *mileage*. Take a look at example outputs to get the prompt.

### The car object
The `Car` object should have 3 data members, and a few public methods
#### Private data members
1. The name of the car, represented with `string`
1. The price of the car, represented with a `double`
1. The mileage of the car, represented with an `int`

#### Public Methods
Your function should have the following methods:

accessor for each of the private data members with their function names being:
1. `name` which has no parameters, and returns the name of the car.
1. `price` which has no parameters, and returns the price of the car.
1. `mileage` which has no parameters, and returns the mileage of the car.

mutator for each of the private data members with their function names being:
1. `set_name`, which has 1 string parameter, and no return
1. `set_price`, which has 1 double parameter, and no return
1. `set_mileage`, which has 1 int parameter, and no return

### Lowest-priced car
This function should be called `lowest_price`. It's function prototype should be in `car.hpp` and it is implemented in `car.cpp`. This function is not part of the `Car` class.

The function will take in two parameters:
1. The `Car` array
1. The size of the `Car` array (as an integer)

The goal of this function is to take the `Car` array and search through it to find the `Car` object with the lowest price, then it should return that `Car` object.

The `main` function already contains skeleton code for getting user input. You only need to fill in the missing code.

### Example Output
Here is some example output:

```
Car #1
Please enter the name: Nissan
Please enter the mileage: 89200
Please enter the price: 60000
Car #2
Please enter the name: Jeep
Please enter the mileage: 100000
Please enter the price: 3000
Car #3
Please enter the name: Civic
Please enter the mileage: 80000
Please enter the price: 5000

The car with the lowest price is Jeep with a mileage of 100000 and a price of $3000.00

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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `car.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 car.cpp main.cpp -o main
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
