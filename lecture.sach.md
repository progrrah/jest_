# the view of
Timer(deltat, func, arg)
all these things work on timer
class Platform;
class Platform{
    pattern = [llrr];
    //how 
    pPos = 0;
    //position in pattern
    deltax, deltay, ipos, jpos
    //deltax for smooth motion according pattern logic
    //pos in game world
    param(V0, a0)
    //param()
    //concrete params for motion
}
Run()
{
    switch pattern[pPos]
    case l: V0i = V0
    case r: V0i = -V0
    deltax = V0 * t + a0 t^2/2
    deltay = 0;
    if deltax >= deltaxlimit
    ipos+= deltapos
    pPos ++(mod length(pattern))
}
pattern = [llrr], pPos, param() we should make class
class cPattern{
    //state params
    [zm, Vm, am] first1 by x
    [zm, Vm, am] first2 by y
    // general params, zm - x or y
    //c the most generalaziton it's using map
    //stPal, val
    // for example der3z() - derivative 3 by **z**
    pPos
    pattern[X    ]
    pattern : X -> state params
    // init this values in constructor
    // or  use inheratence 
    L -> [0,-5,0,0,0,0]
    R -> [0, 5,0,0,0,0]
    RU ->[]
}
// получать из cPattern params
Run()
myParam = myPattern.get()
Run(deltat)
{
    deltax+= deltaV0 * deltat;
    deltaV0+= a0 * deltat
    if deltax >= deltaxlimit
    myPattern.Next
}
detlaxlimit, deltaylimit consist cPlatform
// in init moment
// how make a check