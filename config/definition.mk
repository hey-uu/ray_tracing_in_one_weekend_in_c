# **************************** command and flags ***************************** #

# compile
CC						=		cc
CFLAGS1					=		-MMD -MP
CFLAGS2					=		-Wall -Wextra -Werror -g3
CFLAGS3					=		-fsanitize=address -g3
CFLAGS					=		$(CFLAGS1) $(CFLAGS2)

ifdef FSANITIZE_FLAG
	CFLAGS				+=		$(CFLAGS3)
endif

# library archive
AR						=		ar
ARFLAGS					=		crs

# remove
RM						=		rm
RMFLAG1					=		-f
RMFLAG2					=		-r


# ********************************* library ********************************** #

# directory name
LIB_DIR					=		lib

LIBFLAGS				=		-lm

# ******************************** directory ********************************* #

SRC_DIR					=		src
OBJ_DIR					=		obj
INC_DIR					=		include
STRUCT_DIR				=		struct
RESULT_DIR				=		result

# ******************************* header files ******************************* #

# directory path
INC_PATH				=		$(INC_DIR)
INC_STRUCT_PATH			=		$(INC_DIR)/$(STRUCT_DIR)
# flags
INC_FLAG				=		-I./$(INC_PATH) -I./$(INC_STRUCT_PATH)

# ******************************* object files ******************************* #

# directory path
OBJ_PATH				=		$(OBJ_DIR)
SRC_PATH				=		$(SRC_DIR)

FILE					=		camera\
								color_util\
								discriminant\
								image\
								main\
								material\
								ray\
								scatter\
								sphere\
								utils\
								vector_operator\
								vector_util\
								world


# file name(absolute path)
OBJ						=		$(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(FILE)))


# ****************************** dependency files ***************************** #

DEP						=		$(OBJ:.o=.d)

