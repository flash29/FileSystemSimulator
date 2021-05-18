# FileSystemSimulator
Implementing a Unix/linux file system tree simulator using a binary tree.

Each node contains the following data:
1. Type : whether it is a directory or a file
2. Name of the file or directory
3. ParentPtr : Points to the parent of the current node
4. ChildPtr: Points to the first child node.
5. SibiblingPtr: Points to the node which belongs to the same parent node.

To run the program use the following commands via terminal:
1. gcc *.c
2. ./a.out

It works with the following commands:
mkdir, rmdir, pwd, cd, ls, creat, rm, save, reload, menu, quit.

The file system can be saved to a text file and can be retrieved using "save" and "reload" commands.
