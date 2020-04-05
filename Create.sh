#!/bin/bash 
date=\test-20-$(date +%m)\-$(date +%d)

fill_vim()
{
	echo "############# vim.sh ############
#!/bin/sh  

srand=\$(date +%s)
rand=\$[ \$srand%10  ]

fill()
{
	echo \"#include <stdio.h>

int main()
{
	return 0; 
}

	\" > \$1
}

if [ \$# -lt 1    ] ; then 
#   echo FileName to create is required
	fill \$rand.c \$1
	vim \$rand.c
	exit 1
fi
FileName=\$1
if [ -e \$FileName    ]; then
	vim \$FileName
	exit 1
fi
fill \$FileName \$1
vim \$FileName
exit 0
	" > $1
}

fill_makefile()
{
	echo "# File paths  
SRC_DIR := ./srcs
BUILD_DIR := ./build
OBJ_DIR := \$(BUILD_DIR)/obj

# Compilation flags 
CC := gcc
LD := gcc
CFLAGS := -Wall

# Files to be compiled
SRCS := \$(wildcard \$(SRC_DIR)/*.c)
OBJS := \$(SRCS:\$(SRC_DIR)/%.c=\$(OBJ_DIR)/%.o)
BUILD := \$(OBJS:\$(OBJ_DIR)/%.o=\$(BUILD_DIR)/%)

# Don't remove *.o files automatically
.SECONDARY: \$(OBJS)

all: \$(BUILD)

# Compile each *.c file as *.o files
\$(OBJ_DIR)/%.o: \$(SRC_DIR)/%.c 
	@echo + CC $<
	@mkdir -p \$(OBJ_DIR)
	@\$(CC) \$(CFLAGS) -c -o \$@ $<
				                
# Link each *.o file as executable files
\$(BUILD_DIR)/%: \$(OBJ_DIR)/%.o
	@echo + LD \$@
	@mkdir -p \$(BUILD_DIR)
	@\$(LD) \$(CFLAGS) -o \$@ $<
							                                
.PHONY: all clean 
clean:
	rm -rf \$(BUILD_DIR)
								
	" > $1
}

############### 开始创建工程 ################
PWD=`pwd`
if [ -e $date ]; then 
	echo " -> 无法创建目录\"$date\": 文件已存在"
	echo " -> $PWD/$date"
	exit 1
fi 
`mkdir $date`
PWD=$PWD/$date
# echo "$PWD"
# `mkdir $PWD/build`
# `touch $PWD/CMakeLists.txt`
 `mkdir $PWD/srcs`
# `touch $PWD/srcs/CMakeLists.txt`
# `mkdir $PWD/objs`
# `mkdir $PWD/libs`
# `mkdir $PWD/test`
# `mkdir $PWD/include`
# `mkdir $PWD/bin`
`touch $PWD/Makefile`
`touch $PWD/srcs/vim.sh`
fill_makefile $PWD/Makefile $1
fill_vim $PWD/srcs/vim.sh $1
chmod u+x $PWD/srcs/vim.sh 
tree $PWD/ 


