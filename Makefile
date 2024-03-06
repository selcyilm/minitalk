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
###-RM UTIL-#####################################
RM = rm -rf
###-COLOURS-#####################################
COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
###-RULES-########################################
all: $(NCLIENT) $(NSERVER)

$(NSERVER): $(OSERVER)
	@$(CC) $(CFLAGS) $(SERVER) src/utils.c -o $(NSERVER)
	@echo "$(COLOUR_GREEN)SERVER IS READY$(COLOUR_END)"

$(NCLIENT): $(OCLIENT)
	@$(CC) $(CFLAGS) $(CLIENT) src/utils.c -o $(NCLIENT)
	@echo "$(COLOUR_GREEN)CLIENT IS READY$(COLOUR_END)"

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OCLIENT) $(OSERVER)
	@echo "$(COLOUR_BLUE)CLEANING OBJECT FILES...$(COLOUR_END)"
	@echo "REMOVED .O FILES"

fclean: clean
	@$(RM) $(NCLIENT) $(NSERVER) 
	@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE...$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
###-END-#########################################
