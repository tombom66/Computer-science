# Double Bubble
For this exercise you need to create a `Bubble` class and construct 2 instances of the `Bubble` object. You will then take the two bubble objects and combine them to create a new, larger combined bubble object. This will be done using functions that take in these `Bubble` objects as parameters.

The `Bubble` class contains one data member, `radius_`, and accessor and mutator methods for `radius_`. It should have another method called `volume` that computes for the [volume of a bubble (sphere)](https://en.wikipedia.org/wiki/Sphere#Enclosed_volume). Use the value 3.1415 for PI.

Your `main` function has some skeleton code that asks the user for the radius of two bubbles. You will use this to create the two bubble objects. You will create a `combine_bubble` function that receives 2 parameters (2 `Bubble` objects) and returns a `Bubble` object. Combining bubbles simply means creating a new `Bubble` object whose radius is the sum of the two `Bubble` objects' radius.

Place the `Bubble` class and the `combine_bubble`'s function prototype in `bubble.hpp`. Place `combine_bubble`'s implementation in `bubble.cpp`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.

### Example Output
Here is some example output:

```
Please enter the radius of the first bubble: 4.5
Please enter the radius of the second bubble: 2.3
The bubbles have now combined and create a bubble with the volume of: 1317.05
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `bubble.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 bubble.cpp main.cpp -o main
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
