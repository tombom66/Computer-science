# Athlete and Shoe
In this program, you will be creating two classes called `AthleticShoe` and `Athlete`.

## AthleticShoe Class
Create a class called `AthleticShoe` that will have the following:

### Private Member Variables
1. `style_` which is a `std::string` that represents the style of the shoe (i.e. Jogging, Basketball, Cleats).
1. `color_` which is a `std::string` that represents the color of the shoe.
1. `size_` which is a `double` that represents the size of the shoe (i.e. 9.5 inches).

### Default Constructor
Create a default constructor for `AthleticShoe` that sets `style_` to `"Running"`, `color_` to `"Blue"`, and `size_` to `12.0`.

### Non-Default Constructor
Create a non-default constructor that receives two `std::string` for `style_` and `color_`, and a double for `size_` respectively.

### Accessors and Mutators
Create accessors called `getStyle()`, `getColor()`, and `getSize()`.
Create mutators called `setStyle()`, `setColor()`, and `setSize()`.

## Athlete class
Create a class called `Athlete` that inherits from class `Person`, which is provided already in the `athlete.hpp` file. Class `Athlete` will have the following:

### Private Member Variables
1. `sport_` which is a `std::string` that represents the type of sport (i.e. Soccer, Tennis, etc.).
1. `height_` which is an `int` that represents the height of the athlete.
1. `weight_` which is an `int` that represents the weight of the athlete.
1. `shoe_` which is a **pointer** to `AthleticShoe`

### Default Constructor
Create a default constructor for `Athlete` that sets `sport_` to `"Cross-Country"`, `height_` to `72`
and `weight_` to `180`. It should also dynamically allocate memory for an `AthleticShoe` object that is assigned to `shoe_`. And lastly, it should set the name of the `Person` to `"Tuffy Default"`.

### Non-Default Constructor
Create a non-default constructor that receives a `std::string` for `name`, `std::string` for `sport_`, two `int` values for `height_` and `weight_`, and a **pointer** to an `AthleticShoe` object for `shoe_` respectively. Use the parameters to initialize the respective data members.

### Accessors and Mutators
Create accessors called `getSport()`, `getHeight()`, `getWeight()`, and `getShoe()`. *NOTE*: `getShoe()` must return a **pointer**.
Create mutators called `setSport()`, `setHeight()`, `setWeight()`, and `setShoe()`. *NOTE*: `setShoe()` must pass in a **pointer**.

### Print Member Function
Create a member function for `Athlete` called `print` that prints the athlete's information. *NOTE*: You must use `std::setw(8)` and `std::left` to print the name, sport, height, and weight values of the athlete and use `std::setw(10)` to print the style, color, and size of the associated `AthleticShoe` object.

## Main Function
Complete the main function as described.

Sample Output:
```
Please enter the athlete's sport (q to quit): Baseball
Please enter the athlete's name: Tuffy One
Please enter the athlete's height (in): 74
Please enter the athlete's weight (lbs): 195
Please enter the shoe style: Cleats
Please enter the shoe color: Red & White
Please enter the shoe size (in): 12.5
Please enter the athlete's sport (q to quit): Basketball
Please enter the athlete's name: Tuffy Two
Please enter the athlete's height (in): 66
Please enter the athlete's weight (lbs): 150
Please enter the shoe style: Basketball
Please enter the shoe color: Blue & Gold
Please enter the shoe size (in): 9
Please enter the athlete's sport (q to quit): q
Printing Athletes:
Athlete 1
Name:   Tuffy One
Sport:  Baseball
Height: 74in
Weight: 195lbs
Shoe:
  Style:  Cleats
  Color:  Red & White
  Size:   12.5in
Athlete 2
Name:   Tuffy Two
Sport:  Basketball
Height: 66in
Weight: 150lbs
Shoe:
  Style:  Basketball
  Color:  Blue & Gold
  Size:   9in
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
cd labex12-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cpp` and `athlete.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 athlete.cpp main.cpp -o main
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
