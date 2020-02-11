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
SRC_NAME = ft_strlen.s\
		   ft_strcpy.s\
		   ft_strcmp.s\
		   ft_write.s\
		   ft_read.s\
		   ft_strdup.s\
		   ft_strchr.s\
		   ft_atoi_base.s
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

test: all
	make -C test

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
