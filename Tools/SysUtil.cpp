#include <Windows.h>
#include <TlHelp32.h>




int close_other_instance(const char * exename)
{
	PROCESSENTRY32  pe32 = { 0 };
	int instance_num = 0;

	// ½ø³Ì¿ìÕÕ
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe32.dwSize = sizeof(PROCESSENTRY32);
	if (::Process32First(hProcessSnap, &pe32))
	{
		do
		{
			if (stricmp(pe32.szExeFile, exename) == 0)
			{
				if (pe32.th32ProcessID != GetCurrentProcessId())
				{
					HANDLE                    hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
					if (hProcess != NULL)
					{
						TerminateProcess(hProcess, 0);
					}
				}
			}
		} while (::Process32Next(hProcessSnap, &pe32));
	}

	return instance_num;
}