*This project has been created as part of the 42 curriculum by bastalze*

# Description
Prototype: char \*get\_next\_line(int fd);

The function returns continuously one line at each function call from the document specified with
the file descriptor fd. There is no going back to a previous line.

If mallocation fails it returns NULL.

# Instruction
The default buffer size is 100. If you want to define your own buffer size add "-D BUFFER\_SIZE=n",
with n being the desired buffer size, to your compilation call.

To use get\_next\_line to read through a document include the headerfile get\_next\_line.h and use
the functions open to get fd and close to close the file again.

# Resources

## Online research
Due to the late implementation im the mandatory README for the project I did not document in detail
what I googled in detail. I definitely looked up concepts on geeksforgeeks.org and similar websites.
Stackoverflow never really helped me that much.

## Peers
Special thanks goes out to my fellow students especially Kian who helped me a lot talking through
concepts and looking at my buggy code. Thanks also go out to David, Irene and Myron who helped me 
fixing little errors and thank you to Stefan A. who did some rigorous debugging.

## AI
I used deepseek.com mainly like a colleague, to explain me code snippets and debug small pieces.
