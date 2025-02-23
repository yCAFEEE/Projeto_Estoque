CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
TARGET = main

.SILENT:
$(TARGET): $(OBJ)
	@echo Compilando os arquivos para $(TARGET)
	$(CC) -Wall $^ -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) -Wall -Iheader -c $< -o $@

.PHONY: clean
clean:
	@echo Removendo os arquivos
	rm -f $(TARGET) obj/*.o
	rm -rf obj