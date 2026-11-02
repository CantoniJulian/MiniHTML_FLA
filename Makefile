# Configuración del compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2 -fpermissive

# Nombres y rutas
SRC = src/stack.h
BUILD_DIR = bin
TARGET = $(BUILD_DIR)/stack

# Regla por defecto
all: $(TARGET)

# Crea la carpeta 'bin' si no existe y compila dentro de ella
$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) src/automata.cpp src/stack.h -o bin/automatest	

# Limpia el ejecutable y la carpeta de compilación
clean:
	rm bin/automatest

.PHONY: all clean
