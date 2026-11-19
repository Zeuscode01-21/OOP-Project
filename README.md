# C++ OOP Laboratory Experiments

A GitHub-ready collection of C++ programs for the 11 experiments in the supplied practical list.

## Repository structure

```text
Cpp_OOP_Lab_GitHub/
├── Experiment-01-Fundamentals/
│   └── main.cpp
├── Experiment-02-Class-Hierarchy/
│   └── main.cpp
├── Experiment-03-Constructors-Rule-of-5/
│   └── main.cpp
├── Experiment-04-Inheritance/
│   └── main.cpp
├── Experiment-05-Runtime-Polymorphism/
│   └── main.cpp
├── Experiment-06-Compile-Time-Polymorphism/
│   └── main.cpp
├── Experiment-07-Templates/
│   └── main.cpp
├── Experiment-08-STL/
│   └── main.cpp
├── Experiment-09-Exceptions/
│   └── main.cpp
├── Experiment-10-File-Handling-CSV/
│   └── main.cpp
└── Experiment-11-Mini-Project-Student-Management/
    └── main.cpp
```

## Requirements

- A C++17-compatible compiler (GCC, Clang, or MSVC).
- Optional: Valgrind on Linux for Experiment 03.

## Compile and run

Open a terminal in the repository folder. For any experiment, run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Experiment-01-Fundamentals/main.cpp -o experiment
./experiment
```

Replace the folder path with the experiment you want to run. On Windows, run the generated executable as:

```powershell
.\experiment.exe
```

You can also compile each `main.cpp` separately in VS Code. Each experiment has its own `main()` function, so do not compile all files into one executable at the same time.

## Experiment 03: Valgrind

On Linux, compile with debug information:

```bash
g++ -std=c++17 -g -Wall -Wextra Experiment-03-Constructors-Rule-of-5/main.cpp -o constructors
valgrind --leak-check=full --track-origins=yes ./constructors
```

The program uses RAII and correctly releases its dynamically allocated memory. A clean run should report no definitely-lost memory.

## Push this repository to GitHub

1. Create a new empty repository on GitHub.
2. Extract this ZIP file.
3. Open a terminal in the extracted `Cpp_OOP_Lab_GitHub` folder.
4. Run:

```bash
git init
git add .
git commit -m "Add C++ OOP laboratory experiments"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
git push -u origin main
```

Replace the remote URL with your own GitHub repository URL.

## Notes

- Programs include comments to identify the concepts being demonstrated.
- Experiment 10 creates `students.csv` in the current working directory when run.
- Experiment 11 creates `student_records.csv` in the current working directory and provides a menu-driven student record system.
- CSV examples use simple comma-separated fields and avoid commas inside names or course names.
