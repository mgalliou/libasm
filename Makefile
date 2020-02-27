NAME     = libasm.a
RM       = rm -rf
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
AS       = nasm
ASFLAGS  = -f macho64 -i$(INC_DIR)
ARFLAGS  = rc
RL       = ranlib
LDFLAGS  = -L.
LDLIBS   = -lasm
INC_DIR  = src
INC_NAME = t_list.s
SRC_DIR  = src
SRC_NAME = ft_strlen.s\
			ft_strcpy.s\
			ft_strcmp.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s\
			ft_strchr.s\
			ft_atoi_base.s\
			ft_isspace.s\
			ft_create_elem.s\
			ft_list_push_front.s\
			ft_list_size.s\
			ft_list_sort.s\
			ft_list_remove_if.s
OBJ_NAME = $(SRC_NAME:.s=.o)
OBJ_DIR  = obj
INC      = $(addprefix $(INC_DIR)/,$(INC_NAME))
SRC      = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ      = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s $(INC)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

debug: ASFLAGS := $(ASFLAGS) -g
debug: all

check: all
	make -C test
	./test/test

test_main: $(NAME)
	$(CC) main.c $(NAME) -o test_main

test_bonus: $(NAME)
	$(CC) main_bonus.c $(NAME) -o test_bonus

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) test_main test_bonus

re: fclean all

.PHONY: all check test_main test_bonus clean fclean re
