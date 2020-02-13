NAME		=	test
PROJECT		=	libasm.a
INC_DIR		=	libftest/include
SRC_DIR		=	src
OBJ_DIR		=	obj
LIB_DIR		=	libftest
RM			= 	rm -rf
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_DEBUG =	-g -fsanitize=address
CPPFLAGS	=	$(foreach dir,$(INC_DIR),-I$(dir))
LDFLAGS		=	$(foreach dir,$(LIB_DIR),-L$(dir)) -L..
LDLIBS		=	-lftest -lasm
RM			= 	rm -rf
SRC_NAME	=	main.c\
				suite_ft_strlen.c\
				suite_ft_strcpy.c\
				suite_ft_strdup.c\
				suite_ft_strchr.c\
				suite_ft_atoi_base.c\
				suite_ft_isspace.c\
				suite_ft_create_elem.c\
				suite_ft_list_push_front.c
SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
LIB_NAME    =   libftest.a
LIB			=	$(addprefix $(LIB_DIR)/,$(LIB_NAME))

all : $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB) ../$(PROJECT)
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(PROJECT):
	make -C ../

$(LIB):
	make -C $(LIB_DIR) CFLAGS="$(CFLAGS)"

debug: CFLAGS := $(CFLAGS) $(CFLAGS_DEBUG)
debug: all

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
