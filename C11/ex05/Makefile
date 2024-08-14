TARGET	= ./do-op
CC	= gcc
CFLAGS	+= -Wall -Wextra -Werror

SRC_DIR	= ./src
INC_DIR	= ./include
BUILD_DIR	= ./build

SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJS	= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
