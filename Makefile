# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:23:32 by lluque            #+#    #+#              #
#    Updated: 2024/01/27 21:37:28 by lluque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories for source code, tester and headers (permanent), and for
# object files and binary output (volatile).
# (relative to repository root directory)
#
SRC_DIR = ./src/
INC_DIR = ./include/
TEST_DIR = ./test/
BIN_DIR = ./bin/
OBJ_DIR = ./obj/

# Resulting library name (to be placed in BIN_DIR)
NAME = libft.a

# Resulting bonus output name (to be placed in BIN_DIR)
#BONUS_NAME = ???

# Resulting tester name (to be placed in BIN_DIR)
TESTER_NAME = tester

# Archive command flags
AR_FLAGS = rcs

# Compiler flags
CC_FLAGS = -Wall -Werror -Wextra

# List of header file names that, if modified, should force recompiling
INCLUDES = $(INC_DIR)libft.h \
		   $(INC_DIR)ft_char.h \
		   $(INC_DIR)ft_debug.h \
		   $(INC_DIR)ft_file.h \
		   $(INC_DIR)ft_llst.h \
		   $(INC_DIR)ft_math.h  \
		   $(INC_DIR)ft_memory.h \
		   $(INC_DIR)ft_string.h

# List of source code file names with path relative to SRC_DIR
SOURCES = char/ft_isalpha.c \
		  char/ft_isdigit.c \
		  char/ft_isalnum.c \
		  char/ft_isascii.c \
		  char/ft_isprint.c \
		  char/ft_toupper.c \
		  char/ft_tolower.c \
		  char/ft_islower.c \
		  char/ft_isupper.c \
		  char/ft_issign.c \
		  char/ft_isspace.c \
		  memory/ft_memset.c \
		  memory/ft_bzero.c \
		  memory/ft_memcpy.c \
		  memory/ft_memmove.c \
		  memory/ft_memchr.c \
		  memory/ft_memcmp.c \
		  memory/ft_calloc.c \
		  string/ft_strlen.c \
		  string/ft_strlcpy.c \
		  string/ft_strlcat.c \
		  string/ft_strchr.c \
		  string/ft_strrchr.c \
		  string/ft_strncmp.c \
		  string/ft_strnstr.c \
		  string/ft_atoi.c \
		  string/ft_strdup.c \
		  string/ft_substr.c \
		  string/ft_strjoin.c \
		  string/ft_strtrim.c \
		  string/ft_split.c \
		  string/ft_itoa.c \
		  string/ft_strmapi.c \
		  string/ft_striteri.c \
		  string/ft_itoa_b.c \
		  string/ft_get_sym_table.c \
		  string/ft_ltoa.c \
		  string/ft_ltoa_b.c \
		  string/ft_ultoa_b.c \
		  string/ft_uitoa_b.c \
		  file/ft_putchar_fd.c \
		  file/ft_putstr_fd.c \
		  file/ft_putendl_fd.c \
		  file/ft_putnbr_fd.c \
		  file/ft_putchar_fd_safe.c \
		  file/ft_putstr_fd_safe.c \
		  llst/ft_lstnew.c \
		  llst/ft_lstadd_front.c \
		  llst/ft_lstsize.c \
		  llst/ft_lstlast.c \
		  llst/ft_lstadd_back.c \
		  llst/ft_lstdelone.c \
		  llst/ft_lstclear.c \
		  llst/ft_lstiter.c \
		  llst/ft_lstmap.c \
		  math/ft_pow.c \
		  debug/ft_print_memory.c

# Auto generated list of object file names from SOURCES
# (here the path is relative to repository's root)
#
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)%.o)

# List of tester source code file names with path relative to TEST_DIR
TEST_SRC = tester.c

################################################################################
############### VARIABLES FOR DOXYGEN DOCUMENTATION GENERATION #################

# Doxyfile name, to be generated and edited in repository root directory
DOXYFILE = Doxyfile
DOC_DIR = ./doc/

# Project name for documentation purposes
DOX_PROJECT_NAME = Library libft

# Project brief description (one line)
DOX_PROJECT_BRIEF = Cummulative util library for Campus 42

# Version of the documentation (date for now)
DOX_PROJECT_NUMBER = $(shell date +%Y-%m-%d)

# Location with files to extract documentation from (.h)
# Look for more files in subdirectories
#
DOX_INPUT = $(INC_DIR) $(DOX_MAIN_PAGE)
DOX_RECURSIVE = YES

# Content for documentation main page
DOX_MAIN_PAGE = ./README.md

# Optimization for languages
DOX_OPTIMIZE_OUTPUT_FOR_C = YES

# Documentation formats to generate
DOX_GENERATE_HTML = YES
DOX_GENERATE_LATEX = NO
DOX_GENERATE_RTF = NO
DOX_GENERATE_MAN = YES

################ VARIABLES FOR DOXYGEN DOCUMENTATION GENERATION ################
################################################################################

# Default rule
all: $(BIN_DIR)$(NAME)

# Rule to archive objects into library
$(BIN_DIR)$(NAME): $(OBJECTS)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "     --- Archiving objects into library $(BIN_DIR)$(NAME) ---"
	@echo
	mkdir -p $(BIN_DIR)
	ar $(AR_FLAGS) $(BIN_DIR)$(NAME) $(OBJECTS)
	@echo
	@echo ----------------------------------------------------------------------

################################################################################
################## START OF PATTERN RULE TO COMPILE OBJECTS ####################
# Pattern rule to individually compile each object:
#
# 	targets: target-pattern: requisite-pattern extra-req1 extra-req2...
# 	|			|				|				|
# 	|			|				|				|___ more requisites
# 	|			|				|
# 	|			|				|___ ./src/what_matches.c -> ./src/%.c 
#	|			|
# 	|			|________ ./obj/what_matches.o -> ./obj/%.o 
# 	|
# 	|______./obj/file1.o ./obj/file2.o ./obj/file3.o ./obj/file4.o...   
#
# From GNU make manual:
# 	"The target-pattern and prereq-patterns say how to compute the prerequisites
# 	of each target. Each target is matched against the target-pattern to extract
# 	a part of the target name, called the stem. This stem is substituted into
# 	each of the prereq-patterns to make the prerequisite names (one from each
# 	prereq-pattern)."
#
# (1) The wildcard '%' in target-pattern is determined for each target when
# matching the pattern. (2) On the requisite-pattern side, the '%' resolves to
# whatever was determined in the target-pattern side. Thus:
#
#	OBJ_DIR is included in target-pattern because of (1), so it is not included
#	as part of '%' when sustituted in requisite-pattern side.
#
#	SRC_DIR is included in requisite pattern in order to have the complete
#	path and name of each requisite when '%' gets substituted in the requisite-
#	pattern side.
#
# The automatic variables:
#	$^ replaced by the name of ALL prerequisites
#	$< replaced by the name of FIRST prerequisites
#	$@ replaced by the name of the target
#
#	Using $< instead of $^ allows to correctly introduce more prerequisites
#	in a pattern rule.
#
# The expression:
# 	$(dir $@) 	equivalent to	$(@D)
# Resolves to the directory part of the target, excluding the file name.
# For just the name file:
# 	$(notdir $@) 	equivalent to	$(@F)
#
# Notice the headers as extra pre-requisites to force a recompiling if
# modified.
#
$(OBJECTS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "              --- Compiling objects to $(OBJ_DIR)/*.o ---"
	mkdir -p $(@D)
	cc -c $< -o $@ -I$(INC_DIR)
	@echo
	@echo ----------------------------------------------------------------------
################### END OF PATTERN RULE TO COMPILE OBJECTS #####################
################################################################################

# Cleaning rule: deletes object files and directory.
# Possible additions to the recipe:
# 	rm -rf $(BONUS_OBJ_DIR)
# 	make clean --directory=$(SOME_LIBRARY_PATH)
#
clean:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- Cleaning ---"
	@echo
	rm -rf $(OBJ_DIR)
	@echo
	@echo ----------------------------------------------------------------------

# Full cleaning rule: deletes objects files, all binary outputs, and directories
# Possible additions to the recipe:
# 	make fclean --directory=$(SOME_ANOTHER_LIBRARY_PATH)
#
fclean:clean
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- Fcleaning ---"
	@echo
	rm -rf $(BIN_DIR)
	@echo
	@echo ----------------------------------------------------------------------

# Rebuild rule: deletes objects files and all outputs, then compiles again
re: fclean all

$(DOXYFILE):
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- Generating default Doxyfile configuration file ---"
	@echo
	doxygen -g $(DOXYFILE)
	@echo
	@echo "        --- Customizing Doxyfile configuration file ---"
	@echo
	sed -i '/^PROJECT_NAME.*=/s/^.*$$/PROJECT_NAME = "$(DOX_PROJECT_NAME)"/' $(DOXYFILE)
	sed -i -e '/^PROJECT_NUMBER.*=/s/^.*$$/PROJECT_NUMBER = $(DOX_PROJECT_NUMBER)/' $(DOXYFILE)
	sed -i '/^PROJECT_BRIEF.*=/s/^.*$$/PROJECT_BRIEF = "$(DOX_PROJECT_BRIEF)"/' $(DOXYFILE)
	sed -i '\|^OUTPUT_DIR.*=|s|^.*$$|OUTPUT_DIRECTORY = $(DOC_DIR)|' $(DOXYFILE)
	sed -i '\|^INPUT .*=|s|^.*$$|INPUT = $(DOX_INPUT)|' $(DOXYFILE)
	sed -i '/^RECURSIVE.*=/s/^.*$$/RECURSIVE = $(DOX_RECURSIVE)/' $(DOXYFILE)
	sed -i '/^OPTIMIZE_OUTPUT_FOR_C.*=/s/^.*$$/OPTIMIZE_OUTPUT_FOR_C = $(DOX_OPTIMIZE_OUTPUT_FOR_C)/' $(DOXYFILE)
	sed -i '\|^USE_MDFILE_AS_MAINPAGE.*=|s|^.*$$|USE_MDFILE_AS_MAINPAGE = $(DOX_MAIN_PAGE)|' $(DOXYFILE)
	sed -i '/^GENERATE_HTML .*=/s/^.*$$/GENERATE_HTML = $(DOX_GENERATE_HTML)/' $(DOXYFILE)
	sed -i '/^GENERATE_LATEX.*=/s/^.*$$/GENERATE_LATEX = $(DOX_GENERATE_LATEX)/' $(DOXYFILE)
	sed -i '/^GENERATE_RTF.*=/s/^.*$$/GENERATE_RTF = $(DOX_GENERATE_RTF)/' $(DOXYFILE)
	sed -i '/^GENERATE_MAN.*=/s/^.*$$/GENERATE_MAN = $(DOX_GENERATE_MAN)/' $(DOXYFILE)
	@echo
	@echo ----------------------------------------------------------------------

doc: $(DOXYFILE)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- Generating project documentation ($(DOC_DIR)) ---"
	@echo
	doxygen $(DOXYFILE)
	@echo
	@echo ----------------------------------------------------------------------

docclean:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- Cleaning documentation directory and Doxyfile ---"
	@echo
	rm -rf $(DOC_DIR)
	rm $(DOXYFILE)
	@echo
	@echo ----------------------------------------------------------------------

tester: $(BIN_DIR)$(TESTER_NAME)

$(BIN_DIR)$(TESTER_NAME): $(TEST_DIR)$(TEST_SRC) $(BIN_DIR)$(NAME)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "        --- Compiling tester to $(BIN_DIR)$(TESTER_NAME) ---"
	@echo
	cc $(CC_FLAGS) $(TEST_DIR)$(TEST_SRC) $(BIN_DIR)$(NAME) -o $(BIN_DIR)$(TESTER_NAME) -I$(INC_DIR) -I$(TEST_DIR) 
	@echo
	@echo ----------------------------------------------------------------------

# Help rule: because I use to forget everything
help:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- Ayuda ---"
	@echo
	@echo "    usar 'make', 'make all' o 'make $(BIN_DIR)$(NAME)' para compilar el proyecto base como: $(BIN_DIR)$(NAME)"
	@echo "    usar 'make bonus' para compilar el bonus (en caso de estar disponible) como $(BIN_DIR)$(BONUS_NAME)"
	@echo "    usar 'make tester' para compilar el programa de pruebas (en caso de estar disponible) como $(BIN_DIR)$(TESTER_NAME)"
	@echo "    usar 'make clean' para borrar los archivos .o y su directorio $(OBJ_DIR)"
	@echo "    usar 'make fclean para hacer 'clean' y ademas borrar todos los binarios y su directorio $(BIN_DIR)"
	@echo "    usar 'make re' para hacer 'fclean' y luego 'all'"
	@echo "    usar 'make help' para mostrar esta ayuda"
	@echo
	@echo ----------------------------------------------------------------------

# Phonies: this list of words are never to be interpreted as files but
# only as rule names
#
.PHONY: all clean fclean re tester help bonus doc docclean
