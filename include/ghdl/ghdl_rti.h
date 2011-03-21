#ifndef __GHDL_RTI_H__
#define __GHDL_RTI_H__
#include <stdbool.h>
#include <stdint.h>

typedef uint32_t Ghdl_Index_Type;

enum Ghdl_Rtik_enum32{
  Ghdl_Rtik_Top,
  Ghdl_Rtik_Library,        /* use scalar*/
  Ghdl_Rtik_Package,
  Ghdl_Rtik_Package_Body,
  Ghdl_Rtik_Entity,
  Ghdl_Rtik_Architecture,
  Ghdl_Rtik_Process,
  Ghdl_Rtik_Block,
  Ghdl_Rtik_If_Generate,
  Ghdl_Rtik_For_Generate,
  Ghdl_Rtik_Instance, /*10*/
  Ghdl_Rtik_Constant,
  Ghdl_Rtik_Iterator,
  Ghdl_Rtik_Variable,
  Ghdl_Rtik_Signal,
  Ghdl_Rtik_File, /* 15*/
  Ghdl_Rtik_Port,
  Ghdl_Rtik_Generic,
  Ghdl_Rtik_Alias,
  Ghdl_Rtik_Guard,
  Ghdl_Rtik_Component, /* 20*/
  Ghdl_Rtik_Attribute,
  Ghdl_Rtik_Type_B2,   /*  Enum*/
  Ghdl_Rtik_Type_E8,
  Ghdl_Rtik_Type_E32,
  Ghdl_Rtik_Type_I32,  /* 25 Scalar*/
  Ghdl_Rtik_Type_I64,
  Ghdl_Rtik_Type_F64,
  Ghdl_Rtik_Type_P32,
  Ghdl_Rtik_Type_P64,
  Ghdl_Rtik_Type_Access,
  Ghdl_Rtik_Type_Array,
  Ghdl_Rtik_Type_Record,
  Ghdl_Rtik_Type_File,
  Ghdl_Rtik_Subtype_Scalar,
  Ghdl_Rtik_Subtype_Array,
  Ghdl_Rtik_Subtype_Array_Ptr,
  Ghdl_Rtik_Subtype_Unconstrained_Array,
  Ghdl_Rtik_Subtype_Record,
  Ghdl_Rtik_Subtype_Access,
  Ghdl_Rtik_Type_Protected,
  Ghdl_Rtik_Element,
  Ghdl_Rtik_Unit,
  Ghdl_Rtik_Attribute_Transaction,
  Ghdl_Rtik_Attribute_Quiet,
  Ghdl_Rtik_Attribute_Stable,
  Ghdl_Rtik_Error
};

typedef uint8_t Ghdl_Rtik;
typedef uint8_t Ghdl_Rti_Depth;
typedef uint8_t Ghdl_Rti_U8;

typedef struct {
  Ghdl_Rtik      Kind;
  Ghdl_Rti_Depth Depth;
  Ghdl_Rti_U8    Mode;
  Ghdl_Rti_Depth Max_Depth;
}Ghdl_Rti_Common;
typedef Ghdl_Rti_Common *Ghdl_Rti_Access;

typedef union {
  uint32_t Ghdl_Index_Type;
  void*    Addr;
}Ghdl_Rti_Loc;

typedef const char* Ghdl_C_String;

typedef struct{
  Ghdl_Rti_Common common;
  Ghdl_C_String   name;
  Ghdl_Rti_Loc    loc;
  Ghdl_Rti_Access obj_Type;
}Ghdl_Rtin_Object;
typedef Ghdl_Rtin_Object* Ghdl_Rtin_Object_Acc;

typedef Ghdl_Rti_Access* Ghdl_Rti_Array;
typedef Ghdl_Rti_Array** Ghdl_Rti_Arr_Acc;

typedef struct{
  Ghdl_Rti_Common  Common;
  Ghdl_C_String    Name;
  Ghdl_Rti_Loc     Loc;
  Ghdl_Rti_Access  Parent;
  Ghdl_Index_Type  Size;
  Ghdl_Index_Type  Nbr_Child;
  Ghdl_Rti_Arr_Acc Children;
}Ghdl_Rtin_Block;
typedef Ghdl_Rtin_Block* Ghdl_Rtin_Block_Acc;

/*  An RTI context contains a pointer (BASE) to or into an instance.
    BLOCK describes data being pointed.  If a reference is made to a field
    described by a parent of BLOCK, BASE must be modified.*/
typedef struct{
  void* base;
  Ghdl_Rti_Access block;
}Rti_Context;

#endif //#ifndef __GHDL_RTI_H__
