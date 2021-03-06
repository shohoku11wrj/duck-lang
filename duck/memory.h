/* memory.h */
#ifndef _MEMORY_H
#define _MEMORY_H

#include <ctype.h>
#include <stdlib.h>
#include "interpreter.h"

#define PAGE_SIZE       4096

/* memory pages */
typedef struct MEM_PAGE 
{
    void* data_ptrs[PAGE_SIZE];
    unsigned int page_index;
    struct MEM_PAGE* next_page;    
} MEM_PAGE;

extern MEM_PAGE* gBaseMemory;
extern MEM_PAGE* gWorkingMemory;

/* memory management */
void* ALLOCATE(size_t amount);
void  DEALLOCATE(void* memory);
void  CreateEnvironment();
void  FreeEnvironment();

void* ALLOC(size_t amount);
void  DEALLOC(void* addr);

/* */
void FreeContext(CONTEXT* context);
void FreeFunction(FUNCTION* func);
void InvalidateExpr(VALUE expression);
void ForceFreeContext(CONTEXT* context);

/* accessor functions */
VALUE GetRecord(const char* identifier, CONTEXT* context);
void  StoreRecord(const char* identifier, VALUE value, CONTEXT* context);

#endif // _MEMORY_H

