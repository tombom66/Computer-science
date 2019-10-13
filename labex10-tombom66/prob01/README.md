# Player
Create a `Player` class with constructors and member functions. Your class should also have accessors and mutators.

Your class should have the following private member variables: an `int` for an x position, an `int` for a y position, a `string` for the player's name, an `int` for the health, an `int` for the strength, and an `int` for the defense.

### Accessors & Mutators
Your accessors should be named: `getXpos`, `getYpos`, `getName`, `getHealth`, `getStrength`, and `getDefense`.
Your mutators should be named: `setXpos`, `setYpos`, `setName`, `setHealth`, `setStrength`, and `setDefense`.

### Player Default Constructor
Create a default constructor that initializes the member variables to the following values:
`0` for the x position, `0` for the y position, `Bob` for the name, `10` for the health, `5` for the strength and `2` for the defense.

### Player Non-Default Constructor
Create another constructor that takes in 6 parameters: the name, the health, the strength, the defense, the x position, and the y position respectively.

### Player displayStat
Create a member function called `displayStat` that takes in no parameters and does not return anything.

This member function should `cout` the name of the player, the player's health, the player's strength, the player's defense, and the player's (x,y) coordinates, respectively. Follow the format of the sample output provided below.

### Player playerMove
Create a member function called `playerMove` that takes in no parameters and does not return anything.

This member function should increment the x position and the y position by a value of 1.

### Player isPlayerDead
Create a member function called `isPlayerDead` that takes in no parameters and returns a `bool` value.

This member funciton should check the player's health. If the player's health is equal to 0, then return `true`, otherwise return `false`.

### Player takeDamage
Create a member function called `takeDamage` that takes in an `int` value for the damage taken and returns nothing.

This member function should `cout` a statement saying that the player took damage, and decrease the player's health based on the damage taken. If the damage taken is greater than the player's current health, set the player's health to 0 (the player cannot have negative health).

This member function should also call the `isPlayerDead` function. Using that function, if the player is dead, `cout` a statement saying that the player is dead. Follow the format of the sample output provided below.

# main()
The main function is provided for you. Do not edit the `main.cpp` file.

Output
```
Player: Bob
Health: 10
Strength: 5
Defense: 2
At position: (10, 10)

Player: Mary
Health: 20
Strength: 10
Defense: 6
At position: (0, 0)

Bob took 25 damage
Bob is dead

Player: Bob
Health: 0
Strength: 5
Defense: 2
At position: (10, 10)
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `player.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
