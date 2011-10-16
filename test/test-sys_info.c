
//gcc test-sys_info.c -I../include -DLINUX32 -L../build -lvm -lpthread

//gcc test-sys_info.c -I../include -DLINUX32 -L../build/release -lvm -L /opt/intel/ipp/lib/intel64/ -L /opt/intel/lib/intel64/ -lipps_t  -lippcore_t  -pthread -lm -liomp5 -static



#include <stdio.h>
#include "vm_sys_info.h"

int main() {

  printf(" Sys Info testing : \n");

  char cpu_name[256];
  Ipp32u value =0;

  vm_sys_info_get_computer_name(&cpu_name[0]);
  printf("   Computer Name:  %s \n", cpu_name);


  vm_sys_info_get_os_name(&cpu_name[0]);
  printf("   OS Name:  %s \n", cpu_name);


  vm_sys_info_get_cpu_name(&cpu_name[0]);
  printf("   CPU Name:  %s \n", cpu_name);

  value = vm_sys_info_get_cpu_speed();
  printf("   CPU Speed:  %d \n", value);

  value = vm_sys_info_get_cpu_num();
  printf("   CPU Number:  %d \n", value);

  value = vm_sys_info_get_avail_cpu_num();
  printf("   CPU Available:  %d \n", value);


  value = vm_sys_info_get_mem_size();
  printf("   Memory Size:  %d \n", value);

  vm_sys_info_get_vga_card(&cpu_name[0]);
  printf("   VGA Name:  %s \n", cpu_name);

  VM_PID pid;
  pid = vm_sys_info_getpid();
  printf("   Process ID:  %d \n", pid);

 //  value = vm_sys_info_get_process_memory_usage(pid);
 // printf("   Process Memory:  %d \n", value);

  //void vm_sys_info_get_date(vm_char *m_date, DateFormat df);
  //void vm_sys_info_get_time(vm_char *m_time, TimeFormat tf);

  vm_sys_info_get_program_name(&cpu_name[0]);
  printf("   Program Name:  %s \n", cpu_name);

  vm_sys_info_get_program_path(&cpu_name[0]);
  printf("   Program Path:  %s \n", cpu_name);

//  void vm_sys_info_get_program_description(vm_char *program_description);


  return 0;
}


