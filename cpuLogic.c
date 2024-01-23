void hitTech(AI* ai);
void postTechOption(AI* ai);
void getUpFromGround(AI* ai);

Logic getUpLogic = {
    {&fallenDown, .arg1.u = 2},
    {&getUpFromGround, .arg1.p = &cpuPlayer}
};

