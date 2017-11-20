#ifdef TESTUNIT_H
#define TESTUNIT_H

#include "BufferManager.h"
#include "Constante.h"
#include "DefStruct.h"
#include "GlobalManager.h"
#include "HeapFile.h"
#include "Record.h"
#include "split.h"
#include "PageId.h"

void testRecord();
void testsplit();
void testDbDef();
void testRelDef();
void testRelSchema();

#endif