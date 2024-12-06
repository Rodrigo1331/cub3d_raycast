#!/bin/bash

# Define the colors
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
GRAY='\033[1;37m'
WHITE='\033[1;97m'
NC='\033[0m' # No color

map_messages=(
    "1 char (wall)"
    "2 exits"
    "2 players"
    "empty map"
    "no collectebles"
    "no corner walls"
    "no exit"
    "no exit path"
    "no path"
    "no player"
    "no rectangular map"
    "no walls"
    "wrong tiles"
    "no collectebles path"
    "no collectebles path2"
    "good map - control"
)

echo -e "${YELLOW}\nSO_LONG (Mandatory Part)\n${NC}"

all_ok=true  # Flag to track overall success
bonus_failure=false  # Flag to track bonus test failure

valgrind_leaks="Valgrind LEAKS FREE"
valgrind_errors="Valgrind ERRORS FREE"

# Loop through map numbers from 1 to 16
for i in $(seq 1 16); do
    map_file="maps_check_errors/${i}.ber"
    message="${map_messages[i - 1]}"

    echo -e "${YELLOW}SO_LONG ${BLUE}map ${i}:${CYAN}${message}${NC}"

    # Test for MANDATORY version
    output=$(./so_long ${map_file} 2>&1)

    if [[ "$i" -le 15 ]]; then
        if [[ "$output" == *"Couldn't open requested file."* ]]; then
            echo -e "${RED}Error${NC}"
            echo "${output}" | grep -v "Error"
            echo -e "${RED}FAILURE - your code has some problems${NC}"
            all_ok=false
        elif [[ "$output" == *"Error"* ]]; then
            echo -e "${RED}Error${NC}"
            echo "${output}" | grep -v "Error"
            echo -e "${GREEN}OK${NC}"
        else
            echo -e "${RED}FAIL${NC}"
            all_ok=false
        fi
    else
        if [[ "$i" -eq 16 ]]; then
            if [[ "$output" == *"Map has invalid path."* ]]; then
                echo -e "${RED}FAILURE - your code has some problems in the bonus tests!! 😡\n${NC}"
                bonus_failure=true
            else
                echo -e "${GREEN}OK${NC}"
            fi
        else
            if [[ "$output" == *"Couldn't open requested file."* ]]; then
                echo -e "${RED}Error${NC}"
                echo "${output}" | grep -v "Error"
            else
                echo -e "${RED}FAIL${NC}"
            fi
        fi
    fi

# Test for MANDATORY version with Valgrind
    valgrind_output=$(valgrind ./so_long "${map_file}" 2>&1)
        
    # Check for memory leaks message
    if [[ "$valgrind_output" == *"All heap blocks were freed -- no leaks are possible"* ]]; then
        echo -e "${WHITE}Valgrind ${GREEN}without LEAKS${NC}"
    else
        echo -e "${WHITE}Valgrind ${RED}with LEAKS${NC}"
        all_ok=false
        valgrind_leaks="${RED}Valgrind HAVE LEAKS"
    fi
        
    # Check for error summary message
    if [[ "$valgrind_output" == *"ERROR SUMMARY: 0 errors from 0 contexts"* ]]; then
        echo -e "${WHITE}Valgrind ${GREEN}without ERRORS${NC}"
    else
        echo -e "$${WHITE}Valgrind {RED}with ERRORS${NC}"
        all_ok=false
        valgrind_errors="${RED}Valgrind HAVE ERRORS"
    fi

    echo "--------------------------------------------"
done


# Check if all first 15 tests passed
if $all_ok; then
    # Check bonus test 16 result
    if ! $bonus_failure; then
        echo -e "${GREEN}\nTUDO OK !! WELL DONE !! 👌\n${NC}"
    fi
else
    echo -e "${RED}\nFAILURE - your code has some problems in the mandatory tests !! 😡\n${NC}"
fi

# Ask if they want to continue with SO_LONG_BONUS
read -p "Do you want to continue with SO_LONG_BONUS? (y/n): " continue_bonus

if [[ "$continue_bonus" == "y" || "$continue_bonus" == "Y" ]]; then
    # Continue with SO_LONG_BONUS
    echo -e "${YELLOW}\nContinuing with SO_LONG_BONUS...\n${NC}"

    all_ok=true  # Reset flag for bonus tests
    bonus_failure=false  # Reset flag for bonus test failure

    # Loop through map numbers from 1 to 16
    for i in $(seq 1 16); do
        map_file="maps_check_errors/${i}.ber"
        message="${map_messages[i - 1]}"

        echo -e "${YELLOW}SO_LONG_BONUS ${BLUE}map ${i}:${CYAN}${message}${NC}"

        # Test for BONUS version
        output=$(./so_long_bonus ${map_file} 2>&1)

        if [[ "$i" -le 15 ]]; then
            if [[ "$output" == *"Couldn't open requested file."* ]]; then
                echo -e "${RED}Error${NC}"
                echo "${output}" | grep -v "Error"
                echo -e "${RED}FAILURE - your code has some problems${NC}"
                all_ok=false
            elif [[ "$output" == *"Error"* ]]; then
                echo -e "${RED}Error${NC}"
                echo "${output}" | grep -v "Error"
                echo -e "${GREEN}OK${NC}"
            else
                echo -e "${RED}FAIL${NC}"
                all_ok=false
            fi
        else
            if [[ "$i" -eq 16 ]]; then
                if [[ "$output" == *"Map has invalid path."* ]]; then
                    echo -e "${RED}FAILURE - Map has invalid path!! 😡\n${NC}"
                    bonus_failure=true
                else
                    echo -e "${GREEN}OK${NC}"
                fi
            else
                if [[ "$output" == *"Couldn't open requested file."* ]]; then
                    echo -e "${RED}Error${NC}"
                    echo "${output}" | grep -v "Error"
                else
                    echo -e "${RED}FAIL${NC}"
                fi
            fi
        fi

    # Test for BONUS version with Valgrind
    valgrind_output=$(valgrind ./so_long_bonus "${map_file}" 2>&1)
        
    # Check for memory leaks message
    if [[ "$valgrind_output" == *"All heap blocks were freed -- no leaks are possible"* ]]; then
        echo -e "${WHITE}Valgrind ${GREEN}without LEAKS${NC}"
    else
        echo -e "${WHITE}Valgrind ${RED}with LEAKS${NC}"
        all_ok=false
        valgrind_leaks="${RED}Valgrind HAVE LEAKS"
    fi
        
    # Check for error summary message
    if [[ "$valgrind_output" == *"ERROR SUMMARY: 0 errors from 0 contexts"* ]]; then
        echo -e "${WHITE}Valgrind ${GREEN}without ERRORS${NC}"
    else
        echo -e "$${WHITE}Valgrind {RED}with ERRORS${NC}"
        all_ok=false
        valgrind_errors="${RED}Valgrind HAVE ERRORS"
    fi


        echo "--------------------------------------------"
    done

    # Check if all bonus tests passed
    if $all_ok && ! $bonus_failure; then
        echo -e "${GREEN}\nTUDO OK !! WELL DONE !! 👌\n${NC}"
        echo -e  "${GRAY}Bye bye, thanks for using me! 😀\n${NC}"
        echo -e  "${YELLOW}Credits: ${CYAN}fde-carv (42Porto)\n${NC}"
    else
        echo -e "${RED}\nFAILURE - your code has some problems in the bonus tests!! 😡\n${NC}"
        echo -e  "${GRAY}\nBye bye, thanks for using me! 😀\n${NC}"
        echo -e  "${YELLOW}Credits: ${CYAN}fde-carv (42Porto)\n${NC}"
    fi

    else
        echo -e  "${GRAY}\nBye bye, thanks for using me! 😀\n${NC}"
        echo -e  "${YELLOW}Credits: ${CYAN}fde-carv (42Porto)\n${NC}"
    fi

    # Display Valgrind results
echo -e "${GREEN}${valgrind_leaks}${NC}"
echo -e "${GREEN}${valgrind_errors}$\n${NC}"
