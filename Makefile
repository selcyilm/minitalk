CLIENT = client.c
SERVER = server.c

OCLIENT = $(CLIENT:.c=.o)
OSERVER = $(SERVER:.c=.o)

NCLIENT = client
NSERVER = server

CFLAGS = -Wall -Werror -Wextra

HEADERS = minitalk.h

RM = rm -rf

all: $(NCLIENT) $(NSERVER)

$(NSERVER): $(OSERVER)
	gcc $(CFLAGS) $(SERVER) -o $(NSERVER)

$(NCLIENT): $(OCLIENT)
	gcc $(CFLAGS) $(CLIENT) -o $(NCLIENT)

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OCLIENT) $(OSERVER)

fclean: clean
	$(RM) $(NCLIENT) $(NSERVER)

re: fclean all

.PHONY: all clean fclean re
