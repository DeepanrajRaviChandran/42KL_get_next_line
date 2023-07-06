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

## Idea
- From the buffer, tranfer each character one by one until new line. Allocate memory continuesly to append each character. If new line is not reached, increase buffer size and set the index back to 0.

## Step by Step Mandotory
1. Defines a default value for BUFFER_SIZE. The buffer size determines the maximum number of characters read from the file at a time.
2. t_buf, represents a buffer variable.
- buf: A character array used to store the read data.
- index: An integer representing the current index in the buffer.
- size: An integer representing the number of characters in the buffer.
3. ft_realloc function is used to reallocate memory for a given pointer with a new size. Allocates memory of size size + 1 and then copies the data from the old memory block to the new one using a loop. It frees the old memory block and returns the new pointer.
4. read_buffer function reads data from the file descriptor into the buf->buf array using the read function. It reads up to BUFFER_SIZE characters and returns the number of characters read. It also updates the buf->index to 0 and buf->size to the number of characters read. Read system call keeps an internal file position and every calling it multiple time will make it to read the next sets of character.
5. append_line takes a double pointer to a string (line), a pointer to an integer (line_index), and a character (current_char). The function first reallocates memory for the line by calling ft_realloc with the new size of (*line_index + 1) * sizeof(char). If reallocation fails, it frees the old line and returns -1. If reallocation succeeds, it assigns the new memory block to *line and appends current_char at index *line_index. Finally, it increments *line_index and returns 0.
6. finalize_line a double pointer to a string (line) and an integer (line_index). The function first reallocates memory for the line by calling ft_realloc with the new size of (line_index + 1) * sizeof(char). If reallocation fails, it frees the old line, sets *line to NULL, and returns. If reallocation succeeds, it assigns the new memory block to *line and adds a null terminator ('\0') at index line_index. This indicates the end of the string.
7. The get_next_line takes a file descriptor (fd) and returns a dynamically allocated string representing the next line read from the file. The function uses a static t_buf struct called buf to store the buffer data. It also initializes line as a null pointer and line_index as 0.
- The function enters an infinite loop using while (1).
- Inside the loop, the function checks if the current index (buf.index) is equal to or greater than the size of the buffer (buf.size) to check if the buffer needs to be refilled with data from the file. If the read_buffer returns 0, that means it has reaches the EOF and if it return -1 there is an error and the loop breaks.
- Function retrieves the current character from the buffer (buf.buf[buf.index++]) and stores it in current_char.
- The function calls append_line to append current_char to the line string. If append_line returns a non-zero value, it means an error occurred, so the function returns NULL.
- The function checks if current_char is a newline character ('\n'). If it is, it means a complete line has been read, so the loop breaks.
- After the loop ends, the function checks if line is still a null pointer or if line_index is 0. If either condition is true, it means no line was read, so the function returns NULL.
- If a line was read, the function calls finalize_line to add a null terminator ('\0') at the end of the line.

## Step by Step Bonus
- A constant MAX_FD with a value of 1024 which represents the maximum number of file descriptors is defined.
- t_buf struct now includes an additional field fd, which represents the file descriptor associated with the buffer.
- The buf array in the t_buf struct is now an array of t_buf structs (t_buf buf[MAX_FD]). Each element in the array represents a separate buffer for a specific file descriptor.
- The get_next_line function, instead of using a single static buffer (buf), an array of static buffers is used (buf[MAX_FD]). The specific buffer used for a given file descriptor is accessed using buf[fd]. Only 999 fd can be used at a time.
