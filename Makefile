CLIENT = src/client.c
SERVER = src/server.c

OCLIENT = $(CLIENT:.c=.o)
OSERVER = $(SERVER:.c=.o)

NCLIENT = client
NSERVER = server

CFLAGS = -Wall -Werror -Wextra

HEADERS = minitalk.h

RM = rm -rf

all: $(NCLIENT) $(NSERVER)

$(NSERVER): $(OSERVER)
	@gcc $(CFLAGS) $(SERVER) -o $(NSERVER)
	@echo "SERVER IS READY"

$(NCLIENT): $(OCLIENT)
	@gcc $(CFLAGS) $(CLIENT) -o $(NCLIENT)
	@echo "CLIENT IS READY"

%.o:%.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OCLIENT) $(OSERVER)
	@echo "CLEANING OBJECT FILES..."

fclean: clean
	@$(RM) $(NCLIENT) $(NSERVER)
	@echo "CLEANING EXECUTABLE..."

re: fclean all

.PHONY: all clean fclean re
