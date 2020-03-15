##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

CFLAGS	+=	-Iinclude -Wall -Wextra -Werror

SRC	=	source/main.c				\
		source/init.c				\
		source/packet.c				\
		source/transfer.c			\
		source/parameters.c			\
		source/print_spoof.c		\
		source/arp_spoofing.c		\
		source/print_broadcast.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myARPspoof

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o  $(NAME) $(OBJ)
		make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re
