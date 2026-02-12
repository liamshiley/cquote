# CQuotes

A lightweight C program that displays random inspirational quotes in your terminal.

## Features

- Displays random quotes from a curated collection
- Fast and lightweight
- Perfect for terminal startup messages
- No dependencies beyond standard C libraries

## Building

### Prerequisites

- GCC compiler
- Make

### Compilation
```bash
make
```

This will create the `cquotes` executable.

## Usage

### Run Once
```bash
./cquotes
```

### Running on Terminal Startup

To display a random quote every time you open a terminal:

1. **Determine your shell:**
```bash
   echo $SHELL
```

2. **Edit your shell configuration file:**
```bash
   nano ~/.bashrc  # For bash
   # or
   nano ~/.zshrc   # For zsh
```

3. **Add the following lines at the end of the file:**
```bash
   (cd /path/to/cquote && ./cquotes)
   echo -e "\n"
```
   Replace `/path/to/cquote` with the actual path to this directory.
   
   For example:
```bash
   (cd ~/Documents/Projects/cquote && ./cquotes)
   echo -e "\n"
```

4. **Apply the changes:**
```bash
   source ~/.bashrc  # or source ~/.zshrc
```

Now every new terminal will greet you with an inspirational quote!

### Alternative: Wait for Keypress

If you prefer the quote to remain visible until you press any key:
```bash
(cd /path/to/cquote && ./cquotes)
read -n 1 -s -r -p ""
```

## Quotes Database

Quotes are stored in `quotes.csv`. You can add your own quotes by following the existing format:
```
"Quote text","Author"
```

## Project Structure
```
cquote/
├── cquotes          # Compiled executable
├── main.c           # Source code
├── quotes.csv       # Quote database
├── Makefile         # Build configuration
├── LICENSE          # License file
└── README.md        # This file
```

## Cleaning Up

To remove compiled files:
```bash
make clean
```

## License

See LICENSE file for details.

## Contributing

Feel free to add more quotes to `quotes.csv` or suggest improvements!