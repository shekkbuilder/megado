#pragma once

#include "m68k.h"
#include "operands.h"

#define DEFINE_INSTR(NAME) Instruction* gen_ ## NAME (uint16_t opcode, M68k* context)

DEFINE_INSTR(bchg);
DEFINE_INSTR(bclr);
DEFINE_INSTR(bset);
DEFINE_INSTR(btst);