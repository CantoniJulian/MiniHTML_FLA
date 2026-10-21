# Configuración del compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

# Nombres y rutas
SRC = src/stack.cpp
BUILD_DIR = bin
TARGET = $(BUILD_DIR)/stack

# Regla por defecto
all: $(TARGET)

# Crea la carpeta 'bin' si no existe y compila dentro de ella
$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Limpia el ejecutable y la carpeta de compilación
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
