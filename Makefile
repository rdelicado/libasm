# Variables de directorio y herramientas
SRC_DIR    := src
TEST_DIR   := unitest
OBJ_DIR    := obj
INC_DIR    := includes
NAME       := libasm.a
NASM       := nasm
NASM_FLAGS := -f elf64 -g -F dwarf
MKDIR      := mkdir -p
AR         := ar
AR_FLAGS   := rcs
RM         := rm -f

# Archivos de fuente
SRCS      := $(wildcard $(SRC_DIR)/*.s)
OBJS      := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRCS))
UTIL_SRCS := $(wildcard $(TEST_DIR)/*_utils.c)
UTIL_OBJS := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(UTIL_SRCS))
TEST_SRCS := $(filter-out $(UTIL_SRCS), $(wildcard $(TEST_DIR)/*.c))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
MAIN_SRCS := $(wildcard *.c)
MAIN_OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))

# Compilación de la librería (ensamblador)
$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $@ $^

# Reglas de compilación
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@$(MKDIR) $(OBJ_DIR)
	$(NASM) $(NASM_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	gcc -c $< -I$(INC_DIR) -I$(TEST_DIR) -o $@

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(OBJ_DIR)
	gcc -c $< -I$(INC_DIR) -o $@

all: $(NAME)

test: $(NAME) $(MAIN_OBJS) $(TEST_OBJS) $(UTIL_OBJS)
	gcc -no-pie $(MAIN_OBJS) $(TEST_OBJS) $(UTIL_OBJS) -L. -lasm -I$(INC_DIR) -I$(TEST_DIR) -o test

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) test

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test