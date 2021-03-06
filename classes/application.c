#include <stdio.h>
#include <stdlib.h>

#include "Application.h"


#include "../classes/string.h"
#include "../classes/accumulator.h"
#include "../classes/dummy.h"
#include "../classes/dummy2.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

CyClass* Cy_class_Application;

Cy_struct_Application* _Application_i_construct_i_ppb(CyClass* cls, Cy_struct_Application* self, int argc, char* argv[])
{
    CY_INVOKE(void*, cls->parent, M_i_construct, self);
    self->name = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_construct_pb, CY_NEW(String), "NoTitle");
    self->argc = argc;
    self->argv = argv;
    puts("Application Created !!");
    printf("Application arguments: %d\n", self->argc);
    int i = 0;
    for (i = 0; i < self->argc; i++)
    {
        puts(self->argv[i]);
    }
    puts("End of application arguments.");
    return self;
}

int _Application_i_run(CyClass* cls, Cy_struct_Application* self)
{
    printf("Application %s Running !!\n", self->name->data);

    // Using String object
    Cy_struct_String* str1 = CY_NEW(String);
    CY_INVOKE(void*, Cy_class_String, M_i_construct_pb, str1, "Hello");
    Cy_struct_String* str2 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_construct_pb, CY_NEW(String), " People");
    Cy_struct_String* str3 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_concat_ZCString, str1, str2);
    printf("%s\n", str3->data);
    Cy_struct_String* str4 = CY_INVOKE(Cy_struct_String*, Cy_class_String, M_i_concat_pb_pb, str1, ", ", "World");
    printf("%s\n", str4->data);
    printf("%c%c\n", CY_INVOKE(char, Cy_class_String, M_i_charAt_i, str4, 0), CY_INVOKE(char, Cy_class_String, M_i_charAt_i, str4, 7));

    // Using Dummy object
    Cy_struct_Dummy* dummy = CY_NEW(Dummy);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Dummy, M_i_construct, dummy);

    // Using Accumulator object
    Cy_struct_Accumulator* acc = CY_NEW(Accumulator);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_construct, acc);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 10);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 30);
    CY_INVOKE(Cy_struct_Dummy*, Cy_class_Accumulator, M_i_add_i, acc, 2);
    printf("Accumulator = %d\n", CY_INVOKE(int, Cy_class_Accumulator, M_i_getValue, acc));

    // Using Dummy2 object
    Cy_struct_Dummy2* dummy2 = CY_NEW(Dummy2);
    CY_INVOKE(Cy_struct_Dummy2*, Cy_class_Dummy2, M_i_construct, dummy2);

    return 0;
}
