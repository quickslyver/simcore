#ifndef __GHDL_SIGNALS_H__
#define __GHDL_SIGNALS_H__

typedef uint64_t Std_Time;

typedef union{
  bool     B2;
  uint8_t  E8;
  uint32_t E32;
  uint32_t I32;
  uint64_t I64;
  double   F64;
}Value_Union;

typedef struct{
      //  Fields known by ghdl.//
      Value_Union Value;
      Value_Union Driving_Value;
      Value_Union Last_Value;
      Std_Time    Last_Event;
      Std_Time    Last_Active;
}Ghdl_Signal;

typedef Ghdl_Signal* Ghdl_Signal_Ptr;
typedef Value_Union* Ghdl_Value_Ptr;

#endif //#ifndef __GHDL_SIGNALS_H__
