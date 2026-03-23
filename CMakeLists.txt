# 1. Minimum version and project name
cmake_minimum_required(VERSION 3.10)
project(hit VERSION 1.0)

# 2. Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all .c files in the src directory and store them in a variable called 'SOURCES'
file(GLOB SOURCES "src/*.c")

# 3. Create the executable and point to the source files inside the 'src' folder
# If you have more source files (e.g., src/math.cpp), add them to this list separated by spaces!
add_executable(hit 
    ${SOURCES}
)

# 4. Tell the compiler where to find your header files
target_include_directories(hit PUBLIC include)

# command to run the executable (make run)
add_custom_target(run
    COMMAND ./hit
    DEPENDS hit
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)