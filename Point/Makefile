srcs := \
	../generated/c/GenericRequirementsForSci/SSciEfesPrim.c \
	../generated/c/SubsystemPoint/SSciPReceive.c \
	../generated/c/SubsystemPoint/SSciPCommand.c \
	main.c

hdrs := \
	../generated/c/GenericRequirementsForSci/SSciEfesPrim.h \
	../generated/c/SubsystemPoint/SSciPReceive.h \
	../generated/c/SubsystemPoint/SSciPCommand.h

point: $(srcs) $(hdrs)
	$(CC) $(CFLAGS) -g -I../generated/c -o point $(srcs) $(LDFLAGS)
