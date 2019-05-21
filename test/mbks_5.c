#include <fltKernel.h>
#include <dontuse.h>
#include <suppress.h>
#include <ntstrsafe.h>
#include <ntifs.h>

typedef int NTSTATUS;
typedef int PFLT_FILTER;

typedef int FLT_OPERATION_REGISTRATION;
typedef int FLT_REGISTRATION;
// typedef int
// typedef int
// typedef int

PFLT_FILTER FilterHandle = NULL;

char objects[256][256];
int AccessMatrix[256][256] = { 0 };

int my_strcmp(char* a, char* b)
{
	int i = 0;
	while (a[i] == b[i])
		if (a[i] == '\0' || b[i] == '\0')
			return 0;
		else
			i++;
	return 1;
}

char* my_strcpy(char* dest, const char* src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}

int search(char* object)
{
	for (int i = 0; i < 256; i++)
		if (!my_strcmp(object, objects[i]))
			return i;
	return -1;
}

const FLT_OPERATION_REGISTRATION Callbacks[] =
{
	{IRP_MJ_READ, 0, MiniPreRead, NULL},
	{IRP_MJ_WRITE, 0, MiniPreWrite, NULL},
	{IRP_MJ_OPERATION_END}
};

const FLT_REGISTRATION FilterRegistration =
{
	sizeof(FLT_REGISTRATION),
	FLT_REGISTRATION_VERSION,
	0,
	NULL,
	Callbacks,
	FilterUnload,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

typedef NTSTATUS FLT_FILTER_UNLOAD_FLAGS;
NTSTATUS FilterUnload(FLT_FILTER_UNLOAD_FLAGS flags)
{
	KdPrint(("Driver unload\n"));
	FltUnregisterFilter(FilterHandle);

	return STATUS_SUCCESS;
}
typedef NTSTATUS FLT_PREOP_CALLBACK_STATUS;
typedef NTSTATUS PFLT_CALLBACK_DATA;
typedef NTSTATUS PCFLT_RELATED_OBJECTS;
typedef NTSTATUS PVOID;
typedef NTSTATUS PFLT_FILE_NAME_INFORMATION;
typedef NTSTATUS ANSI_STRING;
typedef char CHAR;

FLT_PREOP_CALLBACK_STATUS MiniPreRead(PFLT_CALLBACK_DATA Data, PCFLT_RELATED_OBJECTS FltObjects, PVOID* CompleteContext)
{
	PFLT_FILE_NAME_INFORMATION fileNameInfo;
	NTSTATUS status;
	ANSI_STRING ansiFileName[260] = { 0 };
	CHAR FileName[256] = { 0 };

	status = FltGetFileNameInformation(Data, FLT_FILE_NAME_NORMALIZED | FLT_FILE_NAME_QUERY_DEFAULT, &fileNameInfo);

	if (NT_SUCCESS(status))
	{
		status = FltParseFileNameInformation(fileNameInfo);

		if (NT_SUCCESS(status))
		{
			if (fileNameInfo->Name.MaximumLength < 260)
			{
				RtlUnicodeStringToAnsiString(ansiFileName, &(fileNameInfo->Name), TRUE);
				RtlCopyMemory(FileName, ansiFileName->Buffer, ansiFileName->Length);

				// RtlCopyMemory(FileName, fileNameInfo->Name.Buffer, fileNameInfo->Name.MaximumLength);
//
				//PEPROCESS objCurProcess = IoThreadToProcess(Data->Thread);
				//HANDLE curProcessID = PsGetProcessId(objCurProcess);
				char* ProcessName = PsGetProcessImageFileName(objCurProcess);
				ProcessName[6] = '\0';

				int subject = search(ProcessName);
				int object = search(FileName);

				KdPrint(("%s -> %s\n", ProcessName, FileName));
				KdPrint(("%d -> %d\n", subject, object));

				if ((subject >= 0 && object >= 0) && (AccessMatrix[subject][object] == 0 || AccessMatrix[subject][object] == 2))
				{
					KdPrint(("Access deny\n"));
					Data->IoStatus.Status = STATUS_INVALID_PARAMETER;
					Data->IoStatus.Information = 0;
					FltReleaseFileNameInformation(fileNameInfo);

					return FLT_PREOP_COMPLETE;
				}
			}

		}
		FltReleaseFileNameInformation(fileNameInfo);
	};

	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

FLT_PREOP_CALLBACK_STATUS MiniPreWrite(PFLT_CALLBACK_DATA Data, PCFLT_RELATED_OBJECTS FltObjects, PVOID* CompleteContext)
{
	PFLT_FILE_NAME_INFORMATION fileNameInfo;
	NTSTATUS status;
	ANSI_STRING ansiFileName[260] = { 0 };
	CHAR FileName[256] = { 0 };

	status = FltGetFileNameInformation(Data, FLT_FILE_NAME_NORMALIZED | FLT_FILE_NAME_QUERY_DEFAULT, &fileNameInfo);

	if (NT_SUCCESS(status))
	{
		status = FltParseFileNameInformation(fileNameInfo);

		if (NT_SUCCESS(status))
		{
			if (fileNameInfo->Name.MaximumLength < 260)
			{
				RtlUnicodeStringToAnsiString(ansiFileName, &(fileNameInfo->Name), TRUE);
				RtlCopyMemory(FileName, ansiFileName->Buffer, ansiFileName->Length);

				//PEPROCESS objCurProcess = IoThreadToProcess(Data->Thread);
				//HANDLE curProcessID = PsGetProcessId(objCurProcess);
				char* ProcessName = PsGetProcessImageFileName(objCurProcess);
				ProcessName[6] = '\0';

				int subject = search(ProcessName);
				int object = search(FileName);

				KdPrint(("%s -> %s\n", ProcessName, FileName));
				KdPrint(("%d -> %d\n", subject, object));

				if ((subject >= 0 && object >= 0) && (AccessMatrix[subject][object] == 0 || AccessMatrix[subject][object] == 1))
				{
					KdPrint(("Access deny\n"));
					Data->IoStatus.Status = STATUS_INVALID_PARAMETER;
					Data->IoStatus.Information = 0;
					FltReleaseFileNameInformation(fileNameInfo);

					return FLT_PREOP_COMPLETE;
				}
			}

		}
		FltReleaseFileNameInformation(fileNameInfo);
	};

	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

NTSTATUS DriverEntry(int DriverObject, char RegistryPath)
{
	NTSTATUS status;

	status = Init();
	if (!NT_SUCCESS(status))
	{
		return status;
	}

	status = FltRegisterFilter(DriverObject, &FilterRegistration, &FilterHandle);
	if (NT_SUCCESS(status))
	{
		status = FltStartFiltering(FilterHandle);
		if (!NT_SUCCESS(status))
		{
			FltUnregisterFilter(FilterHandle);
		}
	}
	return status;
}
typedef char HANDLE,IO_STATUS_BLOCK,ULONG;
NTSTATUS Init()
{
	// ��������� ��� ���� � ����� https://support.microsoft.com/en-gb/help/891805/how-to-open-a-file-from-a-kernel-mode-device-driver-and-how-to-read-fr
	
	// ���� ���� (handle)

	//UNICODE_STRING     uniName;
	//OBJECT_ATTRIBUTES  objAttr;

	RtlInitUnicodeString(&uniName, "\\DosDevices\\C:\\config.txt");
	InitializeObjectAttributes(&objAttr, &uniName,
		OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
		NULL, NULL);

	HANDLE   handle;
	NTSTATUS ntstatus;
	IO_STATUS_BLOCK    ioStatusBlock;

	// ��������� ����

	if (KeGetCurrentIrql() != PASSIVE_LEVEL)
		return STATUS_INVALID_DEVICE_STATE;

	ntstatus = ZwCreateFile(&handle,
		GENERIC_READ,
		&objAttr, &ioStatusBlock,
		NULL,
		FILE_ATTRIBUTE_NORMAL,
		0,
		FILE_OPEN,
		FILE_NON_DIRECTORY_FILE,
		NULL, 0);

	if (!NT_SUCCESS(ntstatus))
		return ntstatus;

	// ������ ���������� � �����

	// FILE_END_OF_FILE_INFORMATION eofInfo = { 0 };

	RtlZeroMemory(&ioStatusBlock, sizeof(ioStatusBlock));
	ntstatus = ZwQueryInformationFile(handle, &ioStatusBlock, &eofInfo, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation);
	if (!NT_SUCCESS(ntstatus))
	{
		ZwClose(handle);
		return ntstatus;
	}

	ULONG FileLength = eofInfo.EndOfFile.LowPart;
	DbgPrint("len: %d", FileLength);

	// ������ � ����� ���� ����

	CHAR* buffer;
	buffer = (CHAR*)ExAllocatePool(NonPagedPool, FileLength);

	int byteOffset = { 0,0 };

	RtlZeroMemory(&byteOffset, sizeof(byteOffset));
	RtlZeroMemory(&ioStatusBlock, sizeof(ioStatusBlock));
	ntstatus = ZwReadFile(handle, NULL, NULL, NULL, &ioStatusBlock, buffer, FileLength, &byteOffset, NULL);
	if (!NT_SUCCESS(ntstatus))
	{
		ZwClose(handle);
		return ntstatus;
	}
	
	FileLength = ioStatusBlock.Information;
	DbgPrint("len: %d", FileLength);

	// ������ ������

	int objects_count = 0;

	for (int i = 0; i < FileLength; i++)
	{
		char token[256];

		if (buffer[i] == '\n' || buffer[i] == '\r')
			continue;

		for (int j = 0; j < 256; j++)
		{
			if (buffer[i] == '0')
			{
				token[j] = '\0';
				break;
			}
			token[j] = buffer[i++];
		}

		KdPrint(("[%s]\n", token));

		if (!my_strcmp(token, "subject") || !my_strcmp(token, "object"))
		{
			i++; // (
			for (int j = 0; j < 256; j++)
			{
				if (buffer[i] == ')')
				{
					token[j] = '\0';
					break;
				}
				token[j] = buffer[i++];
			}

			my_strcpy(objects[objects_count++], token);

			while (buffer[i] != '\n')
				i++;
		}
		else if (!my_strcmp(token, "right"))
		{
			KdPrint(("New rule\n"));

			i++; // (

			for (int j = 0; j < 256; j++)
			{
				if (buffer[i] == ',')
				{
					token[j] = '\0';
					break;
				}
				token[j] = buffer[i++];
			}

			int subject = search(token);
			i++;

			for (int j = 0; j < 256; j++)
			{
				if (buffer[i] == ',')
				{
					token[j] = '\0';
					break;
				}
				token[j] = buffer[i++];
			}

			int object = search(token);
			i++;

			KdPrint(("%d -> %d\n", subject, object));

			if (object >= 0 && subject >= 0)
			{
				if (buffer[i] == 'r')
					AccessMatrix[subject][object] += 1;
				else if (buffer[i] == 'w')
					AccessMatrix[subject][object] += 2;
			}

			while (i <= FileLength && buffer[i] != '\n')
				i++;
		}
	}

	ZwClose(handle);

	for (int i = 0; i < objects_count; i++)
	{
		for (int j = 0; j < objects_count; j++)
			KdPrint(("%d ", AccessMatrix[i][j]));
		KdPrint(("\n"));
	}

	return ntstatus;
}