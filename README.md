# Pipe example in C
Simple example of C program that creates a pipe and then forks.
Then the child communicates to the parent over the pipe.

#### What is a pipe?

It is a one-way communication mechanism, with one end opened for reading and the other end for writing. Therefore, parent and child need to agree on which way to turn the pipe, from parent to child or the other way around.

#### Reference:

[An Introductory 4.3BSD Interprocess Communication Tutorial, by Stuart Sechrest and An Advanced 4.3BSD](https://docs.freebsd.org/44doc/psd/20.ipctut/paper.pdf)
