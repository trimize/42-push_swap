NAME = libft.a
SOURCES = $(wildcard $(shell find . -name "*.c"))	
OBJECTS = $(SOURCES:.c=.o)
OBJ_PATH = ../objs

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "\n\n\033[0m█▄─▄███▄─▄█▄─▄─▀█▄─▄▄─█─▄─▄─███─▄▄▄─█─▄▄─█▄─▀█▀─▄█▄─▄▄─█▄─▄█▄─▄███▄─▄▄─█▄─▄▄▀█"
	@echo "██─██▀██─███─▄─▀██─▄█████─█████─███▀█─██─██─█▄█─███─▄▄▄██─███─██▀██─▄█▀██─██─█"
	@echo "▀▄▄▄▄▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▀▀▄▄▄▀▀▀▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▄▄▄▀▄▄▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▀\n\n"
	@echo "\033[0m⭐ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━⭐\n\n"

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?
	@mkdir -p $(OBJ_PATH)
	@mv $(OBJECTS) $(OBJ_PATH)

bonus: $(OBJECTS)
	$(AR) -r $(NAME) $?
	@echo "\n\n\033[0m█▄─▄███▄─▄█▄─▄─▀█▄─▄▄─█─▄─▄─███─▄▄▄─█─▄▄─█▄─▀█▀─▄█▄─▄▄─█▄─▄█▄─▄███▄─▄▄─█▄─▄▄▀█"
	@echo "██─██▀██─███─▄─▀██─▄█████─█████─███▀█─██─██─█▄█─███─▄▄▄██─███─██▀██─▄█▀██─██─█"
	@echo "▀▄▄▄▄▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▀▀▄▄▄▀▀▀▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▄▄▄▀▄▄▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▀\n\n"
	@echo "\033[0m⭐ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━⭐\n\n"

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re so