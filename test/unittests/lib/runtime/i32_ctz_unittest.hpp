#include <skypat/skypat.h>

#define _Bool bool
extern "C"{
    #include <core/Runtime.h>
}
#undef _Bool

SKYPAT_F(Runtime_i32_ctz, regular)
{
    // prepare
    Stack* stack = new_Stack();
    Value *value1 = new_i32Value(2147483648);
    stack->entries->push(stack->entries, value1);

    // run
    runtime_i32_ctz(stack);

    // check
    Value *check = NULL;
    stack->entries->pop(stack->entries, (void**)&check);
    EXPECT_EQ(check->value.i32, 31); 
}