# showfile

A simple CLI command to display file contents.

Unlike `cat`, `showfile` separates multiple files with clear headers so you always know which file you're looking at.

---

## Usage

```bash
show <filename>
show <file1> <file2> <file3> ...
```

**Examples:**
```bash
show notes.txt
show main.cpp CMakeLists.txt
```

---

## Output

When displaying multiple files, each file is wrapped with a header:

```
=== === file1.txt === ===
(contents of file1)


=== === file2.txt === ===
(contents of file2)
```

---

## Building & Installing

### Requirements
- CMake 3.10+
- A C++ compiler (GCC, Clang, or MSVC)

### Linux / macOS

```bash
git clone https://github.com/yourusername/showfile.git
cd showfile
mkdir build && cd build
cmake ..
make
make install
```

The `show` command will be installed to `~/.local/bin/`. Make sure it's in your `PATH`:

```bash
export PATH="$HOME/.local/bin:$PATH"
```

### Windows

```bash
git clone https://github.com/yourusername/showfile.git
cd showfile
mkdir build && cd build
cmake ..
cmake --build .
cmake --install .
```

---

## Project Structure

```
showfile/
├── main.cpp          # Source code
├── CMakeLists.txt    # Build configuration
└── .gitignore
```

---

## License

This project is open source. Feel free to use and modify it.
