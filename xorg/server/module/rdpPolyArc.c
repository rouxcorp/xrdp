/*
Copyright 2005-2013 Jay Sorg

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "rdp.h"
#include "rdpDraw.h"

#define LOG_LEVEL 1
#define LLOGLN(_level, _args) \
    do { if (_level < LOG_LEVEL) { ErrorF _args ; ErrorF("\n"); } } while (0)

/******************************************************************************/
void
rdpPolyArcOrg(DrawablePtr pDrawable, GCPtr pGC, int narcs, xArc *parcs)
{
    rdpGCPtr priv;
    GCFuncs *oldFuncs;

    GC_OP_PROLOGUE(pGC);
    pGC->ops->PolyArc(pDrawable, pGC, narcs, parcs);
    GC_OP_EPILOGUE(pGC);
}

/******************************************************************************/
void
rdpPolyArc(DrawablePtr pDrawable, GCPtr pGC, int narcs, xArc *parcs)
{
    LLOGLN(10, ("rdpPolyArc:"));
    /* do original call */
    rdpPolyArcOrg(pDrawable, pGC, narcs, parcs);
}