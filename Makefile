NAME     = libasm.a
RM       = rm -rf
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
ASM      = nasm
ASMFLAGS = -f macho64
AR       = ar rc
RL       = ranlib
LDFLAGS  = -L.
LDLIBS   = -lasm
SRC_DIR  = src
SRC_NAME = ft__strlen.c\
		   ft__strcpy.c\
		   ft__strcmp.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR  = obj
SRC      = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ      = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^
	$(RL) $@
	

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@

test: $(NAME)
	gcc $(LDFLAGS) $(LDLIBS) -o test/test test/main.c 
	./test/test
clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
