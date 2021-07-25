NAME =			test

PATH_T =		./tests
PATH_P =		./tests/program
PATH_C =		./containers
PATH_O =		./tests/object_files
PATH_U =		./containers/utils
PATH_R =		./results

NAME_MY =		$(addprefix $(PATH_P)/,$(NAME:%=%_my))
NAME_STD =		$(addprefix $(PATH_P)/,$(NAME:%=%_std))
NAME_MY_DBG =	$(addprefix $(PATH_P)/,$(NAME:%=%_my_dbg))
NAME_STD_DBG =	$(addprefix $(PATH_P)/,$(NAME:%=%_std_dbg))

SRC =			main.cpp
OBJ_MY =		$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_my.o))
OBJ_STD =		$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_std.o))
OBJ_MY_DBG =	$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_my_dbg.o))
OBJ_STD_DBG =	$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_std_dbg.o))

SRCS =			vector_test.cpp \
				map_test.cpp
OBJS_MY =		$(addprefix $(PATH_O)/,$(SRCS:%.cpp=%_my.o))
OBJS_STD =		$(addprefix $(PATH_O)/,$(SRCS:%.cpp=%_std.o))

CC =			clang++
CFLAGS =		-Wall -Wextra -Werror
OUTF =			$(addprefix $(PATH_R)/, output_my.txt) \
				$(addprefix $(PATH_R)/, output_std.txt)
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

$(addprefix $(PATH_O)/, %_my.o): $(addprefix $(PATH_T)/, %.cpp) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(addprefix $(PATH_O)/, %_std.o): $(addprefix $(PATH_T)/, %.cpp) $(DEPS)
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
