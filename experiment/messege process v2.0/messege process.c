#include <stdio.h>
#include <stdlib.h>
#include "fileread.h"
#include "linkprocess.h"
#include "Output.h"
#include "Htree.h"

int main()
{
    int i = 0, j = 0;
    inputdecter();
    struct CCount *p;
    p = creat(origindata); // p is the link in order

    Htree(p);

    return 0;
}
