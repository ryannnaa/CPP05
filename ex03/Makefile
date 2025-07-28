CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := a.out

SRCS := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS := ${SRCS:.cpp=.o}
DEPS := ${OBJS:.o=.d}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@
	
-include ${DEPS}

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
