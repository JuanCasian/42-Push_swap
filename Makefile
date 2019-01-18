# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 18:42:55 by jcasian           #+#    #+#              #
#    Updated: 2019/01/17 19:48:19 by jcasian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
NC = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m

# executable names
CNAME = checker
PNAME = push_swap

# Directories
LIBFTDIR = libft
LIBSDIR = libs
INCLUDES = includes
SRCSDIR = srcs

# compilation flags
FLAGS = -Wall -Werror -Wextra

# Source files for all
CSRCS = $(addprefix $(SRCSDIR)/,\
		checker.c)

PSRCS = $(addprefix $(SRCSDIR)/,\
		push_swap.c)

SRCS =  $(addprefix $(SRCSDIR)/,\
		input_functions.c put_error.c free_functions.c stack_functions.c \
		ft_atoll.c order_functions.c push_functions.c rotate_functions.c \
		swap_functions.c rev_rotate_functions.c) 

LIBFTSRCS = $(addprefix $(LIBFTDIR)/,\
			checks_after_percentage.c ft_atoi.c ft_bzero.c ft_count_words.c \
			ft_filetostr.c ft_is_space.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoalonglong.c ft_lstadd.c \
			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_printf.c ft_printlist.c \
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putwchar.c ft_remalloc.c \
			ft_samplelist.c ft_straddprefix.c ft_straddsuffix.c ft_strcat.c \
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_strinit.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c \
			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c \
			ft_strstr.c ft_strsub.c ft_strtoupper.c ft_strtrim.c ft_tolower.c \
			ft_toupper.c ft_utoabaselonglong.c ft_wchar_len.c ft_wstraddprefix.c \
			ft_wstraddsuffix.c ft_wstrdup.c ft_wstrlen.c ft_wstrnew.c \
			get_next_line.c is_tests.c prepare_address.c prepare_binary.c \
			prepare_char.c prepare_hexadecimal.c prepare_octal.c \
			prepare_percentage.c prepare_signed.c prepare_str.c prepare_undecimal.c \
			print_error.c struct_handle.c ft_countcharsrepetition.c \
			get_next_line_stdin.c)

# Object names
LIBFTOBJECTS = $(patsubst %.c, %.o, $(LIBFTSRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))

COBJS = $(patsubst %.c, %.o, $(CSRCS))

POBJS = $(patsubst %.c, %.o, $(PSRCS))

all: lib $(CNAME) $(PNAME)

# objects creation
$(OBJS): %.o: %.c
	@echo "${YELLOW}Preparing Objects... Please wait${NC}"
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(LIBFTOBJECTS): %.o: %.c
	@echo "${YELLOW}Preparing Library... Please wait${NC}"
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(COBJS): %.o: %.c
	@echo "${YELLOW}Preparing Checker... Please wait${NC}"
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(POBJS): %.o: %.c
	@echo "${YELLOW}Preparing Push_swap... Please wait${NC}"
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

# library processes
lib: $(LIBFTOBJECTS)
	@ar rc $(LIBSDIR)/libft.a $(LIBFTOBJECTS)
	@ranlib $(LIBSDIR)/libft.a
	@echo "${GREEN}Library is ready!${NC}"

libclean:
	@echo "${YELLOW}Cleanning objects...${NC}"
	@rm -f $(LIBFTOBJECTS)
	@echo "${GREEN}DONE!${NC}"

libfclean: libclean
	@echo "${YELLOW}Deleting library...${NC}"
	@rm -f $(LIBSDIR)/libft.a
	@echo "${GREEN}DONE!${NC}"

# executables creations
$(CNAME): $(OBJS) $(COBJS) 
	@gcc -Wall -Werror -Wextra -I$(INCLUDES) -L$(LIBSDIR) -lft $(COBJS) $(OBJS) -o $(CNAME)
	@echo "${GREEN}Program:" $(CNAME) "is ready!${NC}"

$(PNAME): $(OBJS) $(POBJS)
	@gcc -Wall -Werror -Wextra -I$(INCLUDES) -L$(LIBSDIR) -lft $(POBJS) $(OBJS) -o $(PNAME)
	@echo "${GREEN}Program:" $(PNAME) "is ready!${NC}"

# cleaning functions
cclean:
	@echo "${YELLOW}Cleanning objects...${NC}"
	@rm -f $(COBJS) $(OBJS)
	@echo "${GREEN}DONE!${NC}"

pclean:
	@echo "${YELLOW}Cleanning objects...${NC}"
	@rm -f $(POBJS) $(OBJS)
	@echo "${GREEN}DONE!${NC}"

cfclean: cclean
	@echo "${YELLOW}Cleanning Program...${NC}"
	@rm -f $(CNAME)
	@echo "${GREEN}DONE!${NC}"

pfclean: pclean
	@echo "${YELLOW}Cleanning Program...${NC}"
	@rm -f $(PNAME)
	@echo "${GREEN}DONE!${NC}"

clean:  cclean pclean libclean

fclean: pfclean cfclean libfclean

# debuging processes
debug$(CNAME):
	gcc -g -Wall -Werror -Wextra $(CSRCS) $(SRCS) $(LIBFTSRCS) -I$(INCLUDES) -o debug

debug$(PNAME):
	gcc -g -Wall -Werror -Wextra $(PSRCS) $(SRCS) $(LIBFTSRCS) -I$(INCLUDES) -o debug

debugclean:
	rm -rf debug*

relib: fclean lib

re$(CNAME): cfclean $(CNAME)

re$(PNAME): cfclean $(PNAME)

re: pfclean cfclean libfclean all

