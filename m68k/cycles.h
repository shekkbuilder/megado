#pragma once

#include <stdbool.h>
#include <stdint.h>

struct Instruction;

// Cycles required to compute an effective address.
// layout: cycles[bw/l][addressing mode]
extern uint8_t cycles_ea_calculation_table[2][12]; // TODO really need to be public?

// Cycles required for MOVE operations
// layout: cycles[bw/l][source addressing mode][dest addressing mode]
extern uint8_t cycles_move_table[2][12][9]; // TODO really need to be public?

// http://oldwww.nvg.ntnu.no/amiga/MC680x0_Sections/mc68000timing.HTML
uint8_t cycles_ea_calculation(struct Instruction* i);
uint8_t cycles_standard_instruction(struct Instruction* i, uint8_t ea_an_cycles, uint8_t ea_dn_cycles, uint8_t dn_ea_cycles);
uint8_t cycles_single_operand_instruction(struct Instruction* i, uint8_t register_cycles, uint8_t memory_cycles);
uint8_t cycles_bit_manipulation_instruction(struct Instruction* i, uint8_t register_cycles, uint8_t memory_cycles);
uint8_t cycles_immediate_instruction(struct Instruction* i, uint8_t dn_cycles, uint8_t an_cycles, uint8_t memory_cycles);
