NAME = Fractol

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = main.c draw.c hook.c menu.c mandelbrot.c julia.c

OBJ = main.o draw.o hook.o menu.o mandelbrot.o julia.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "\033[38;5;14m===FDF : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

.PHONY: clean
clean:
	@make clean -C Libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C Libft
	@rm -rf TMP
	@rm -rf $(NAME)

re: fclean all
