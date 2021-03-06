#ifndef __CY_CLASSES_STRING__
#define __CY_CLASSES_STRING__

#include "../cy_runtime/runtime.h"

typedef struct {
    Cy_struct_Object super;
    char* data;
} Cy_struct_String;

extern CyClass* Cy_class_String;

Cy_struct_String* _String_i_construct(CyClass* cls, Cy_struct_String* self);
Cy_struct_String* _String_i_construct_pb(CyClass* cls, Cy_struct_String* self, char* str);
char _String_i_charAt_i(CyClass* cls, Cy_struct_String* self, int offset);
Cy_struct_String* _String_i_concat_pb(CyClass* cls, Cy_struct_String* self, char* other);
Cy_struct_String* _String_i_concat_ZCString(CyClass* cls, Cy_struct_String* self, Cy_struct_String* other);
Cy_struct_String* _String_i_concat_pb_pb(CyClass* cls, Cy_struct_String* self, char* str1, char* str2);

#endif
