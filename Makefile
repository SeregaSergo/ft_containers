NAME =			test

PATH_T =		./tests
PATH_P =		./tests/program
PATH_C =		./containers
PATH_O =		./tests/object_files
PATH_U =		./containers/utils
PATH_R =		./results

NAME_MY =		$(addprefix $(PATH_P)/,$(NAME:%=%_my))
NAME_STD =		$(addprefix $(PATH_P)/,$(NAME:%=%_std))
NAME_MY_DBG =	$(NAME:%=%_my_dbg)
NAME_STD_DBG =	$(NAME:%=%_std_dbg)

SRC =			main.cpp
OBJ_MY =		$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_my.o))
OBJ_STD =		$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_std.o))
OBJ_MY_DBG =	$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_my_dbg.o))
OBJ_STD_DBG =	$(addprefix $(PATH_O)/,$(SRC:%.cpp=%_std_dbg.o))

SRCS =			vector_test.cpp \
				map_test.cpp \
				stack_test.cpp \
				set_test.cpp
OBJS_MY =		$(addprefix $(PATH_O)/,$(SRCS:%.cpp=%_my.o))
OBJS_STD =		$(addprefix $(PATH_O)/,$(SRCS:%.cpp=%_std.o))

CC =			clang++
CFLAGS =		-Wall -Wextra -Werror -std=c++98
OUTF =			$(addprefix $(PATH_R)/, *.txt)

DEPS =			$(OBJ_MY:.o=.d) \
				$(OBJ_STD:.o=.d) \
				$(OBJ_MY_DBG:.o=.d) \
				$(OBJ_STD_DBG:.o=.d) \
				$(OBJS_MY:.o=.d) \
				$(OBJS_STD:.o=.d)

.PHONY: all clean fclean re debug

all: $(NAME_MY) $(NAME_STD)

$(NAME_MY): $(OBJS_MY) $(OBJ_MY)
	$(CC) $(CFLAGS) $(OBJ_MY) $(OBJS_MY) -o $(NAME_MY)

$(NAME_STD): $(OBJS_STD) $(OBJ_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) $(OBJS_STD) -D STD_TEST -o $(NAME_STD)

$(addprefix $(PATH_O)/, %_my.o): $(addprefix $(PATH_T)/, %.cpp)
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

$(addprefix $(PATH_O)/, %_std.o): $(addprefix $(PATH_T)/, %.cpp)
	$(CC) $(CFLAGS) -MMD -D STD_TEST -c -o $@ $<

debug: $(NAME_STD_DBG) $(NAME_MY_DBG)

$(NAME_MY_DBG): $(OBJ_MY_DBG) $(OBJS_MY)
	$(CC) $(CFLAGS) $(OBJ_MY_DBG) $(OBJS_MY) -o $(NAME_MY_DBG)

$(NAME_STD_DBG): $(OBJ_STD_DBG) $(OBJS_STD)
	$(CC) $(CFLAGS) $(OBJ_STD_DBG) $(OBJS_STD) -o $(NAME_STD_DBG)

$(addprefix $(PATH_O)/, %_my_dbg.o): $(addprefix $(PATH_T)/, %.cpp)
	$(CC) $(CFLAGS) -D DEBUG_TERM -c -o $@ $<

$(addprefix $(PATH_O)/, %_std_dbg.o): $(addprefix $(PATH_T)/, %.cpp)
	$(CC) $(CFLAGS) -D DEBUG_TERM -D STD_TEST -c -o $@ $<

-include $(DEPS)

clean:
	/bin/rm -f $(OBJ_MY) $(OBJ_STD) $(OUTF) $(OBJ_MY_DBG) $(OBJ_STD_DBG) $(OBJS_STD) $(OBJS_MY) $(DEPS)

fclean: clean
	/bin/rm -f $(NAME_MY) $(NAME_STD) $(NAME_STD_DBG) $(NAME_MY_DBG)

re: fclean all
