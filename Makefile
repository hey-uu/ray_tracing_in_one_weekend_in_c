
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
	$(RM) $(RMFLAG1) $(RMFLAG2) $(OBJ_PATH)

fclean : clean
	$(RM) $(RMFLAG1) $(RESULT_DIR)/error_log
	$(RM) $(RMFLAG1) $(NAME)

re :
	make fclean
	make all

# ******************************* assist rules ******************************* #

.PHONY : img

img :
	make all
	mkdir -p $(RESULT_DIR)
	sh script/get_img_log.sh
