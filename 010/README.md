# Challenge 010 - To-Do List Application

## Goals for This Challenge

My goals for this challenge are the following:

+ Actually finish a project
+ Write some bad code so that I can one day write some good code
+ Improve my C++ skills through using it
+ Learn to use the Google GTest unit testing framework
+ Get better at testing my code
+ Practice following a style guide (in this case 
[Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html))
+ Write good documentation for a project
+ Make a program I would actually want to use

## Summary

As the title states, this is a To-Do List application with a CLI user interface.
I'm a big fan of To-Do lists so I wanted to make this application something that
I would want to use.

## Dependencies


## Implementation

This project gave me a chance to come up with my own architecture on how to implement
a To-Do list program. Below is higher-level-delving-into-lower-levels explanation
of that architecture and the details of the implementation of that architecture.

This program is written in C++. It is built around a hierarchy of "things to do".
The most basic building block is a **Task**, which is quite simply a single task
that needs to be done. These tasks and the things built from them are all tied to
a **User**. A User will quickly accumulate many Tasks, and so these tasks are 
organized into **Lists**. If a user has enough related Lists for a big thing that 
needs doing, these Lists can be organized into a **Project**.

Each of these objects are a class. These classes are tracked and editted through
a command line interface (the details of the commands and the usage of this program
are found further below).

## Installation

Once the program is finished I will add instructions on how to build and install
it.

## Usage

Once all the details are ironed out I will add documentation on how to use the
program.

## Things That Can Be Improved

Once we've finished the program we can do a post-mortem on it to see what can be
improved or what might have been a better way to accomplish such a program.

## License

This code is licensed under the GNU GPL3 license.
