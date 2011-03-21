#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ghdl/ghdl_rti.h"
#include "ghdl/ghdl_signals.h"
#define __USE_GNU  //dladdr() is a GLIBC non std function
#include <dlfcn.h>

Ghdl_Rtin_Object* sig_Rti;

const char* getSymbol(void* addr){
  Dl_info info;
  if(dladdr(addr,&info) && info.dli_saddr == addr)
    return info.dli_sname;
  return "unknown location";
}

void dump_sig_Rti(){
  /*sig_Rti->common;
  sig_Rti->name;
  sig_Rti->loc;
  sig_Rti->obj_Type;*/
  printf("  signal name  : %s \n",sig_Rti->name);
  printf("  type   symbol: %s \n",getSymbol(sig_Rti->obj_Type));
  printf("  type   name  : %s \n",((Ghdl_Rtin_Object*)sig_Rti->obj_Type)->name);
}

void dump_block_rti(Ghdl_Rtin_Block* rti){
  printf("  block name   : %s \n",rti->Name);
}

/* function Ghdl_Create_Signal_E32
     (Init_Val : Ghdl_E32;
      Resolv_Func : System.Address;
      Resolv_Inst : System.Address)*/
Ghdl_Signal_Ptr __ghdl_create_signal_i32(uint32_t init_Val,void* resolv_func,void* resolv_inst){
  printf("\n-- Create i32 Signal --\n");
  dump_sig_Rti();
  printf("  init_val     : %d \n",init_Val);
  printf("  resolv_func  : %s \n",getSymbol(resolv_func));
  printf("  resolv_inst  : %s \n",getSymbol(resolv_inst));
  Ghdl_Signal_Ptr sig=malloc(sizeof(Ghdl_Signal));
  printf("  signal addr  : %p \n",sig);
  return sig;
}

void __ghdl_process_add_sensitivity(){
  printf("\n__ghdl_process_add_sensitivity() called\n");
}

/*   procedure Ghdl_Sensitized_Process_Register
     (Instance : System.Address;
      Proc : System.Address;
      Ctxt : Ghdl_Rti_Access;
      Addr : System.Address)*/
void __ghdl_sensitized_process_register(
    void* instance,
    void* proc,
    Ghdl_Rtin_Block_Acc ctxt,
    void* addr){
  printf("\n__ghdl_sensitized_process_register() called\n");
  printf("  instance     : %p (%s)\n",instance,getSymbol(instance));
  printf("  proc         : %p (%s)\n",proc,getSymbol(proc));
  printf("  ctxt         : %p (%s)\n",ctxt,getSymbol(ctxt));
  printf("  addr         : %p (%s)\n",addr,getSymbol(addr));
  dump_block_rti(ctxt);
}

void __ghdl_signal_active_chain(){
  printf("\n__ghdl_signal_active_chain() called\n");
}

/*procedure Ghdl_Signal_Direct_Driver (Sign : Ghdl_Signal_Ptr;
                                       Drv : Ghdl_Value_Ptr)*/
void __ghdl_signal_direct_driver(Ghdl_Signal_Ptr signal,Ghdl_Value_Ptr driver){
  printf("\n__ghdl_signal_direct_driver() called\n");
  printf("  signal : %p (%s)\n",signal,getSymbol(signal));
  printf("  driver : %p (%s)\n",driver,getSymbol(driver));
}

/*procedure Ghdl_Signal_Name_Rti (Sig : Ghdl_Rti_Access;
                                   Ctxt : Ghdl_Rti_Access;
                                   Addr : System.Address);*/
void __ghdl_signal_name_rti(Ghdl_Rti_Access sig,
                            Ghdl_Rti_Access ctxt,
                            void* addr){
  /*printf("\n__ghdl_signal_name_rti() called\n");*/
  sig_Rti=(Ghdl_Rtin_Object*)sig;
}

void __ghdl_stack2_allocate(){
  printf("__ghdl_stack2_allocate unimplemented\n");
  abort();
}

void __ghdl_memcpy(){
  printf("__ghdl_memcpy unimplemented\n");
  abort();
}

void __ghdl_bound_check_failed_l1(){
  printf("__ghdl_bound_check_failed_l1 unimplemented\n");
  abort();
}

void __ghdl_bound_check_failed_l0(){
  printf("__ghdl_bound_check_failed_l0 unimplemented\n");
  abort();
}

/*int ieee__std_logic_1164__ELABORATED;*/

/*void ieee__std_logic_1164__ELAB_BODY(){
  printf("ieee__std_logic_1164__ELAB_BODY\n");
}*/

/*int std__standard__integer__RTI;*/

Ghdl_Rtin_Object work__RTI;
Ghdl_Rtin_Object std__RTI;

#define GHDL_DECLARE(library,entity,architecture) \
  extern int library ## __ ## entity ## __ARCH__ ## architecture ## __INSTSIZE;\
  void library ## __ ## entity ## __ARCH__ ## architecture ## __ELAB(void * inst)
  
#define GHDL_INSTANCIATE(inst_ptr,library,entity,architecture) \
  inst_ptr=malloc(library ## __ ## entity ## __ARCH__ ## architecture ## __INSTSIZE); \
  library ## __ ## entity ## __ARCH__ ## architecture ## __ELAB(inst_ptr)

GHDL_DECLARE(work,test,rtl);

int main(){
  void *inst;

  GHDL_INSTANCIATE(inst,work,test,rtl);
  free(inst);
  return 0;
}
