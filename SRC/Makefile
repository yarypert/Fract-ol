NAME = Fractol

COMPILL = -L/home/sholyu/Bureau/42/Fractol/minilibx -lm -lmlx -lXext -lX11

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = main.c draw.c dispatch.c hook.c hook2.c menu.c menu2.c mandelbrot.c julia.c rorschach.c rose.c colors.c

OBJ = main.o draw.o dispatch.o hook.o hook2.o menu.o menu2.o mandelbrot.o julia.o rorschach.o rose.o colors.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "\033[38;5;14m===Fractol : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

linux:
	@echo "\033[38;5;28m===Fractol : Compilation for Linux...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@gcc $(OBJ) $(COMPILL) $(LIB) $(INCLUDES) -o $(NAME)
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

relinux: fclean linux

re: fclean all
