###-SOURCE CODE-#################################
CLIENT = src/client.c
CLIENTB = src/client_bonus.c
SERVER = src/server.c
SERVERB = src/server_bonus.c
###-OBJECT FILES-################################
OCLIENT = $(CLIENT:.c=.o)
OCLIENTB = $(CLIENTB:.c=.o)
OSERVER = $(SERVER:.c=.o)
OSERVERB = $(SERVERB:.c=.o)
###-EXECUTABLE NAMES-############################
NCLIENT = client
NCLIENTB = client_bonus
NSERVER = server
NSERVERB = server_bonus
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

$(NSERVERB): $(LIBFT) $(OSERVERB)
	@$(CC) $(CFLAGS) $(SERVERB) $(LIBFT) -o $(NSERVER)
	@echo "$(COLOUR_ORANGE)SERVER IS READY FOR BONUS..$(COLOUR_END)"

$(NCLIENTB): $(LIBFT) $(OCLIENTB)
	@$(CC) $(CFLAGS) $(CLIENTB) $(LIBFT) -o $(NCLIENT)
	@echo "$(COLOUR_ORANGE)CLIENT IS READY FOR BONUS..$(COLOUR_END)"

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NCLIENTB) $(NSERVERB)


clean:
	@make -C libft/ clean
	@$(RM) $(OCLIENT) $(OSERVER) $(OCLIENTB) $(OSERVERB)
	@echo "$(COLOUR_BLUE)CLEANING OBJECT FILES...$(COLOUR_END)"

fclean: clean
	@make -C libft/ fclean
	@$(RM) $(NCLIENT) $(NSERVER) $(NCLIENTB) $(NSERVERB)
	@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE...$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
###-END-#########################################