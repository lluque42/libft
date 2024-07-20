# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:23:32 by lluque            #+#    #+#              #
#    Updated: 2024/07/21 00:33:46 by lluque           ###   ########.fr        #
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
BONUS_NAME = $(NAME)
# Separate bonus compilation was droped after this project was submitted for
# evaluation.
# In other 42 projects the code will be structured in basic/ shared/ bonus/
# directories inside $(SRC_DIR) and $(INC_DIR). Shared code is always compiled.
# Additionally, basic OR bonus code will be compiled depending on the invocation
# of make.

# Resulting tester name (to be placed in BIN_DIR)
TESTER_NAME = tester

# Archive command flags
AR_FLAGS = rcs

# Default value of DEBUG (if passed from command line DEBUG=... overrides it)
DEBUG = no

# Optional debugging flags, conditional to DEBUG value and MAKE_DEBUG_LVL passed
# from command line.
ifeq ($(DEBUG), g)
	DEB_FLAGS = -g
else ifeq ($(DEBUG), addsan)
	DEB_FLAGS = -g -fsanitize=address
else
	DEB_FLAGS =
endif

# Default value of MAKE_DEBUG_LVL (if passed from command line MAKE_DEBUG_LVL=... overrides it)
# Intended to be passed to the code as a #define integer_value to enable levels
# of debug messages from the program.
# No default value set intentionally (this doesn't evaluate as defined).
MAKE_DEBUG_LVL =

# Condition to add the debugging level if coming from the comand line.
ifdef MAKE_DEBUG_LVL
	DEB_FLAGS += -D MAKE_DEBUG_LVL=$(MAKE_DEBUG_LVL)
endif

# Compiler to use
CC = cc

# Compiler flags
CC_FLAGS = -Wall -Werror -Wextra $(DEB_FLAGS)

# List of header file names that, if modified, should force recompiling
INCLUDES = $(INC_DIR)libft.h \
		   $(INC_DIR)ft_char.h \
		   $(INC_DIR)ft_debug.h \
		   $(INC_DIR)ft_file.h \
		   $(SRC_DIR)file/ft_gnl/ft_gnl.h \
		   $(INC_DIR)ft_llst.h \
		   $(INC_DIR)ft_math.h  \
		   $(INC_DIR)ft_memory.h \
		   $(INC_DIR)ft_string.h \
		   $(SRC_DIR)string/ft_printf/ft_printf_utils.h \
		   $(INC_DIR)ft_dlclst.h

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
		  string/ft_ltoa.c \
		  string/ft_ltoa_b.c \
		  string/ft_ultoa_b.c \
		  string/ft_uitoa_b.c \
		  string/ft_printf/add_precision_for_numbers.c \
		  string/ft_printf/init_format.c \
		  string/ft_printf/print_hex_integer.c \
		  string/ft_printf/add_width_alignment.c \
  		  string/ft_printf/parse_conversion.c \
  		  string/ft_printf/print_integer.c \
		  string/ft_printf/add_width_alignment_utils.c \
	  	  string/ft_printf/parse_format.c \
		  string/ft_printf/print_pointer.c \
		  string/ft_printf/ft_printf.c \
		  string/ft_printf/parse_literal_char.c \
  		  string/ft_printf/print_string.c \
  		  string/ft_printf/parser_select.c \
		  string/ft_printf/printer_select.c \
		  string/ft_printf/generic_functions.c \
  		  string/ft_printf/print_char.c \
		  string/ft_aisi.c \
		  string/ft_is_string_composed_of_char.c \
		  string/ft_atoi_b.c \
		  file/ft_putchar_fd.c \
		  file/ft_putstr_fd.c \
		  file/ft_putendl_fd.c \
		  file/ft_putnbr_fd.c \
		  file/ft_putchar_fd_safe.c \
		  file/ft_putstr_fd_safe.c \
		  file/ft_gnl/ft_gnl.c \
		  file/ft_gnl/ft_gnl_utils.c \
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
		  debug/ft_print_memory.c \
		  dlclst/ft_dlclst_insback.c \
		  dlclst/ft_dlclst_insfront.c \
		  dlclst/ft_dlclst_inspos.c \
		  dlclst/ft_dlclst_last.c \
		  dlclst/ft_dlclst_new.c \
		  dlclst/ft_dlclst_remback.c \
		  dlclst/ft_dlclst_remfront.c \
		  dlclst/ft_dlclst_rempos.c \
		  dlclst/ft_dlclst_clear.c \
		  dlclst/ft_dlclst_iter.c \
		  dlclst/ft_dlclst_map.c \
		  dlclst/ft_dlclst_search.c \
		  dlclst/ft_dlclst_rotateprev.c \
		  dlclst/ft_dlclst_rotatenext.c \
		  dlclst/ft_dlclst_swapfront.c \
		  dlclst/ft_dlclst_swapback.c \
		  dlclst/ft_dlclst_extractfront.c \
		  dlclst/ft_dlclst_extractback.c \
		  dlclst/ft_dlclst_extractpos.c \
		  dlclst/ft_dlclst_size.c \
		  strarr/ft_free_strarr.c \
		  strarr/ft_putstrarr_fd.c \
		  strarr/ft_remove_blanks_strarr.c \
		  strarr/ft_strarrlen.c

# Auto generated list of object file names from SOURCES by: replacing
# the file extension .c for .o; and adding the $(OBJ_DIR) to the resulting
# list of file names (thus maintaining the directory structure of the
# code files.
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

################## VARIABLES FOR ANSI ESCAPE CODES FOR COLORS ##################
################################################################################

# BASIC COLOR CODES
RED = \033[0;31m
GREEN = \033[0;32m
CYAN = \033[0;36m
PURPLE = \033[0;35m

# BOLD COLOR CODES
BRED = \033[1;31m
BGREEN = \033[1;32m
BCYAN = \033[1;36m
BPURPLE = \033[1;35m

# No Color (resets previously set color)
NC=\033[0m
################## VARIABLES FOR ANSI ESCAPE CODES FOR COLORS ##################
################################################################################

################################ RULES #########################################
################################################################################

# Default rule
all: $(BIN_DIR)$(NAME)

# Rule for NAME as phony
# (i.e. to allow 'make my_project' instead of 'make ./bin/my_project'
$(NAME): $(BIN_DIR)$(NAME)

# Rule (pattern rule) to individually (no relink) compile objects
############################### REMEMBER #######################################
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
$(OBJECTS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES) print_title
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I$(INC_DIR)
	@echo -n -e '${BGREEN}!${NC}'

# This rule creates a file as a flag because using a rule which does not
# produce a target file as a requisite of another rule always forces the later
# to be executed. This flag file is deleted along with the object files.
print_title:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "              --- ${PURPLE}Building ${BPURPLE}$(NAME)${NC} ---"
	@echo
	@echo -n -e '${BGREEN}${NC}'
	@touch print_title

# Rule to archive objects into library
$(BIN_DIR)$(NAME): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@ar $(AR_FLAGS) $(BIN_DIR)$(NAME) $(OBJECTS)
	@echo
	@echo -n -e '${BGREEN}$(NAME) done!${NC}'
	@echo
	@echo ----------------------------------------------------------------------

# Cleaning rule: deletes object files and directory.
# Possible additions to the recipe:
# 	rm -rf $(BONUS_OBJ_DIR)
# 	make clean --directory=$(SOME_LIBRARY_PATH)
#
clean:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- ${PURPLE}Cleaning (at $(NAME))${NC} ---"
	@echo
	rm -rf $(OBJ_DIR)
	@rm print_title
	@echo
	@echo ----------------------------------------------------------------------

# Full cleaning rule: deletes objects files, all binary outputs, and directories
# Possible additions to the recipe:
# 	make fclean --directory=$(SOME_ANOTHER_LIBRARY_PATH)
#
fclean:clean
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- ${PURPLE}Fcleaning (at $(NAME))${NC} ---"
	@echo
	rm -rf $(BIN_DIR)
	@echo
	@echo ----------------------------------------------------------------------

# Rebuild rule: deletes objects files and all outputs, then compiles again
re: fclean all

# Rule to create and customize Doxygen configuration file which will define
# how to generate the project's documentation from comments in the code when
# using 'make doc'.
$(DOXYFILE):
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- ${PURPLE}Generating default Doxygen configuration file: ${BPURPLE}./$(DOXYFILE)${NC} ---"
	@echo
	doxygen -g $(DOXYFILE)
	@echo
	@echo "        --- ${PURPLE}Customizing Doxygen configuration file: ${BPURPLE}./$(DOXYFILE)${NC} ---"
	@echo
	sed -i '/^PROJECT_NAME.*=/s/^.*$$/PROJECT_NAME = "$(DOX_PROJECT_NAME)"/' $(DOXYFILE)
	sed -i '/^PROJECT_NUMBER.*=/s/^.*$$/PROJECT_NUMBER = $(DOX_PROJECT_NUMBER)/' $(DOXYFILE)
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

# Rule to generate the project's documentation from commented code.
doc: $(DOXYFILE)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- ${PURPLE}Generating project documentation in ${BPURPLE}$(DOC_DIR)${NC} ---"
	@echo
	doxygen $(DOXYFILE)
	@echo
	@echo ----------------------------------------------------------------------

# Rule to delete the project's documentation and Doxygen's configuration file.
docclean:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "      --- ${PURPLE}Cleaning documentation directory and Doxyfile${NC} ---"
	@echo
	rm -rf $(DOC_DIR)
	rm $(DOXYFILE)
	@echo
	@echo ----------------------------------------------------------------------

# Rule to build the test program binary.
tester: $(BIN_DIR)$(TESTER_NAME)

$(BIN_DIR)$(TESTER_NAME): $(TEST_DIR)$(TEST_SRC) $(BIN_DIR)$(NAME)
	@echo ----------------------------------------------------------------------
	@echo
	@echo "        --- ${PURPLE}Compiling tester to $(BIN_DIR)$(TESTER_NAME)${NC} ---"
	@echo
	$(CC) $(CC_FLAGS) $(TEST_DIR)$(TEST_SRC) $(BIN_DIR)$(NAME) -o $(BIN_DIR)$(TESTER_NAME) -I$(INC_DIR) -I$(TEST_DIR) 
	@echo
	@echo ----------------------------------------------------------------------

# Help rule: because I use to forget everything
help:
	@echo ----------------------------------------------------------------------
	@echo
	@echo "                          --- ${PURPLE}Ayuda${NC} ---"
	@echo
	@echo "    usar '${BGREEN}make${NC}', '${GREEN}make ${BGREEN}all${NC}' o '${GREEN}make ${BGREEN}$(BIN_DIR)$(NAME)${NC}' para compilar el proyecto base como: ${CYAN}$(BIN_DIR)$(NAME)${NC}"
	@echo "    usar '${GREEN}make ${BGREEN}bonus${NC}' para compilar el proyecto en version bonus (en caso de estar disponible) como ${CYAN}$(BIN_DIR)$(BONUS_NAME)${NC}"
	@echo "    usar '${GREEN}make ${BGREEN}tester${NC}' para compilar el programa de pruebas (en caso de estar disponible) como ${CYAN}$(BIN_DIR)$(TESTER_NAME)${NC}"
	@echo "    usar '${GREEN}make ${BGREEN}clean${NC}' para borrar los archivos .o y su directorio ${CYAN}$(OBJ_DIR)${NC}"
	@echo "    usar '${GREEN}make ${BGREEN}fclean${NC}' para hacer '${CYAN}clean${NC}' y ademas borrar todos los binarios y su directorio ${CYAN}$(BIN_DIR)${NC}"
	@echo "    usar '${GREEN}make ${BGREEN}re${NC}' para hacer '${CYAN}fclean${NC}' y luego '${CYAN}all${NC}'"
	@echo "    usar '${GREEN}make ... ${BGREEN}DEBUG=...${NC}' para hacer todas las compilaciones con estos flags adicionales:"
	@echo "        ${CYAN}DEBUG=${BCYAN}g${NC}      (e.g. para debugging con lldb)    ---> ${CYAN}-g${NC}"
	@echo "        ${CYAN}DEBUG=${BCYAN}addsan${NC} (i.e. para reportar memory leaks) ---> ${CYAN}-g -fsanitize=address${NC}"
	@echo "        (cualquier otro valor es ignorado)"
	@echo "    usar '${GREEN}make ... ${BGREEN}MAKE_DEBUG_LVL=...${NC}' para compilar el código con un ${CYAN}#define MAKE_DEBUG_LVL ...${NC}"
	@echo "        Se recomienda pasar un valor entero que sería usado en el código como MAKE_DEBUG_LVL"
	@echo "        para imprimir diferentes niveles de mensajes de debugging."
	@echo "    usar '${GREEN}make ${BGREEN}help${NC}' para mostrar esta ayuda"
	@echo
	@echo ----------------------------------------------------------------------

# Phonies: this list of words are never to be interpreted as files but
# only as rule names
#
.PHONY: all clean fclean re tester help bonus $(NAME) doc docclean
