#!/bin/bash

# Makefile Generator 2.1.1

# Colors
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;35m'
BLUE='\033[0;36m'
WHITE='\033[0;37m'
BOLD='\033[1m'
RESET='\033[0;0m'

printf "${CYAN}${BOLD}\nLove Matrix?${RESET} Scan this ${BOLD}QRCode${RESET} to get source code 👋\n\n";
curl "https://raw.githubusercontent.com/aabduvak/matrix-calculator/master/assets/qrcode";
printf "\nOpening github repository?[y/n]: ";
read CONFIRM;

if [ $CONFIRM = "y" ] || [ $CONFIRM = "Y" ]; then
	open "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
fi
