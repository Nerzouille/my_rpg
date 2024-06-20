##
## EPITECH PROJECT, 2024
## B-MUL-200-LYN-2-1-myrpg-charly.palliere
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

HEADER_FILE	=	my.h

EXEC	=	libmy.a

CFLAGS	+=	-g3

all: $(EXEC)

$(EXEC):	$(OBJ)
	ar rc $(EXEC) $(OBJ)
	make cp_files

cp_files:	${EXEC}	${HEADER_FILE}
	cp $(EXEC) ../../
	cp $(HEADER_FILE) ../../include/

clean:
	rm -f *.o *.gch

fclean:	clean
	rm -f ../../$(EXEC) ../../include/$(HEADER_FILE) $(EXEC)

re: fclean all

.PHONY:	all	cp_files	clean	fclean	re
