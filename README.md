# LS COMMAND

Recreate the `ls` command in the linux terminal

Project for Epitech first year (2024)

### Description

-  `my_ls` can list directories and files just like the regular ls command, files and/or folders can be passed as arguments and the program handle these flags -[adrtR]

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`


## Usage

**Execution:**

The program can be executed with files/folders passed as arguments

```
./my_ls -[adrtR] <file_or_folder>
```

It also handle the specified flags

## Innerworkings

### Proyect structure

#### Approach

For `my_ls`, I started by implementing the basic functionality of listing directory contents, similar to the standard `ls` command. The entries are read using `readdir`, and then I applied sorting to ensure the files are displayed alphabetically. To handle different flags, I used a modular approach with function pointers, allowing each flag (e.g., `-a`, `-t`, `-r`) to be processed by its respective handler function. The program first parses the flags from the command-line arguments, then dynamically calls the correct function for each flag

#### Tools

The only allowed functions of this project were opendir, readdir, closedir, stat, lstat, write, getpwuid, getgrgid, time, ctime, readlink va_start, va_arg, va_end, malloc, free, perror, strerror, exit.

The rest were all custom made functions.

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors

* **Jad BGHIEL** ([GitHub](https://github.com/JadBghiel) / [LinkedIn](https://www.linkedin.com/in/jadbghiel/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](https://www.gnu.org/licenses/gpl-3.0.html) file for details.
