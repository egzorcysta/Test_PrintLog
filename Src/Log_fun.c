#include "Log.h"

void Log(u32 num, u32 file, u32 line, ...) {
	va_list ap;
	s32* pBuffer;
	u8   count = 0;

	if (num > Log_Attr_Num) {
		return;
	}

	va_start(ap, line);

	pBuffer = g_LogBuffer[g_LogIndex++];

	if (g_LogIndex == Log_Max_Num) {
		g_LogOverturn_Flag = True;
		g_LogIndex = 0;
	}

	pBuffer[count++] = file;
	pBuffer[count++] = line;

	while (num--) {
		pBuffer[count++] = va_arg(ap, u32);
	}
	va_end(ap);
	return;
}
