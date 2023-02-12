
# **************************** dependency rules ****************************** #

ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEP)
endif

# ****************************** compile rules ******************************* #

# mandatory
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@

