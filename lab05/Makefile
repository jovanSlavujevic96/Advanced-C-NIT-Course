CC = gcc
AR = ar rs
RM = rm -rf

C_CAESAR_OBJ = caesar_cipher/caesar.o
C_ROT13_OBJ  = ROT13/rot13.o

C_OBJS  = $(C_CAESAR_OBJ)
C_OBJS += $(C_ROT13_OBJ)

CAESAR_STAT_LIB = libcaesar.a
ROT13_STAT_LIB = librot13.a

CAESAR_DYN_LIB = libcaesar.so
ROT13_DYN_LIB = librot13.so

CIPHER_STAT_APP = cipher_static
CIPHER_DYN_APP = cipher_dynamic

OBJECTS  = $(CAESAR_STAT_LIB)
OBJECTS += $(ROT13_STAT_LIB)
OBJECTS += $(CAESAR_DYN_LIB)
OBJECTS += $(ROT13_DYN_LIB)
OBJECTS += $(CIPHER_STAT_APP)
OBJECTS += $(CIPHER_DYN_APP)

INCLUDES  = -Icaesar_cipher
INCLUDES += -IROT13

LIB  = -lcaesar
LIB += -lrot13

$(C_OBJS): %.o: %.c
	$(CC) $(INCLUDES) -c -o $@ $<

$(CAESAR_STAT_LIB):
	$(AR) $@ $(C_CAESAR_OBJ)

$(ROT13_STAT_LIB):
	$(AR) $@ $(C_ROT13_OBJ)

$(CAESAR_DYN_LIB):
	$(CC) -shared -o $@ $(C_CAESAR_OBJ)

$(ROT13_DYN_LIB):
	$(CC) -shared -o $@ $(C_ROT13_OBJ)

$(CIPHER_STAT_APP):
	$(CC) $(INCLUDES) -o $@ cipher.c --static -L. $(LIB)

$(CIPHER_DYN_APP):
	$(CC) $(INCLUDES) -o $@ cipher.c -L. $(LIB) -Wl,--rpath=.

all: $(C_OBJS) $(OBJECTS)

clean:
	$(RM) $(C_OBJS) $(OBJECTS)

.PHONY: clean caeaser rot13 $(OBJECTS)
