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
- Basiclly retains the value across multiple funtions calls and its always intitialized to 0 if not initialized.
- By using a static variable, the get_next_line function maintains the buffer state across function calls.

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
- It ensures that any remaining data from the previous read is processed in subsequent calls until the buffer is fully consumed.

### Read system call
- ssize_t read(int fd, void *buffer, size_t count);
- fd: The file descriptor from which to read data.
- buffer: A pointer to the buffer where the data will be stored.
- count: The maximum number of bytes to read.
- returns the number of bytes read if successful, 0 if the end of the file has been reached, or -1 if an error occurred. The actual data read is stored in the buffer parameter.

## Step by Step Mandotory
1. Defines a default value for BUFFER_SIZE. The buffer size determines the maximum number of characters read from the file at a time.
2. ft_read_fd: Reads from a file descriptor fd into line_buffer until a newline character is encountered or the end of the file is reached. Reads data in chunks of BUFFER_SIZE, appends the read data to line_buffer using ft_strjoin_mod, and returns the number of bytes read. If an error occurs during the read operation, it returns -1.
3. ft_get_line: Creates a new string new_line by copying characters from str until a newline character or the end of the string is encountered. It allocates memory for new_line and returns it
4. Creates a new string str by copying characters from line_buffer after the newline character. It allocates memory for str and returns it. It also frees the memory allocated for line_buffer
5. get_next_line:
- It allocates memory for a buffer of size BUFFER_SIZE + 1 using malloc. This buffer will be used for reading data from the file descriptor. Plus 1 in size is for the NULL terminator
- It calls the ft_read_fd function, passing the file descriptor fd, the address of line_buffer, and the buffer. The purpose of this function is to read data from fd and append it to line_buffer until a newline character is encountered or the end of the file is reached. It returns the number of bytes read. If an error occurs during the read operation, it returns -1.
- The ft_get_line function, passing line_buffer. This function creates a new string line by copying characters from line_buffer until a newline character or the end of the string is encountered. It returns the newly created line.
- updates line_buffer by calling the ft_strclean function, passing line_buffer. This function creates a new string str by copying characters from line_buffer after the newline character. It returns the newly created str. It also frees the memory allocated for line_buffer.
- Finally, the code frees the memory allocated for the buffer and returns the line obtained from the file descriptor.

## Step by Step Bonus
- static char *line_buffer[MAX_FD]; introduces a new static array called line_buffer. It is an array of character pointers that stores the line buffers for multiple file descriptors.
- The line bytes = ft_read_fd(fd, &line_buffer[fd], buffer); replaces the usage of the previous line_buffer variable with line_buffer[fd]. Now, instead of using a single line buffer for all file descriptors, each file descriptor fd has its own associated line buffer stored in the line_buffer array.
- line = ft_get_line(line_buffer[fd]); is unchanged and retrieves the line from the appropriate line_buffer for the given file descriptor fd.
- line_buffer[fd] = ft_strclean(line_buffer[fd]); updates the corresponding line buffer for fd by removing the processed line. The ft_strclean function is called on line_buffer[fd] to obtain the remaining part of the buffer after the processed line.
-this modification allows the get_next_line function to handle multiple file descriptors simultaneously by maintaining separate line buffers for each file descriptor in the line_buffer array. This enables independent reading of lines from different file descriptors without interfering with each other.
