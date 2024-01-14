#include <mml/system.h>
#include <mml/gctypes.h>

#include <mml/ai.h>


static char heap[2000];
static bool init_run = false;

static AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | YOSHI);


static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}