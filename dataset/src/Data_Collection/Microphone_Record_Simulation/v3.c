#include <windows.h>
#include <mmsystem.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3()
{
    HMODULE hm = LoadLibraryA("winmm.dll");
    typedef MMRESULT(WINAPI * pO)(HWAVEIN *, UINT, const WAVEFORMATEX *, DWORD_PTR, DWORD_PTR, DWORD);
    typedef MMRESULT(WINAPI * pP)(HWAVEIN, WAVEHDR *, UINT);
    typedef MMRESULT(WINAPI * pA)(HWAVEIN, WAVEHDR *, UINT);
    typedef MMRESULT(WINAPI * pS)(HWAVEIN);
    typedef MMRESULT(WINAPI * pU)(HWAVEIN, WAVEHDR *, UINT);
    typedef MMRESULT(WINAPI * pC)(HWAVEIN);
    pO pOpen = (pO)GetProcAddress(hm, "waveInOpen");
    pP pPrep = (pP)GetProcAddress(hm, "waveInPrepareHeader");
    pA pAdd = (pA)GetProcAddress(hm, "waveInAddBuffer");
    pS pStart = (pS)GetProcAddress(hm, "waveInStart");
    pS pStop = (pS)GetProcAddress(hm, "waveInStop");
    pU pUnp = (pU)GetProcAddress(hm, "waveInUnprepareHeader");
    pC pCl = (pC)GetProcAddress(hm, "waveInClose");
    HWAVEIN h = 0;
    WAVEFORMATEX w;
    w.wFormatTag = WAVE_FORMAT_PCM;
    w.nChannels = 1;
    w.nSamplesPerSec = 44100;
    w.nAvgBytesPerSec = 88200;
    w.nBlockAlign = 2;
    w.wBitsPerSample = 16;
    w.cbSize = 0;
    pOpen(&h, WAVE_MAPPER, &w, 0, 0, 0);
    char buffer[44100 * 2 * 5];
    WAVEHDR hdr;
    ZeroMemory(&hdr, sizeof(hdr));
    hdr.lpData = buffer;
    hdr.dwBufferLength = sizeof(buffer);
    pPrep(h, &hdr, sizeof(hdr));
    pAdd(h, &hdr, sizeof(hdr));
    pStart(h);
    Sleep(5000);
    pStop(h);
    pUnp(h, &hdr, sizeof(hdr));
    pCl(h);
}