NAME = push_swap
BONUS = checker
LIBFT_PATH = ./libft/
INCDIR = ./includes/
SRCSDIR = ./srcs/
OBJDIR = ./objs/
BOBJDIR = ./bobjs/
BONUSDIR = ./bonus/
LIBFT = $(LIBFT_PATH)libft.a

SOURCES = $(wildcard $(SRCSDIR)*.c)
BSOURCES = $(wildcard $(BONUSDIR)*.c)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
BOBJECTS = $(addprefix $(BOBJDIR), $(notdir $(BSOURCES:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR)

all: $(NAME)

bonus: all $(BONUS)

$(NAME): $(LIBFT) $(OBJECTS)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_PATH) -lft
	@echo "$@ has been successfully built!"

$(BONUS): $(LIBFT) $(BOBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(BOBJECTS) -L$(LIBFT_PATH) -lft
	@echo "Bonuses have been successfully built!"

$(LIBFT):
	@echo "Building $(LIBFT) library"
	@make -C $(LIBFT_PATH) >/dev/null 2>&1

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR)%.o: $(BONUSDIR)%.c | $(BOBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR):
	@mkdir -p $(BOBJDIR)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJDIR)
	@rm -rf $(BOBJDIR)
	@make -C $(LIBFT_PATH) clean >/dev/null 2>&1

fclean: clean
	@echo "Cleaning $(NAME)"
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make -C $(LIBFT_PATH) fclean >/dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus
