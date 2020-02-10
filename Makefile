NAME     = libasm.a
RM       = rm -rf
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
AS       = nasm
ASFLAGS  = -f macho64
ARFLAGS  = rc
RL       = ranlib
LDFLAGS  = -L.
LDLIBS   = -lasm
SRC_DIR  = src
SRC_NAME = ft__strlen.s\
		   ft__strcpy.s\
		   ft__strcmp.s\
		   ft__write.s\
		   ft__read.s
OBJ_NAME = $(SRC_NAME:.s=.o)
OBJ_DIR  = obj
SRC      = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ      = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

debug: ASFLAGS := $(ASFLAGS) -g
debug: all

test: $(NAME)
	make -C test

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
