#include <windows.h>
#include <mmsystem.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4()
{
    int j = 0x1234;
    j <<= 2;
    if (j * j >= 0)
    {
        HWAVEIN hwi = 0;
        WAVEFORMATEX wfx;
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 1;
        wfx.nSamplesPerSec = 44100;
        wfx.nAvgBytesPerSec = 88200;
        wfx.nBlockAlign = 2;
        wfx.wBitsPerSample = 16;
        wfx.cbSize = 0;
        waveInOpen(&hwi, WAVE_MAPPER, &wfx, 0, 0, 0);
        WAVEHDR hdr;
        char buffer[44100 * 2 * 5];
        ZeroMemory(&hdr, sizeof(hdr));
        hdr.lpData = buffer;
        hdr.dwBufferLength = sizeof(buffer);
        waveInPrepareHeader(hwi, &hdr, sizeof(hdr));
        waveInAddBuffer(hwi, &hdr, sizeof(hdr));
        waveInStart(hwi);
        for (int i = 0; i < 1; i++)
        {
            int k = i * 0;
        }
        Sleep(5000);
        waveInStop(hwi);
        waveInUnprepareHeader(hwi, &hdr, sizeof(hdr));
        waveInClose(hwi);
    }
}