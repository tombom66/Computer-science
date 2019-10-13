# Pets
## Breed Class
Create a `Breed` class with the following:

### Private Member Variables
Create private member variables `std::string` `species_`, `name_`, and `color_`.

### Default Constructor
Create a default constructor for `Breed` that sets its `species_` to `"Dog"`, `name_` to `"Pug"`, and `color_` to `"Fawn"`.

### Non-Default Constructor
Create a non-default constructor that receives a `std::string` for `species_`, `name_`, and `color_` in that order.

### Accessors and Mutators
Create accessors called `getSpecies`, `getName`, and `getColor`.

Create mutators called `setSpecies`, `setName`, and `setColor`.

## Pet Class
Create a `Pet` class with the following:

### Private Member Variables
Create private member variables `std::string name_`, `Breed breed_` , and `double weight_`.

### Default Constructor
Create a default constructor for `Pet` that sets its name to `"Doug"` and weight to `15.6`. The `Breed` object will automatically be created using its default constructor.

### Non-Default Constructor
Create a non-default constructor that receives a `std::string` for `name_`, `Breed` for `breed_`, and a `double` for `weight_` in that order.

### Accessors and Mutators
Create accessors called `getName`, `getBreed`, and `getWeight`.

Create mutators called `setName`, `setBreed`, and `setWeight`.

### Print Member Function
Create a member function called `print` that returns `void` and does not take in any parameters.

Using the private member variables, this function should print out the name and weight of the pet. It should also utilize accessors of the `Breed` class to get the species, breed name, and color. *NOTE* This function prints only the name, species, breed, color, and weight. The cout for `Printing Pets` and `Pet #` should be in `main()`.

**NOTE**: You must use `std::setw()` (set the width to `8`) and `std::left` from the `iomanip` library to format the output.
For example:

```
std::cout << std::setw(8) << std::left << "A: " << "first text";
std::cout << std::setw(8) << std::left << "BB: " << "second text";
std::cout << std::setw(8) << std::left << "CCC: " << "third text";
```

As a result, the first argument after `std::left` will be left-aligned and take up at least 8 characters.

```
A:      first text
BB:     second text
CCC:    third text
```

Complete the `main()` function as described by the comments in `main.cpp`.

# Sample Output:
```
Please enter the pet's name (q to quit): AirBud
Please enter the pet's type: Dog
Please enter the pet's breed: Golden Retriever
Please enter the pet's color: Blonde
Please enter the pet's weight (lbs): 44.5
Please enter the pet's name (q to quit): Cookie
Please enter the pet's type: Dog
Please enter the pet's breed: English Bulldog
Please enter the pet's color: Brown & White
Please enter the pet's weight (lbs): 31.2
Please enter the pet's name (q to quit): q
Printing Pets:
Pet 1
Name:   AirBud
Species:Dog
Breed:  Golden Retriever
Color:  Blonde
Weight: 44.5 lbs
Pet 2
Name:   Cookie
Species:Dog
Breed:  English Bulldog
Color:  Brown & White
Weight: 31.2 lbs
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
cd labex11-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `pet.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
