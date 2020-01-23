# Get Next Line

2nd C project for 42 Paris school.

<b>Summary:</b> The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

<hr />

# How to use it

int get_next_line(const int fd, char **line)

<ul>
<li>The first parameter is the file descriptor that will be used to read.</li>
<li>The second parameter is the address of a pointer to a character that will be used
to save the line read from the file descriptor.</li>
<li>The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.</li>
<li>Calling get_next_line in a loop will then allow you to read the text
available on a file descriptor one line at a time until the end of the text, no matter
the size of either the text or one of its lines.</li>
</ul>

![Grade](./Get_next_line.png?raw=true "Grade")
