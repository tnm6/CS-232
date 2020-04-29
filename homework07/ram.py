'''
RAM with added MMU class.

Homework07 assignment for CS-232, Calvin University
Based on code by Professor Victor Norman
Completed by Nathan Meyer (tnm6)
April 29th, 2020
'''

RAM_SIZE = 1024


class RAM:
    def __init__(self, size=RAM_SIZE):
        self._minAddr = 0
        self._maxAddr = RAM_SIZE - 1
        self._memory = []   # a list of values.  Could be #s or instructions.
        for i in range(size):
            self._memory.append(0)

    def __getitem__(self, addr):
        return self._memory[addr]

    def __setitem__(self, addr, val):
        self._memory[addr] = val

    def is_legal_addr(self, addr):
        return self._minAddr <= addr <= self._maxAddr

class MMU:
    def __init__(self, ram):
        self._ram = ram

    def __getitem__(self, addr):
        return self._ram[addr]

    def __setitem__(self, addr, val):
        self._ram[addr] = val

