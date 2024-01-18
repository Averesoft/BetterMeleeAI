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

static Logic respawnLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_RebirthWait},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_shortHop}
};

static void loadDefaultLogic() {
    addLogic(&cpuPlayer, &respawnLogic);

}


void _main() {
    if (!init_run) { init(); }

    if (needLogic(&cpuPlayer)) { loadDefaultLogic(); }

    updateAI(&cpuPlayer);
}