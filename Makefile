NAME        := libasm.a
NASM        := nasm
NASM_FLAGS  := -f elf64 -g -F dwarf
AR          := ar
AR_FLAGS    := rcs
MKDIR       := mkdir -p
RM          := rm -f

SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := includes

SRCS        := $(wildcard $(SRC_DIR)/*.s)
OBJS        := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRCS))

$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@$(MKDIR) $(OBJ_DIR)
	$(NASM) $(NASM_FLAGS) $< -o $@

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) test

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	gcc -no-pie main.c -I$(INC_DIR) -L. -lasm -o test

debug:
	gdb -q obj/ft_putchar.o

.PHONY: all clean fclean re test