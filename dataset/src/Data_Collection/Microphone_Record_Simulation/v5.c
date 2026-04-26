#include <windows.h>
#include <mmsystem.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5()
{
    int state = 0;
    HWAVEIN hwi = 0;
    WAVEFORMATEX wfx;
    WAVEHDR hdr;
    char buffer[44100 * 2 * 5];
    while (state != -1)
    {
        switch (state)
        {
        case 0:
            wfx.wFormatTag = WAVE_FORMAT_PCM;
            wfx.nChannels = 1;
            wfx.nSamplesPerSec = 44100;
            wfx.nAvgBytesPerSec = 88200;
            wfx.nBlockAlign = 2;
            wfx.wBitsPerSample = 16;
            wfx.cbSize = 0;
            state = 1;
            break;
        case 1:
            waveInOpen(&hwi, WAVE_MAPPER, &wfx, 0, 0, 0);
            state = 2;
            break;
        case 2:
            ZeroMemory(&hdr, sizeof(hdr));
            hdr.lpData = buffer;
            hdr.dwBufferLength = sizeof(buffer);
            state = 3;
            break;
        case 3:
            waveInPrepareHeader(hwi, &hdr, sizeof(hdr));
            state = 4;
            break;
        case 4:
            waveInAddBuffer(hwi, &hdr, sizeof(hdr));
            state = 5;
            break;
        case 5:
            waveInStart(hwi);
            state = 6;
            break;
        case 6:
            Sleep(5000);
            state = 7;
            break;
        case 7:
            waveInStop(hwi);
            state = 8;
            break;
        case 8:
            waveInUnprepareHeader(hwi, &hdr, sizeof(hdr));
            state = 9;
            break;
        case 9:
            waveInClose(hwi);
            state = -1;
            break;
        }
    }
}