NAME_MY =		test_my
NAME_STD =		test_std
NAME_MY_DBG =	test_my_dbg
NAME_STD_DBG =	test_std_dbg

PATH_T =		./tests
PATH_C =		./containers
PATH_O =		./tests/object_files
PATH_U =		./containers/utils

SRC =			main.cpp
OBJ_MY =		$(addprefix $(PATH_T)/,$(SRC:%.cpp=%_my.o))
OBJ_STD =		$(addprefix $(PATH_T)/,$(SRC:%.cpp=%_std.o))
OBJ_MY_DBG =	$(addprefix $(PATH_T)/,$(SRC:%.cpp=%_my_dbg.o))
OBJ_STD_DBG =	$(addprefix $(PATH_T)/,$(SRC:%.cpp=%_std_dbg.o))

SRCS =			vector_test.cpp \
				map_test.cpp
OBJS_MY =		$(addprefix $(PATH_T)/,$(SRCS:%.cpp=%_my.o))
OBJS_STD =		$(addprefix $(PATH_T)/,$(SRCS:%.cpp=%_std.o))

CC =			clang++
CFLAGS =		-Wall -Wextra -Werror
OUTF =			output_my.txt \
				output_std.txt
DEPS =			$(PATH_T)/test.hpp \
				$(PATH_C)/vector.hpp \
				$(PATH_C)/map.hpp \
				$(PATH_C)/tree.hpp \
				$(PATH_U)/utils.hpp \
				$(PATH_U)/reverse_iterator.hpp

.PHONY: all clean fclean re debug

all: $(NAME_MY) $(NAME_STD)

$(NAME_MY): $(OBJS_MY) $(OBJ_MY)
	$(CC) $(CFLAGS) $(OBJ_MY) $(OBJS_MY) -o $(NAME_MY)

$(NAME_STD): $(OBJS_STD) $(OBJ_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) $(OBJS_STD) -D STD_TEST -o $(NAME_STD)

%_my.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

%_std.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -D STD_TEST -c -o $@ $<

debug: $(NAME_DBG_STD) $(NAME_DBG_MY)

$(NAME_DBG_STD): $(OBJ_DBG_STD) $(OBJS_STD)
	$(CC) $(CFLAGS) $(OBJ_DBG_STD) $(OBJS_STD) -o $(NAME_DBG_STD)

$(OBJ_DBG_STD): $(PATH_T)/$(SRC)
	$(CC) $(CFLAGS) -D DEBUG_TERM -D STD_TEST -c -o $@ $<

$(NAME_DBG_MY): $(OBJ_DBG_MY) $(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DBG_MY) $(OBJS) -o $(NAME_DBG_MY)

$(OBJ_DBG_MY): $(PATH_T)/$(SRC)
	$(CC) $(CFLAGS) -D DEBUG_TERM -c -o $@ $<

clean:
	/bin/rm -f $(OBJ_MY) $(OBJ_STD) $(OUTF) $(OBJ_MY_DBG) $(OBJ_STD_DBG) $(OBJS_STD) $(OBJS_MY)

fclean: clean
	/bin/rm -f $(NAME_MY) $(NAME_STD) $(NAME_DBG_STD) $(NAME_DBG_MY)

re: fclean all
