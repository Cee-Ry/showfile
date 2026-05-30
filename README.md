# showfile

A simple CLI command to display file contents.

---

## Usage

```bash
show <filename>
show <file1> <file2> <file3> ...
show <option> ...
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
git clone https://github.com/Cee-Ry/showfile.git
cd showfile
cmake -B build
cmake --build build
cmake --install build
```

The `show` command will be installed to `~/.local/bin/`. Make sure it's in your `PATH`:

```bash
export PATH="$HOME/.local/bin:$PATH"
```

### Windows

```bash
git clone https://github.com/Cee-Ry/showfile.git
cd showfile
cmake -B build -G "MinGW Makefiles"
cmake --build build
cmake --install build
```
The `show` command will be installed to `C:\Users\<your username>\AppData\Local\Programs\showfile\bin`. Make sure it's executable anywhere, in `powershell` paste:

```powershell
[Environment]::SetEnvironmentVariable("Path", [Environment]::GetEnvironmentVariable("Path", "User") + ";$env:LOCALAPPDATA\Programs\showfile\bin", "User")
```

---

## Project Structure

```
showfile/
├── main.cpp          # Source code
├── CMakeLists.txt    # Build configuration
├── README.md         # This file you are reading
└── .gitignore
```

---

## License

This project is open source. Feel free to use and modify it.
