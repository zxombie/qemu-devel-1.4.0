#ifndef _TARGET_VMPARAM_H_
#define _TARGET_VMPARAM_H_

#define	TARGET_HW_MACHINE	"mips"
#define	TARGET_HW_MACHINE_ARCH	"mips64"

#if defined(__FreeBSD__)

#define	TARGET_VM_MINUSER_ADDRESS	(0x0000000000000000UL)
#define	TARGET_VM_MAXUSER_ADDRESS	(0x0000008000000000UL)

#define	TARGET_USRSTACK	(TARGET_VM_MAXUSER_ADDRESS - TARGET_PAGE_SIZE)

struct target_ps_strings {
	abi_ulong ps_argvstr;
	uint32_t ps_nargvstr;
	abi_ulong ps_envstr;
	uint32_t ps_nenvstr;
};

#define TARGET_SPACE_USRSPACE	4096
#define TARGET_ARG_MAX		262144

#define TARGET_PS_STRINGS  (TARGET_USRSTACK - sizeof(struct target_ps_strings))

/* Make stack size large enough to hold everything. */
#define TARGET_STACK_SIZE ((x86_stack_size < MAX_ARG_PAGES*TARGET_PAGE_SIZE) ? \
    MAX_ARG_PAGES*TARGET_PAGE_SIZE : x86_stack_size)

#else

#define	TARGET_USRSTACK	 0
#endif

#endif /* _TARGET_VMPARAM_H_ */
