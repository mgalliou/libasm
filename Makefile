NAME     = libasm.a
RM       = rm -rf
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
AS       = nasm
ASFLAGS  = -f macho64 -i$(INC_DIR)
ARFLAGS  = rcs
LDFLAGS  = -L.
LDLIBS   = -lasm
INC_DIR  = src
INC_NAME = t_list_bonus.s
SRC_DIR  = src
SRC      = ft_strlen.s\
			ft_strcpy.s\
			ft_strcmp.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s
SRC_BONUS = ft_strchr_bonus.s\
			ft_atoi_base_bonus.s\
			ft_isspace_bonus.s\
			ft_create_elem_bonus.s\
			ft_list_push_front_bonus.s\
			ft_list_size_bonus.s\
			ft_list_sort_bonus.s\
			ft_list_remove_if_bonus.s
OBJ_DIR   = obj
OBJ       = $(SRC:.s=.o)
OBJ_BONUS = $(SRC_BONUS:.s=.o)
INC       = $(addprefix $(INC_DIR)/,$(INC_NAME))
OBJ       := $(addprefix $(OBJ_DIR)/,$(OBJ))
OBJ_BONUS := $(addprefix $(OBJ_DIR)/,$(OBJ_BONUS))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INC)
	$(AS) $(ASFLAGS) $< -o $@

test: all
	make -C test

debug: ASFLAGS += -g
debug: all

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
