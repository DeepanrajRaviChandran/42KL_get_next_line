# 42KL_get_next_line

42 get_next_line done in 42 Kuala Lumpur Campus

## Mandatory

- Read one line at time
- Return the line or NULL
- Reading a file and when reading from the standard input.
- Return line should have \n expect when its the end of the file without \n
- Compiller call -D BUFFER SIZE=n
- Undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file.
- undefined behavior when reading a binary file.

## Bonus

- Using only static variable
- Can manage multiple FD at the same time

## Requirements

- Function must be able to handle a wide variety of file formats including ASCII, UTF-8, and binary files.

## Learning & Understanding

### Static Variable
- Basiclly retains the value across multiple funtions and its always intitialized to 0 if not initialized

### What is a file descriptor
- Basically a number given to an open files(So for bonus i need to use static variable to keep track of the opened files and read them)
- 0,1,2 are stdin, stdout, stderr respectively, Thus, any opened files will be => 3.
-open() function returns a file descriptor that you can use in read(), write(), or close() functions to perform operations on that file.

### What is BUFFER_SIZE -Define the size for read()
- Bytes of memory allocated to store data(input/output commands) temporarily which allows process to take place one by one.
- Higher Buffer Size is more efficient but takes more time to compute
- Continuesly read/computes according to the buffer size at once before continuing
- Simple buffering mechanism to improve performance by reducing the number of actual read system calls.

### What is a binary files
- File that stores data in binary format, Basically information in 0 and 1(Machine Language).
- binary files store data in a format that is directly readable by the computer's hardware or specific software applications.
- used to store non-textual data, such as images, audio files, videos, executable programs, or any other type of data that requires a specific file format.

### Read system call
- ssize_t read(int fd, void *buffer, size_t count);
- fd: The file descriptor from which to read data.
- buffer: A pointer to the buffer where the data will be stored.
- count: The maximum number of bytes to read.
- returns the number of bytes read if successful, 0 if the end of the file has been reached, or -1 if an error occurred. The actual data read is stored in the buffer parameter.

## Idea
- From the buffer, tranfer each character one by one until new line. Allocate memory continuesly to append each character. If new line is not reached, increase buffer size and set the index back to 0.

## Step by Step
1. defines a default value for BUFFER_SIZE. The buffer size determines the maximum number of characters read from the file at a time.
2. t_buf, represents a buffer variable.
- buf: A character array used to store the read data.
- index: An integer representing the current index in the buffer.
- size: An integer representing the number of characters in the buffer.
