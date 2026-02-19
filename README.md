# Pipex

## 📋 Description

**pipex** is a 42 School project that recreates shell pipe behavior. The program simulates the execution of commands connected by pipes, managing processes, file descriptors, and inter-process communication (IPC). This project teaches about process creation with `fork`, input/output redirection, and pipe manipulation.

---

## 🎯 Features

### Basic Behavior
```bash
./pipex file1 cmd1 cmd2 file2
```
Equivalent to:
```bash
< file1 cmd1 | cmd2 > file2
```
---

### Features
- ✅ Executes two commands connected by pipe
- ✅ Reads input from a file
- ✅ Writes output to a file
- ✅ Manages child processes with `fork`
- ✅ Uses `pipe` for inter-process communication
- ✅ Handles file descriptors with `dup2`
- ✅ Proper error handling

---

# 🎯 Concepts Learned

- **Processes:** Creation with `fork()` and execution with `execve()`
- **Pipes:** Inter-process communication using `pipe()`
- **File Descriptors:** Manipulation with `dup2()`, `open()`, `close()`
- **Redirection:** Process input and output
- **Synchronization:** Using `wait()` and `waitpid()`
- **Memory Management:** Proper resource deallocation
- **Error Handling:** Validation and error messages
