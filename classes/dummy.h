#ifndef __CY_CLASSES_DUMMY__
#define __CY_CLASSES_DUMMY__

#include "../cy_runtime/runtime.h"

typedef struct {
    Cy_struct_Object super;
} Cy_struct_Dummy;

extern CyClass* Cy_class_Dummy;

Cy_struct_Dummy* _Dummy_i_construct(CyClass* cls, Cy_struct_Dummy* self);
Cy_struct_Dummy* _Dummy_i_dummy(CyClass* cls, Cy_struct_Dummy* self);

#endif
