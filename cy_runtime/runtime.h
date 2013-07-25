#ifndef __CY_RUNTIME__
#define __CY_RUNTIME__

#include <setjmp.h>

extern jmp_buf env;

#include "macros.h"
#include "../cy_muids.h"
#include "class.h"

extern CyClass* Cy_class_Object;
extern CyClass* Cy_class_Dummy;
extern CyClass* Cy_class_String;
extern CyClass* Cy_class_Accumulator;

typedef void* (*cy_functionPointer)(void*, ...);

CyClass* CyClass_init(CyClass* self);
CyClass* CyClass_setParent(CyClass* self, CyClass* parent);
CyClass* CyClass_addMethod(CyClass* self, cy_muid muid, void* (*implementation)(void*, ...));
void* CyObject_setClass(void* self, CyClass* cls);

cy_functionPointer cy_findImplementation(jmp_buf env, void* object, cy_muid muid);
cy_functionPointer cy_findSuperImplementation(jmp_buf env, void* object, cy_muid muid);

#include "cy_classes.h"

#endif