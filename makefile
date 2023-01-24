sub-make:
	$(MAKE) -C src/file/ MAKEFLAGS=
	$(MAKE) -C src/memory/ MAKEFLAGS=
	$(MAKE) -C src/solver/ MAKEFLAGS=