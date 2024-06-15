##
## EPITECH PROJECT, 2024
## B-OOP-400-LYN-4-1-arcade-camille.erades
## File description:
## Makefile
##

CC = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -I ./include -fPIC
CXXFLAGS += -lsfml-window -lsfml-system -lsfml-graphics -lm -lconfig++

SRC_DIR = ./src
SRC = $(SRC_DIR)/main.cpp \
    $(SRC_DIR)/Camera.cpp \
    $(SRC_DIR)/Ray.cpp \
    $(SRC_DIR)/primitives/Rectangle3D.cpp \
    $(SRC_DIR)/primitives/Sphere.cpp \
    $(SRC_DIR)/primitives/Plane.cpp \
    $(SRC_DIR)/Vector3D.cpp \
    $(SRC_DIR)/Scene.cpp \
    $(SRC_DIR)/Draw.cpp \
    $(SRC_DIR)/primitives/Cone.cpp \
    $(SRC_DIR)/primitives/Cylindre.cpp \
    $(SRC_DIR)/Light.cpp

BUILDDIR = ./obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

EXEC = raytracer

$(BUILDDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ -MD -c $< $(CXXFLAGS) -g3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -rf $(EXEC)

re: fclean all

-include $(OBJ:%.o=%.d)

.PHONY: clean fclean re
