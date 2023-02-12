# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:45:28 by hyeyukim          #+#    #+#              #
#    Updated: 2023/02/12 18:23:13 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ray_tracing
.DEFAULT_GOAL := all

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

bonus :
	make WITH_BONUS=1 all

include config/rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_PATH)

fclean : clean
	$(RM) $(RMFLAGS) $(RESULT_DIR)/error_log
	$(RM) $(NAME)

re :
	make fclean
	make all

# ******************************* assist rules ******************************* #

.PHONY : img

img :
	make all
	mkdir -p $(RESULT_DIR)
	sh script/get_img_log.sh
	