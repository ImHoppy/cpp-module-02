NAME		=	Fixed_ex02

CC			=	c++

CFLAGS		=	-Werror -Wall -Wextra -g3 -std=c++98 -I.
ifeq ($(DEBUG), 1)
	CFLAGS		+= -DDEBUG=1
endif

SRCS		=	main.cpp Fixed.cpp

OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(OBJS:.o=.d)

%.o : %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS) $(DEPS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean
				$(MAKE)

debug		:	fclean
				$(MAKE) DEBUG=1

-include $(DEPS)

.PHONY: all clean fclean re -include
