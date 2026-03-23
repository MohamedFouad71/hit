# hit

hit is a git-like version control system implemented in C.

## How to Build and Run

To build and run the project, follow these steps:

1. Create a build directory and navigate into it (if you haven't already):
   ```bash
   mkdir build
   cd build
   ```

2. Generate the build files:
   ```bash
   cmake ..
   ```

3. Compile the project:
   ```bash
   make
   ```

4. Run the executable:
   ```bash
   make run
   ```

## Contribution Guidelines

- **Direct Pushes Restricted**: Pushing directly to the default (`main`) branch is restricted and closed.
- **Pull Requests Required**: All developers must create a new branch and submit a Pull Request (PR) to merge changes into `main`.
- **CI Checks**: Your pull request **must pass all CI checks** to be eligible for merging. Please ensure your code builds correctly before submitting a PR.
