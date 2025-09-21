NAME = fractol
BONUS_NAME = fractol_bonus
FRACTOL_LIB = fractol.a
FRACTOL_BONUS_LIB = fractol_bonus.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
MAKE = make -sC

LIBFT_D = ./libft
LIBFT = $(LIBFT_D)/libft.a
LIBFT_LIB = libft.a
MLX_D = ./MLX42/build/
MLX = $(MLX_D)/libmlx42.a
MLX_LIB = libmlx42.a

SRC_BONUS = src_bonus/fractol_bonus.c \
	src_bonus/parse_bonus.c \
	src_bonus/utils_1_bonus.c \
	src_bonus/maths_1_bonus.c \
	src_bonus/maths_2_bonus.c \
	src_bonus/colors_bonus.c \
	src_bonus/mandelbrot_bonus.c \
	src_bonus/julia_bonus.c \
	src_bonus/flower_bonus.c \
	src_bonus/butterfly_bonus.c \
	src_bonus/hooks_bonus.c \

SRC = src/fractol.c \
	src/parse.c \
	src/utils_1.c \
	src/maths_1.c \
	src/maths_2.c \
	src/colors.c \
	src/mandelbrot.c \
	src/julia.c \
	src/hooks.c \

OBJ = $(SRC:src/%.c=obj/%.o)

BONUS_OBJ = $(SRC_BONUS:src_bonus/%.c=obj_bonus/%.o)

all: $(FRACTOL_LIB) $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -g $(SRC) $(FRACTOL_LIB) $(LIBFT) $(MLX) -Iinclude -lglfw -lm -o $(NAME)
	@echo "\e[1;32m[✓] Successful fractol compilation\e[0m"

$(BONUS_NAME): $(FRACTOL_BONUS_LIB)
	@$(CC) $(CFLAGS) -g $(FRACTOL_BONUS_LIB) $(LIBFT) $(MLX) -Iinclude -lglfw -lm -o $(BONUS_NAME)
	@echo "\e[1;32m[✓] Successful fractol_bonus compilation\e[0m"

bonus: $(BONUS_NAME)

obj_bonus/%.o: src_bonus/%.c
	@mkdir -p obj_bonus
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "\e[32m$@ created!\e[0m"
	@echo "\e[1;32m[✓] Objects creation \e[0m"

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "\e[32m$@ created!\e[0m"
	@echo "\e[1;32m[✓] Objects creation \e[0m"

$(FRACTOL_BONUS_LIB): $(BONUS_OBJ) $(LIBFT) $(MLX)
	@$(AR) $(FRACTOL_BONUS_LIB) $(BONUS_OBJ)
	@echo "\e[1;32m$(FRACTOL_BONUS_LIB) created...\e[0m"
	@echo "\e[1;32m[✓] all librarys created \e[0m"

$(FRACTOL_LIB): $(OBJ) $(LIBFT) $(MLX)
	@$(AR) $(FRACTOL_LIB) $(OBJ)
	@echo "\e[1;32m$(FRACTOL_LIB) created...\e[0m"
	@echo "\e[1;32m[✓] all librarys created \e[0m"

$(LIBFT):
	@$(MAKE) $(LIBFT_D)
	@echo "\e[1;32mlibft.a created...\e[0m"

removep:
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "\e[1;31m[x] program deleted \e[0m"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@$(RM) -rf obj
	@$(RM) -rf obj_bonus
	@make clean -sC $(LIBFT_D)
	@echo "\e[1;31m[x] Objects deleted \e[0m"

fclean: clean
	@$(RM) $(FRACTOL_LIB)
	@$(RM) $(FRACTOL_BONUS_LIB)
	@make fclean -sC $(LIBFT_D)
	@echo "\e[1;31m[x] Library deleted \e[0m"

re: fclean all

.PHONY: all clean fclean re