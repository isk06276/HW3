#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f) 
{
  printf ("system call!\n");
	switch (*(uint32_t *)(f->exp)){
		case SYS_HALT:
			break;
		case SYS_EXIT:
			exit(*(uint32_t)(f->esp+20));
			break;





	}

}
void halt(void){
	power_off();
}

void exit(int status){
	struct thread *t= thread_current();
	t->exit_status = status;
	print("%s: exit(%d)\n", t->name, status);
	thread_exit();
}
