#pragma once


int close_other_instance(const char * exename);



inline void Mem_Set_WORD(void *dest, unsigned short data, int count)
{
	//该函数一次填充16位字节内存

	_asm
	{
		mov edi, dest; //EDI指针指向目标内存地址 
		mov ecx, count; //将移动次数放入ECX 
		mov ax, data; //将16位数据放入AX
		rep stosw; //rep指令是重复上述操作,直到ECX为0，每执行一次ECX-1；STOS是将EAX值拷贝到ES:edi指向的地址; 如果设置了direction flag, 那么edi会在该指令执行后减小, 如果没有设置direction flag, 那么edi的值会增加.
	}

}

///////////////////////////////////////////////////////////

inline void Mem_Set_QUAD(void *dest, unsigned int data, int count)
{
	// 该函数一次填充32位字节内存


	_asm
	{
		mov edi, dest;
		mov ecx, count;
		mov eax, data;
		rep stosd;
	}

}