# 42cursus-01-get_next_line


# Man

```bash man
READ(2)                                  System Calls Manual                                  READ(2)

NAME
     read – read input

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

     ssize_t
     read(int fildes, void *buf, size_t nbyte);

DESCRIPTION
     read() attempts to read nbyte bytes of data from the object referenced by the descriptor fildes
     into the buffer pointed to by buf.  

     On objects capable of seeking, the read() starts at a position given by the pointer associated
     with fildes (see lseek(2)).  
     Upon return from read(), the pointer is incremented by the number of bytes actually read.

     Objects that are not capable of seeking always read from the current position.  
     The value of the pointer associated with such an object is undefined.

     Upon successful completion, read() returns the number of bytes actually read and placed in the 
     buffer.
     The system guarantees to read the number of bytes requested if the descriptor references a 
     normal file that has that many bytes left before the end-of-file, but in no other case.

     read() will fail if the parameter nbyte exceeds INT_MAX, and it does not attempt a partial read.

RETURN VALUES
     If successful, the number of bytes actually read is returned.  
     Upon reading end-of-file, zero is returned.  
     Otherwise, a -1 is returned and the global variable errno is set to indicate the error.

ERRORS
     The read() calls will succeed unless:

     [EAGAIN]           The file was marked for non-blocking I/O, and no data were ready to be read.

     [EBADF]            fildes is not a valid file or socket descriptor open for reading.

     [EFAULT]           Buf points outside the allocated address space.

     [EINTR]            A read from a slow device was interrupted before any data arrived by the
                        delivery of a signal.

     [EINVAL]           The pointer associated with fildes was negative.

     [EIO]              An I/O error occurred while reading from the file system.

     [EIO]              The process group is orphaned.

     [EIO]              The file is a regular file, nbyte is greater than 0, the starting position is
                        before the end-of-file, and the starting position is greater than or equal to
                        the offset maximum established for the open file descriptor associated with
                        fildes.

     [EISDIR]           An attempt is made to read a directory.

     [ENOBUFS]          An attempt to allocate a memory buffer fails.

     [ENOMEM]           Insufficient memory is available.
     
     [ENXIO]            An action is requested of a device that does not exist.

     [ENXIO]            A requested action cannot be performed by the device.

     [ESTALE]           An attempt to read a remote file through NFS that has already been deleted in
                        the server.

     [ETIMEDOUT]        The connection timed out while reading a remote file from a soft mounted NFS
                        volume (see mount_nfs(8)).

     [ETIMEDOUT]        The file is a “dataless” file that requires materialization and
                        materialization timed out or encountered some other temporary failure.

     [EDEADLK]          The file is a “dataless” file that requires materialization and the I/O
                        policy of the current thread or process disallows dataless file
                        materialization (see getiopolicy_np(3)).

     [ECONNRESET]       The connection is closed by the peer during a read attempt on a socket.

     [ENOTCONN]         A read is attempted on an unconnected socket.

     [ETIMEDOUT]        A transmission timeout occurs during a read attempt on a socket.

     [EINVAL]           The value provided for nbyte exceeds INT_MAX.

LEGACY SYNOPSIS
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

     The include files <sys/types.h> and <sys/uio.h> are necessary for all functions.

SEE ALSO

```




# Resources
* [understanding get_next_line (english subtitles)](https://www.youtube.com/watch?v=-Mt2FdJjVno) - Youtube video explaining the concept of the project
* [massaaki Guide](https://github.com/massaaki/ft_phase01-get_next_line) - Great explanation about the project, including flow diagram
* [fegastal Guide](https://github.com/fegastal/42SP-get_next_line-contents) - Nice presentation with code review and detailed explanation
