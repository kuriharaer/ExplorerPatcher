#ifndef _H_UPDATES_H_
#define _H_UPDATES_H_
#include <Windows.h>
#include <stdio.h>
#include <Wininet.h>
#pragma comment(lib, "Wininet.lib")
#include <shlobj_core.h>
#include "utility.h"

extern HMODULE hModule;

#define UPDATES_VERBOSE_OUTPUT

#define UPDATE_POLICY_AUTO 0
#define UPDATE_POLICY_NOTIFY 1
#define UPDATE_POLICY_MANUAL 2
#define UPDATE_POLICY_DEFAULT UPDATE_POLICY_NOTIFY

#define UPDATES_OP_DEFAULT 0
#define UPDATES_OP_CHECK 1
#define UPDATES_OP_INSTALL 2

#define UPDATES_USER_AGENT "ExplorerPatcher"
#define UPDATES_FORM_HEADERS "Content-Type: text/plain;\r\n"
#define UPDATES_HASH_SIZE 32
#define UPDATES_BUFSIZ 10240
#define UPDATES_DEFAULT_TIMEOUT 600

typedef struct IsUpdateAvailableParameters
{
	HINTERNET hInternet;
	HANDLE hEvent;
};

BOOL IsUpdatePolicy(LPCWSTR wszDataStore, DWORD dwUpdatePolicy);
BOOL IsUpdateAvailable(LPCWSTR wszDataStore, char* szCheckAgainst);
BOOL UpdateProduct(LPCWSTR wszDataStore);
BOOL InstallUpdatesIfAvailable(DWORD dwOperation, DWORD bAllocConsole, DWORD dwUpdatePolicy);
#endif