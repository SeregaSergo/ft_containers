NAME_MY =	test_my
NAME_DBG =	test_my_dbg
NAME_STD =	test_std
PATH =		./tests
SRC =		main.cpp
OBJ_MY =	$(PATH)/main_my.o
OBJ_MY_DBG =$(PATH)/main_my_debug.o
OBJ_STD =	$(PATH)/main_std.o
SRCS =		vector_test.cpp
OBJS =		$(PATH)/vector_test.o
OBJS_STD =	$(PATH)/vector_test_std.o
CC =		clang++
CFLAGS =	-fsanitize=address -Wall -Wextra -Werror
OUTF =		$(PATH)/output_my.txt \
			$(PATH)/output_std.txt
DEPS =		$(PATH)/test.hpp \
			vector.hpp \
			utils.hpp \
			reverse_iterator.hpp

.PHONY: all clean fclean re

all: $(NAME_MY) $(NAME_STD)

$(NAME_MY): $(OBJ_MY) $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_MY) $(OBJS) -o $(NAME_MY)

$(NAME_STD): $(OBJ_STD) $(OBJS_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) $(OBJS_STD) -D STD_TEST_MY -o $(NAME_STD)

$(OBJ_MY): $(PATH)/$(SRC) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_STD): $(PATH)/$(SRC)
	$(CC) $(CFLAGS) -D STD_TEST_MY -c -o $@ $<

$(OBJS): $(PATH)/$(SRCS) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_STD): $(PATH)/$(SRCS)
	$(CC) $(CFLAGS) -D STD_TEST_MY -c -o $@ $<

# $(OBJ_CLS): $(PATH)/$(CLS) $(PATH)/Logger.hpp
# 	$(CC) $(CFLAGS) -c -o $@ $<

debug: $(NAME_DBG)

$(NAME_DBG): $(OBJ_MY_DBG) $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_MY_DBG) $(OBJS) -o $(NAME_DBG)

$(OBJ_MY_DBG): $(PATH)/$(SRC)
	$(CC) $(CFLAGS) -D DEBUG_TERM -c -o $@ $<

clean:
	/bin/rm -f $(OBJ_MY) $(OBJ_STD) $(OUTF) $(OBJ_MY_DBG) $(OBJS_STD) $(OBJS)

fclean: clean
	/bin/rm -f $(NAME_MY) $(NAME_STD) $(NAME_DBG)

re: fclean all
