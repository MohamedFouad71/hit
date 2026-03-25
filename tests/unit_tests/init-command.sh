#!/usr/bin/env bash

PROJECT_PATH="$(git rev-parse --show-toplevel)"
TEMP_TEST_DIR="$PROJECT_PATH/tests/temp"
YELLOW="\033[1;33m"
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# run init command
echo -e "${YELLOW}Running init command${RESET}"
$TEMP_TEST_DIR/build/hit init

# check if .hit directory was created
if [ ! -d "$TEMP_TEST_DIR/.hit" ]; then
    echo -e "${RED}Error: .hit directory not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit directory found!${RESET}"

# check if .hit/HEAD file was created
if [ ! -f "$TEMP_TEST_DIR/.hit/HEAD" ]; then
    echo -e "${RED}Error: .hit/HEAD file not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/HEAD file found!${RESET}"

# check if .hit/config file was created
if [ ! -f "$TEMP_TEST_DIR/.hit/config" ]; then
    echo -e "${RED}Error: .hit/config file not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/config file found!${RESET}"

# check if .hit/description file was created
if [ ! -f "$TEMP_TEST_DIR/.hit/description" ]; then
    echo -e "${RED}Error: .hit/description file not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/description file found!${RESET}"

# check if .hit/objects directory was created
if [ ! -d "$TEMP_TEST_DIR/.hit/objects" ]; then
    echo -e "${RED}Error: .hit/objects directory not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/objects directory found!${RESET}"

# check if .hit/refs directory was created
if [ ! -d "$TEMP_TEST_DIR/.hit/refs" ]; then
    echo -e "${RED}Error: .hit/refs directory not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/refs directory found!${RESET}"

# check if .hit/refs/heads directory was created
if [ ! -d "$TEMP_TEST_DIR/.hit/refs/heads" ]; then
    echo -e "${RED}Error: .hit/refs/heads directory not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/refs/heads directory found!${RESET}"

# check if .hit/refs/tags directory was created
if [ ! -d "$TEMP_TEST_DIR/.hit/refs/tags" ]; then
    echo -e "${RED}Error: .hit/refs/tags directory not found!${RESET}"
    exit 1
fi
echo -e "${GREEN}Success: .hit/refs/tags directory found!${RESET}"

# Success
echo -e "${GREEN}Success: init command executed successfully!${RESET}"