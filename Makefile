# Název projektu
NAME = BalogOS

# Cesty k adresářům
SRC_DIR = kernel/src
OBJ_DIR = kernel/obj
BUILD_DIR = build
INCLUDE_DIR = kernel/include
LINKER_DIR = linker
ISO_DIR = iso

# Nástroje
CC = x86_64-elf-gcc
LD = x86_64-elf-ld
AS = nasm

# Volby kompilace a linkování
CFLAGS = -ffreestanding -nostdlib -m64 -Wall -Wextra -I$(INCLUDE_DIR)
LDFLAGS = -T $(LINKER_DIR)/linker.ld -nostdlib
ASFLAGS = -f elf64

# Soubor výstupů
KERNEL_ELF = $(BUILD_DIR)/kernel.elf
KERNEL_BIN = $(BUILD_DIR)/kernel.bin
ISO_FILE = $(BUILD_DIR)/$(NAME).iso

# Získání všech zdrojových souborů
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS = $(wildcard $(SRC_DIR)/*.asm)
C_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRCS))
ASM_OBJS = $(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%.o, $(ASM_SRCS))
OBJS = $(C_OBJS) $(ASM_OBJS)

# Pravidla
.PHONY: all clean iso

# Výchozí pravidlo
all: $(ISO_FILE)

# Převod na ISO soubor
$(ISO_FILE): $(KERNEL_BIN)
	@mkdir -p $(ISO_DIR)/boot/grub
	cp $(KERNEL_BIN) $(ISO_DIR)/boot/
	cp boot/grub/grub.cfg $(ISO_DIR)/boot/grub/
	grub-mkrescue -o $@ $(ISO_DIR)

# Převod na binární soubor
$(KERNEL_BIN): $(KERNEL_ELF)
	x86_64-elf-objcopy -O binary $< $@

# Linkování kernel.elf
$(KERNEL_ELF): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

# Kompilace C souborů
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Kompilace ASM souborů
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(OBJ_DIR)
	$(AS) $(ASFLAGS) $< -o $@

# Vyčištění
clean:
	rm -rf $(BUILD_DIR) $(OBJ_DIR) $(ISO_DIR)
