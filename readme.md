# Llibs framework (Ellipse)

![Llibs logo](.github/img/llibs-logo.png)

## Basic information

### Main

* Based on C (2011) language
* Contains `.c` and `.h` files
* Can use *[Lingua framework](https://www.markdownguide.org)* as submodule

### How to add?

* Recommended steps to add a framework to a project

0) At first, make sure that you already have `Node JS`
1) Create `external/` folder in main directory
2) Add Llibs as submodule with command: `git submodule add "https://github.com/robotsvision/llibs"` or just download it as `.zip` archive if you don't use git system
3) Add special build scripts for your `makefile` or `Cmake` and change `Include path` to `../external/llibs/include/`