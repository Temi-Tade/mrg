# mrg

A lightweight, high-performance Unix-style CLI tool written in C to merge multiple source files into a single target file.

## Features
- **Fast & Minimal:** Written in pure C with zero external dependencies.
- **Safe Execution:** Built-in protection to prevent overwriting source files if they match the target.
- **Unix-Compliant:** Follows standard CLI conventions for easy piping and automation.

## Usage

```bash
mrg <file1> <file2> ... <fileN> <target>
```

### Example
```bash
# Combine three separate text parts into one complete document
mrg intro.txt body.txt conclusion.txt final_report.txt
```

## Installation
You can install `mrg` via two options:
### 1. Quick install
Install pre-compiled binaries directly
```bash
curl -L -o mrg https://github.com/Temi-Tade/mrg/releases/download/v1.0.0/mrg && chmod +x mrg && sudo mv mrg /usr/local/bin/
```

### 2. Build from Source
You will need a C compiler like `gcc` or `clang` installed on your system.
1. Clone the repository:
   ```bash
   git clone https://github.com/Temi-Tade/mrg
   cd mrg
   ```

2. Compile the source code:
   ```bash
   gcc -Wall -Wextra -O2 main.c -o mrg
   ```

3. (Optional) Move it to your local binaries path to use it globally:
   ```bash
   sudo mv mrg /usr/local/bin/
   ```

# License
MIT
