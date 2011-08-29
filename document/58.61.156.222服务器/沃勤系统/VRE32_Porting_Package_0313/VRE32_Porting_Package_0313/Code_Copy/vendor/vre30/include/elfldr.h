#ifndef ELFLDR_H_
#define ELFLDR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmio.h"
#include "elf.h"

typedef struct {
	VMFILE file;
	elf_head_t elf_head;
} elf_handle_t;

/**
 * Open ELF file.
 */
int open_elf(VMWSTR filename, elf_handle_t* handle);

/**
 * Close ELF file.
 */
int close_elf(elf_handle_t* handle);

/**
 * Get ELF program head.
 */
int read_elf_prog_head(elf_handle_t* handle, elf_prog_head_t* head);

/**
 * Get ELF section by index.
 */
int read_elf_section_head(elf_handle_t* handle, int idx, elf_section_head_t* head);

/**
 * Get ELF section by name.
 */
int read_elf_section_head_by_name(elf_handle_t* handle, char* name, 
	char* string_table, int table_size, elf_section_head_t* head);

/**
 * Get ELF section head by name.
 */
elf_section_head_t* get_elf_section_head_by_name(char *name,
	char *str_tab, int tab_size, elf_section_head_t *sh,
	int sh_num);

/**
 * Get string from string table.
 */
char* get_elf_string(char* string_table, int table_size, int index);

/**
 * Read section into pre-allocated memory.
 */
int read_elf_section(elf_handle_t* handle, elf_section_head_t* head, void* buf);

#ifdef __cplusplus
}
#endif

#endif