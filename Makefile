###-SOURCE CODE-#################################
CLIENT = src/client.c
SERVER = src/server.c
###-OBJECT FILES-################################
OCLIENT = $(CLIENT:.c=.o)
OSERVER = $(SERVER:.c=.o)
###-EXECUTABLE NAMES-############################
NCLIENT = client
NSERVER = server
###-FLAGS AND HEADERS-###########################
CFLAGS = -Wall -Werror -Wextra
CC = cc
HEADERS = minitalk.h
LIBFT = libft/libft.a
###-RM UTIL-#####################################
RM = rm -rf
###-COLOURS-#####################################
COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
COLOUR_ORANGE=\033[38;5;214m
###-RULES-########################################
all: $(LIBFT) $(NCLIENT) $(NSERVER)

$(NSERVER): $(LIBFT) $(OSERVER)
	@$(CC) $(CFLAGS) $(SERVER) $(LIBFT) -o $(NSERVER)
	@echo "$(COLOUR_ORANGE)SERVER IS READY$(COLOUR_END)"

$(NCLIENT): $(LIBFT) $(OCLIENT)
	@$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) -o $(NCLIENT)
	@echo "$(COLOUR_ORANGE)CLIENT IS READY$(COLOUR_END)"

$(LIBFT):
	@make -C libft/ all

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C libft/ clean
	@$(RM) $(OCLIENT) $(OSERVER)
	@echo "$(COLOUR_BLUE)CLEANING OBJECT FILES...$(COLOUR_END)"

fclean: clean
	@make -s -C libft/ fclean
	@$(RM) $(NCLIENT) $(NSERVER)
	@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE...$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
###-END-#########################################