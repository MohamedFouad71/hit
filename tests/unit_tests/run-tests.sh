#!/usr/bin/env bash

################## vars ##################
PROJECT_PATH="$(git rev-parse --show-toplevel)"
TEMP_TEST_DIR="$PROJECT_PATH/tests/temp"
YELLOW="\033[1;33m"
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

################## build ##################
# temp directory for testing
mkdir -p "$TEMP_TEST_DIR"
cd "$TEMP_TEST_DIR"

# build the project
echo -e "${YELLOW}Building the project${RESET}"
cmake -S "$PROJECT_PATH" -B "$TEMP_TEST_DIR/build"
cmake --build "$TEMP_TEST_DIR/build"

# check if build was successful
if [ $? -ne 0 ]; then
    echo -e "${RED}Error: Build failed!${RESET}"
    exit 1
fi

################## tests ##################
$PROJECT_PATH/tests/unit_tests/init-command.sh

################## cleanup ##################
# remove temp directory
echo -e "${YELLOW}Removing temp directory for testing${RESET}"
rm -rf "$TEMP_TEST_DIR"
echo -e "${GREEN}Success: temp directory removed!${RESET}"