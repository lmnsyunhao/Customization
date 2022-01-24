#include <windows.h>
#include <stdio.h>
#include <string.h>

#define MAXTIME 5
#define BUFSIZE 64

int main(){
	STARTUPINFO siFrpc = {0}, siVSCode = {0};
	PROCESS_INFORMATION  piFrpc = {0}, piVSCode = {0};
	BOOL resFrpc = CreateProcess(
		TEXT("D:\\Frp\\frpc.exe"),
		TEXT("D:\\Frp\\frpc.exe -c D:\\Frp\\frpc.ini"),
		NULL, NULL, FALSE, NULL, NULL, NULL, &siFrpc, &piFrpc
	);
	printf("Frpc Process %s.\n", resFrpc ? "started" : "failed");
	if (!resFrpc) ::MessageBox(NULL, TEXT("Frpc Process failed."), TEXT("Information"), MB_OK);
	BOOL resVSCode = CreateProcess(
		TEXT("D:\\VSCode\\Code.exe"),
		NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &siVSCode, &piVSCode
	);
	printf("Microsoft VS Code Process %s.\n", resVSCode ? "started" : "failed");
	if (resVSCode) WaitForSingleObject(piVSCode.hProcess, INFINITE);
	else ::MessageBox(NULL, TEXT("Microsoft VS Code Process failed."), TEXT("Information"), MB_OK);
	if (resVSCode && resFrpc) {
		printf("Terminate Frpc Process.\n");
		char msg[BUFSIZE];
		for (int i = 0; i < MAXTIME; ++i) {
			if (TerminateProcess(piFrpc.hProcess, 0))
				break;
			memset(msg, 0, sizeof(char)*BUFSIZE);
			sprintf(msg, "Frpc Process exits failed.\nTry closing again. (%d/%d).", i+1, MAXTIME);
			printf("Frpc Process exits failed. (%d/%d).\n", i+1, MAXTIME);
			::MessageBox(NULL, TEXT(msg), TEXT("Information"), MB_OK);
		}
	}
	return 0;
}