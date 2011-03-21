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

struct Ghdl_Signal_;
typedef struct Ghdl_Signal_* Ghdl_Signal_Ptr;
struct Ghdl_Signal_{
	//  Fields known by ghdl.//
	Value_Union Value;
	Value_Union Driving_Value;
	Value_Union Last_Value;
	Std_Time    Last_Event;
	Std_Time    Last_Active;
	// Chain of signals.
	//  Used to build nets.
	//  This is also the simply linked list of future active signals.
	Ghdl_Signal_Ptr Link;
  bool        event;
	bool        active;
	//  If set, the activity of the signal is required by the user.
	bool        Has_Active;
}Ghdl_Signal;


typedef Value_Union* Ghdl_Value_Ptr;

#endif //#ifndef __GHDL_SIGNALS_H__
