# 42cursus-01-get_next_line


# Considerations about the [subject](pdf/42cursus_get_next_line_v10.pdf)


## `BUFFER_SIZE`

> Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000?

> When writing your tests, remember that:
> 1) Both the buffer size and the line size can be of very different values.

The subject gives two hints throughout the document on the implementation to be used. If the stack memory version is used, since stack is quite limited, for very high `BUFFER_SIZE` values and very large lines the function will most likely break due to insufficient memory. Please refer to [here](https://stackoverflow.com/questions/10482974/why-is-stack-memory-size-so-limited) for a thread about this discussion on the limits of the stack memory.

```c
char buffer[BUFFER_SIZE + 1];
```

So the design should make use of dynamically allocated memory on the heap, from `malloc` family functions.
```c
char *buffer;
//...
buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
```

## Handling binary files

> We also consider that get_next_line() has an undefined behavior when reading a binary file. However, **you can implement a logical way to handle this behavior if you want to.**

From [Wikipedia](https://en.wikipedia.org/wiki/Binary_file): 

*"A binary file is a computer file that is not a text file."*

So a possible implementation would be to search the buffer after the `read` function for any char that is not printable - see [`ft_isprint.c`](https://github.com/pvaladares/42cursus-00-Libft/blob/main/ft_isprint.c) - and return `NULL` if found any. 

*not implemented on the current version*


## Handling `stdin`

> When writing your tests, remember that:
> 
> (...)
> 
> 2) **A file descriptor does not only point to regular files**.
> Be smart and cross-check with your peers. Prepare a full set of diverse tests for defense.

The subject is giving a hint that `stdin` (a non regular file) will be used to test the function being submitted. More info about file descriptors [here](https://en.wikipedia.org/wiki/File_descriptor).

# Some notes about the implementation

## Validating input for `char	*get_next_line(int fd)` function:

- Depending on how `BUFFER_SIZE` is handled inside the function, the compiler may or may not abort even with flags `-Wall -Werror -Wextra`
- Some investigation was done to find out what the maximum admissible `fd` value that could be passed to the `read` function.
- Using `uname -a` on 42 machine tells us that current kernel is `xnu-6153.141.62~1` so the current limit estimated from the latest open source (previous release) could be checked [here](https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/syslimits.h.auto.html). More info about macOS Catalina releases [here](https://en.wikipedia.org/wiki/MacOS_Catalina).

```c
#define OPEN_MAX                10240   /* max open files per process - todo, make a config option? */
```

- To be noted that the same value could be checked by using command for soft limit on file descriptors `ulimit -Sn`.


# Testing

## Testers
- [Tripouille / gnlTester](https://github.com/Tripouille/gnlTester)
- [xicodomingues / francinette](https://github.com/xicodomingues/francinette)
  
# Resources
* [understanding get_next_line (english subtitles)](https://www.youtube.com/watch?v=-Mt2FdJjVno) - Youtube video explaining the concept of the project
* [massaaki Guide](https://github.com/massaaki/ft_phase01-get_next_line) - Great explanation about the project, including flow diagram
* [fegastal Guide](https://github.com/fegastal/42SP-get_next_line-contents) - Nice presentation with code review and detailed explanation
