$(CC) := gcc

%:
	@$(CC) $@.c -o $@
	@./$@
	@rm $@
