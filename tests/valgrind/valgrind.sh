#!/bin/bash

PROJECT_PATH="$(git rev-parse --show-toplevel)"
TEMP_TEST_DIR="$PROJECT_PATH/tests/temp"
HIT_EXEC_PATH="$TEMP_TEST_DIR/build/hit"
COMMANDS_FILE_PATH="$PROJECT_PATH/tests/valgrind/commands-for-valgrind.txt"

######### Build the project ##########
echo -e "\033[1;33mBuilding the project\033[0m"
mkdir -p "$TEMP_TEST_DIR/build"
cmake -S "$PROJECT_PATH" -B "$TEMP_TEST_DIR/build"
cmake --build "$TEMP_TEST_DIR/build"
echo -e "\033[0;32mSuccess: project built successfully!\033[0m"

######### Check if required files exist ##########
if [ ! -f "$HIT_EXEC_PATH" ]; then
    echo -e "\033[0;31mError: hit executable not found!\033[0m"
    exit 1
fi

if [ ! -f "$COMMANDS_FILE_PATH" ]; then
    echo -e "\033[0;31mError: commands file not found!\033[0m"
    exit 1
fi

# count commands in $COMMANDS_FILE_PATH
command_count=0
while IFS= read -r command || [ -n "$command" ]; do
    command_count=$((command_count + 1))
done < "$COMMANDS_FILE_PATH"

######### Run valgrind on all commands in $COMMANDS_FILE_PATH ##########
# For cross-platform development
echo -e "\033[1;33mRemoving \\\r from commands-for-valgrind.txt\033[0m"    
sed -i 's/\r$//' "$COMMANDS_FILE_PATH"

echo -e "\033[1;33mRunning valgrind on all commands in $COMMANDS_FILE_PATH\033[0m"

run_count=0
while IFS= read -r command || [ -n "$command" ]; do
    valgrind --error-exitcode=99 --leak-check=full --errors-for-leak-kinds=definite "$HIT_EXEC_PATH" $command
    run_count=$((run_count + 1))
    if [ $? -eq 99 ]; then
        echo -e "\033[0;31mError: hit $command has memory leaks!\033[0m"
        echo -e "\033[0;31m$run_count out of $command_count commands have been run!\033[0m"
        exit 1
    fi
    echo -e "\033[0;32mSuccess: hit $command has no memory leaks!\033[0m"
done < "$COMMANDS_FILE_PATH"

# remove temp directory
echo -e "\033[1;33mRemoving temp directory for testing\033[0m"
rm -rf "$TEMP_TEST_DIR"

######### Success ##########
echo -e "\033[0;32mAll commands have no memory leaks!\033[0m"
echo -e "\033[0;32m$run_count out of $command_count commands have been run!\033[0m"