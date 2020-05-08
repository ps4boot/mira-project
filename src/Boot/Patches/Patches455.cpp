#include <Boot/Patches.hpp>

using namespace Mira::Boot;

// Patches done by CrazyVoid
// Thanks to
// WildCard for helping with patches
// Joonie for helping with memcpy patch
// LightingMod for being a tester
// Updated by SiSTRo

/*
	Please, please, please!
	Keep patches consistent with the used patch style for readability.
*/
void Patches::install_prerunPatches_455()
{
#if MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_455
	// You must assign the kernel base pointer before anything is done
	if(!gKernelBase)
		return;

	// Use "kmem" for all patches
	uint8_t *kmem;

	// Enable UART
	// Done by WildCard
	kmem = (uint8_t *)&gKernelBase[0x01997BC8];
	kmem[0] = 0x00;

	// Verbose Panics patch
	// Done by WildCard
	kmem = (uint8_t *)&gKernelBase[0x003DBDC7];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	//kmem[5] = 0x65;
	//kmem[6] = 0x8B;
	//kmem[7] = 0x34;

	// Enable rwx mapping
	// Done By WildCard
	kmem = (uint8_t*)&gKernelBase[0x0016ED8C];
	kmem[0] = 0x07;

	kmem = (uint8_t*)&gKernelBase[0x0016EDA2];
	kmem[0] = 0x07;

	// Patch copyin/copyout to allow userland + kernel addresses in both params
	// Done by CrazyVoid
	kmem = (uint8_t *)&gKernelBase[0x0014A8E7];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x0014A802];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Enable MAP_SELF
	// Done by IDC
	kmem = (uint8_t *)&gKernelBase[0x00143BF2];
	kmem[0] = 0x90;
	kmem[1] = 0xE9;

	kmem = (uint8_t *)&gKernelBase[0x00143E0E];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Patch copyinstr
	// Done by CrazyVoid
	kmem = (uint8_t *)&gKernelBase[0x0014AD53];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&gKernelBase[0x0014AD83];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Patch memcpy stack
	// Done by CrazyVoid
	kmem = (uint8_t *)&gKernelBase[0x0014A6BD];
	kmem[0] = 0xEB;

	// ptrace patches
	// Done by WildCard
	kmem = (uint8_t *)&gKernelBase[0x0017D2EE];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// setlogin patch (for autolaunch check)
	kmem = (uint8_t *)&gKernelBase[0x00116B9C];
	kmem[0] = 0x48;
	kmem[1] = 0x31;
	kmem[2] = 0xC0;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Enable *all* debugging logs (in vprintf)
	// Patch by: SiSTRo (ported by kiwidog)
	kmem = (uint8_t*)&gKernelBase[0x0001801A];
	kmem[0] = 0xEB; // jmp +0x3b
	kmem[1] = 0x39;
	
	// Enable mount for unprivileged user
	kmem = (uint8_t *)&gKernelBase[0x000DA483];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;
	
	// the key itself should most likely be moved elsewhere but the offset can be obtained here, 32 bytes/256 bit
	// could probably be less lines too but wanted to keep formatting
	char *eap_hdd_key;
	kmem = (uint8_t *)&gKernelBase[0x0258CCD0];
	eap_hdd_key[0] = kmem[0];
	eap_hdd_key[1] = kmem[1];
	eap_hdd_key[2] = kmem[2];
	eap_hdd_key[3] = kmem[3];
	eap_hdd_key[4] = kmem[4];
	eap_hdd_key[5] = kmem[5];
	eap_hdd_key[6] = kmem[6];
	eap_hdd_key[7] = kmem[7];
	eap_hdd_key[8] = kmem[8];
	eap_hdd_key[9] = kmem[9];
	eap_hdd_key[10] = kmem[10];
	eap_hdd_key[11] = kmem[11];
	eap_hdd_key[12] = kmem[12];
	eap_hdd_key[13] = kmem[13];
	eap_hdd_key[14] = kmem[14];
	eap_hdd_key[15] = kmem[15];
	eap_hdd_key[16] = kmem[16];
	eap_hdd_key[17] = kmem[17];
	eap_hdd_key[18] = kmem[18];
	eap_hdd_key[19] = kmem[19];
	eap_hdd_key[20] = kmem[20];
	eap_hdd_key[21] = kmem[21];
	eap_hdd_key[22] = kmem[22];
	eap_hdd_key[23] = kmem[23];
	eap_hdd_key[24] = kmem[24];
	eap_hdd_key[25] = kmem[25];
	eap_hdd_key[26] = kmem[26];
	eap_hdd_key[27] = kmem[27];
	eap_hdd_key[28] = kmem[28];
	eap_hdd_key[29] = kmem[29];
	eap_hdd_key[30] = kmem[30];
	eap_hdd_key[31] = kmem[31];
#endif
}
