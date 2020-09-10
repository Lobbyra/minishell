# Minishell - [@42Born2code](https://www.youtube.com/watch?time_continue=88&v=eawhnhTO2oY&feature=emb_logo)
![](https://miro.medium.com/fit/c/1838/551/1*v4o2AXLIJaHSZmqYZk26qA.jpeg)

---

## Introduction

Minishell is a group project for two at [42](https://www.42.fr/42-network/). The goal of this project is to create a simple shell


This project was carried out by __Jecaudal__ and __Jereligi__


## Subject


We based on bash behavior.

__*Rules of project*__

__implement the following builtins:__

- `echo` and the `-n` option
- `cd` only with an absolute or relative path
- `pwd` without any options
- `export` without any options
- `unset` without any options
- `env` without any options or arguments
- `exit` without any options

__The function to be implemented in the project__

- Display a prompt while waiting for a new order.
-  Find and launch the correct executable (based on a PATH environment variable
or using an absolute path).
- `;` in the command line must separate the commands.
- `’`and `"` must work as in bash, except multiline.
- The `<`,`>` and `>>` redirects must work as in bash, except for
aggregations of fd.
-  Pipes redirections `|`.
- The environment variables ($ followed by characters) must work.
- `$?` variable.
- `ctrl-C`, `ctrl-D` and `ctrl- \` signals should have the same behavior.

This project is coded in C with our proper norm at 42.


__Project duration__ : 4 weeks


## Installation 🖥

Run the Makefile with the `make` command to compile all the files

Then run the executable `./minishell`

```bash
minishell[/Users/user42/Desktop/minishell]$>
```

## Tips project

> ⚠️ **Warning**: Don't copy/paste code you don't understand: it's bad for you, and for the school. I have put my login in a lot of files to encourage you doing your own version. Have fun !

- Know and test your shell very well !
- Organize and structure your project


## Project documentation 📚

  [bash reference manual](https://www.gnu.org/software/bash/manual/bash.pdf)


## Contributing, Questions or suggestions ?

__42Slack :__ __*@jecaudal*__ or __*@jereligi*__

__42Intra :__ [@jecaudal](https://profile.intra.42.fr/users/jecaudal) or [@jereligi](https://profile.intra.42.fr/users/jereligi)

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
Please make sure to update tests as appropriate.


Thanks for reading this read me, advice or corrections are welcome

