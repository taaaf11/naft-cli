naft:
	gcc naft.c -o naft

install: naft
	@mkdir -p /home/$(USER)/.local/bin
	@echo Installing into /home/$(USER)/.local/bin
	@install naft /home/$(USER)/.local/bin
	@echo Don\'t forget to add /home/$(USER)/.local/bin to your PATH!

clean:
	rm -f naft a.out
