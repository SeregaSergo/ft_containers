NAME_MY =	test_my
NAME_STD =	test_std
PATH =		./tests
SRC =		main.cpp
CLS =		Logger.cpp
OBJ_CLS =	$(PATH)/Logger.o
OBJ_MY =	$(PATH)/main_my.o
OBJ_STD =	$(PATH)/main_std.o
CC =		clang++
CFLAGS =	-Wall -Wextra -Werror
OUTF =		$(PATH)/output_my.txt \
			$(PATH)/output_std.txt
DEPS =		$(PATH)/utils.hpp \
			vector.hpp \
			traits.hpp \
			reverse_iterator.hpp

.PHONY: all clean fclean re

all: $(NAME_MY) $(NAME_STD)

$(NAME_MY): $(OBJ_MY) $(OBJ_CLS)
	$(CC) $(CFLAGS) $(OBJ_MY) $(OBJ_CLS) -o $(NAME_MY)

$(NAME_STD): $(OBJ_STD) $(OBJ_CLS)
	$(CC) $(CFLAGS) $(OBJ_STD) $(OBJ_CLS) -o $(NAME_STD)

$(OBJ_MY): $(PATH)/$(SRC) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_STD): $(PATH)/$(SRC)
	$(CC) $(CFLAGS) -D STD_TEST_MY -c -o $@ $<

$(OBJ_CLS): $(PATH)/$(CLS) $(PATH)/Logger.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ_MY) $(OBJ_STD) $(OUTF)

fclean: clean
	/bin/rm -f $(NAME_MY) $(NAME_STD)

re: fclean all
