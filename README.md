# 42cursus-01-get_next_line


# 1. Considerations about the [subject](pdf/42cursus_get_next_line_v10.pdf)


## 1.1 `BUFFER_SIZE`

> Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000?

> When writing your tests, remember that:
> 1) Both the buffer size and the line size can be of very different values.

The subject gives two hints throughout the document on the implementation to be used. If the stack memory version is used, since stack is quite limited, for very high `BUFFER_SIZE` values and very large lines the function will most likely break due to insufficient memory. Please refer to [here](https://stackoverflow.com/questions/10482974/why-is-stack-memory-size-so-limited) for a thread about this discussion on the limits of the stack memory.

```c
static char buffer[BUFFER_SIZE + 1];
```

So the design should make use of dynamically allocated memory on the heap, from `malloc` family functions together with chained / linked lists.
```c
static buffer char*;
//...
buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
```

## 1.2 Handling binary files

> We also consider that get_next_line() has an undefined behavior when reading a binary file. However, **you can implement a logical way to handle this behavior if you want to.**

From [Wikipedia](https://en.wikipedia.org/wiki/Binary_file): 

*"A binary file is a computer file that is not a text file."*

So a possible implementation would be to search the buffer after the `read` function for any char that is not printable - see [`ft_isprint.c`](https://github.com/pvaladares/42cursus-00-Libft/blob/main/ft_isprint.c) - and return `NULL` if found any.


## 1.3 Handling `stdin`

> When writing your tests, remember that:
> 1) Both the buffer size and the line size can be of very different values.
> 2) **A file descriptor does not only point to regular files**.
> Be smart and cross-check with your peers. Prepare a full set of diverse tests for defense.

The subject is giving a hint that `stdin` (a non regular file) will be used to test the function being submitted. More info about file descriptors [here](https://en.wikipedia.org/wiki/File_descriptor).

# 2. Some notes about the implementation

## 2.1 Validating input for `char	*get_next_line(int fd)` function:

- Depending on how `BUFFER_SIZE` is handled inside the function, the compiler may or may not abort even with flags `-Wall -Werror -Wextra`
- Some investigation was done to find out what the maximum admissible `fd` value that could be passed to the `read` function.
- Using `uname -a` on 42 machine tells us that current kernel is `xnu-6153.141.62~1` so the current limit estimated from the latest open source (previous release) could be checked [here](https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/syslimits.h.auto.html). More info about macOS Catalina releases [here](https://en.wikipedia.org/wiki/MacOS_Catalina).

```c
#define OPEN_MAX                10240   /* max open files per process - todo, make a config option? */
```

- To be noted that the same value could be checked by using command for soft limit on file descriptors `ulimit -Sn`.


# Man

Man with references only to the used function (everything was deleted)

<details>
  
<summary>READ(2)
</summary>

```man
READ(2)                     BSD System Calls Manual                    READ(2)

NAME
     read -- read input

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

     ssize_t
     read(int fildes, void *buf, size_t nbyte);

DESCRIPTION
     read() attempts to read nbyte bytes of data from the object referenced by
     the descriptor fildes into the buffer pointed to by buf.  

     On objects capable of seeking, the read() starts at a position given by
     the pointer associated with fildes (see lseek(2)).  Upon return from
     read(), the pointer is incremented by the number of bytes actually read.

     Objects that are not capable of seeking always read from the current
     position.  The value of the pointer associated with such an object is
     undefined.

     Upon successful completion, read() returns the number of bytes actually 
     read and placed in the buffer.  
     The system guarantees to read the number of bytes requested if the 
     descriptor references a normal file that has that many bytes left before
     the end-of-file, but in no other case.

RETURN VALUES
     If successful, the number of bytes actually read is returned.  Upon read-
     ing end-of-file, zero is returned.  Otherwise, a -1 is returned and the
     global variable errno is set to indicate the error.

ERRORS
     The read() calls will succeed unless:

     [EAGAIN]           The file was marked for non-blocking I/O, and no data
                        were ready to be read.

     [EBADF]            fildes is not a valid file or socket descriptor open
                        for reading.

     [EFAULT]           Buf points outside the allocated address space.

     [EINTR]            A read from a slow device was interrupted before any
                        data arrived by the delivery of a signal.

     [EINVAL]           The pointer associated with fildes was negative.

     [EIO]              An I/O error occurred while reading from the file sys-
                        tem.

     [EIO]              The process group is orphaned.

     [EIO]              The file is a regular file, nbyte is greater than 0,
                        the starting position is before the end-of-file, and
                        the starting position is greater than or equal to the
                        offset maximum established for the open file descrip-
                        tor associated with fildes.

     [EISDIR]           An attempt is made to read a directory.

     [ENOBUFS]          An attempt to allocate a memory buffer fails.

     [ENOMEM]           Insufficient memory is available.

     [ENXIO]            An action is requested of a device that does not
                        exist..

     [ENXIO]            A requested action cannot be performed by the device.

     [ESTALE]           An attempt to read a remote file through NFS that has
                        already been deleted in the server.

     [ETIMEDOUT]        The connection timed out while reading a remote file
                        from a soft mounted NFS volume (see mount_nfs(8)).
     
     The read() call may also return the following errors:

     [ECONNRESET]       The connection is closed by the peer during a read
                        attempt on a socket.

     [ENOTCONN]         A read is attempted on an unconnected socket.

     [ETIMEDOUT]        A transmission timeout occurs during a read attempt on
                        a socket.   

LEGACY SYNOPSIS
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

     The include files <sys/types.h> and <sys/uio.h> are necessary for all
     functions.

SEE ALSO
     dup(2), fcntl(2), open(2), pipe(2), select(2), socket(2), socketpair(2),
     compat(5)

STANDARDS
     The read() function call is expected to conform to ISO/IEC 9945-1:1990
     (``POSIX.1'').  The readv() and pread() functions are expected to conform
     to X/Open Portability Guide Issue 4, Version 2 (``XPG4.2'').

HISTORY
     The pread() function call appeared in AT&T System V Release 4 UNIX.  The
     readv() function call appeared in 4.2BSD.  A read() function call
     appeared in Version 6 AT&T UNIX.

BSD                            February 26, 1994                           BSD     

```




# Resources
* [understanding get_next_line (english subtitles)](https://www.youtube.com/watch?v=-Mt2FdJjVno) - Youtube video explaining the concept of the project
* [massaaki Guide](https://github.com/massaaki/ft_phase01-get_next_line) - Great explanation about the project, including flow diagram
* [fegastal Guide](https://github.com/fegastal/42SP-get_next_line-contents) - Nice presentation with code review and detailed explanation
