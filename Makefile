# Compiler settings
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

# Source files and target executable
SRC = server.c ft_printf.c utils.c
SRC2 = client.c ft_printf.c utils.c
EXEC = server
EXEC2 = cwel

# Object files for both executables
OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# Default target
all: $(EXEC) $(EXEC2)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
$(EXEC2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(EXEC2)

# Rule to create object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled object files
clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(EXEC) $(EXEC2)

re: fclean all

.PHONY: all clean fclean re

