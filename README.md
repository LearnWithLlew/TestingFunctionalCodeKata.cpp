# Goal

The goal here is to get 100% of the lines and branches unit-tested in the code `TrigMath.h`.

By branches, we mean that both the `true` and `false` paths of every expression in every `if` statement should be reached. This means that you will have more than one test per method. 

## How-To

In `Test.cpp`, we have written the first test for you. Warning: It does not pass.

Get it to pass. Then write some more tests. You should never be changing anything in `TrigMath.h`. 

It is highly suggested that you use some form of code coverage tool in the editor, so that you can see what your next step is.

## Setting up and running with code coverage

### CLion on Unix

* TODO Add more info

Add these lines to `~/.lcovrc`:

```
genhtml_branch_coverage = 1
lcov_branch_coverage = 1
lcov_excl_br_line = LCOV_EXCL_BR_LINE|CHECK|REQUIRE
```

### MS Visual Studio

* Install OpenCppCoverage from the Market Place
* TODO Add more info


## Run from command line

These are the two commands I run to on my computer
``` bash
/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" /Users/llewellyn/Github/TestingFunctionalCodeKata.cpp
./cmake-build-debug/tests/TestingFunctionalCodeKataTests
```