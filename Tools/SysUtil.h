#pragma once


int close_other_instance(const char * exename);



inline void Mem_Set_WORD(void *dest, unsigned short data, int count)
{
	//�ú���һ�����16λ�ֽ��ڴ�

	_asm
	{
		mov edi, dest; //EDIָ��ָ��Ŀ���ڴ��ַ 
		mov ecx, count; //���ƶ���������ECX 
		mov ax, data; //��16λ���ݷ���AX
		rep stosw; //repָ�����ظ���������,ֱ��ECXΪ0��ÿִ��һ��ECX-1��STOS�ǽ�EAXֵ������ES:ediָ��ĵ�ַ; ���������direction flag, ��ôedi���ڸ�ָ��ִ�к��С, ���û������direction flag, ��ôedi��ֵ������.
	}

}

///////////////////////////////////////////////////////////

inline void Mem_Set_QUAD(void *dest, unsigned int data, int count)
{
	// �ú���һ�����32λ�ֽ��ڴ�


	_asm
	{
		mov edi, dest;
		mov ecx, count;
		mov eax, data;
		rep stosd;
	}

}