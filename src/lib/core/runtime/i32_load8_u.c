#include <core/Runtime.h>
#include <dataTypes/Value.h>
#include <instance/MemInst.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int runtime_i32_load8_u(Stack* stack, MemInst* memory, uint32_t offset, uint32_t align)
{
    Value *value1 = NULL;
    pop_Value(stack,&value1);
    uint32_t ea = (uint32_t)value1->value.i32 + offset;
    if(ea + (8 / 8) >= memory->max * 65536) {
        fprintf(stderr, "over the memory range! \n");
        free(value1);
        return -1;
    }
    uint8_t* data = (uint8_t*)memory->data->data + ea;
    push_Value(stack, new_i32Value(*data));
    free(value1);
    return 0;
}
