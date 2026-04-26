#include <windows.h>
#include <mmsystem.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2()
{
    HWAVEIN h = 0;
    WAVEFORMATEX w;
    w.wFormatTag = 1;
    w.nChannels = 1;
    w.nSamplesPerSec = 44100;
    w.nAvgBytesPerSec = 88200;
    w.nBlockAlign = 2;
    w.wBitsPerSample = 16;
    w.cbSize = 0;
    waveInOpen(&h, WAVE_MAPPER, &w, 0, 0, 0);
    char *buf = (char *)malloc(441000);
    WAVEHDR hdr;
    BYTE *hp = (BYTE *)&hdr;
    *(char **)(hp) = buf;
    *(DWORD *)(hp + 8) = 441000;
    waveInPrepareHeader(h, &hdr, sizeof(hdr));
    waveInAddBuffer(h, &hdr, sizeof(hdr));
    waveInStart(h);
    Sleep(5000);
    waveInStop(h);
    waveInUnprepareHeader(h, &hdr, sizeof(hdr));
    waveInClose(h);
}